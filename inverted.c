#include "inverted.h"

/* Function definitions */
int validate_files(char *filename, F_node **head)
{
    FILE *fptr;
    
    char *dot = strstr(filename, ".txt");        // Check if file extension is ".txt"
    if (dot==NULL || strcmp(dot, ".txt") != 0){    //valid text files, if not valid skip this current file next validations
        printf(BRED "ERROR: %s is not a .txt file\n" RESET, filename);
        return FAILURE;    
    }

    fptr = fopen(filename,"r");   //opening file in read mode
    if (fptr==NULL){              // File not present / cannot open
        printf(BRED "ERROR: File %s not Available\n" RESET,filename);
        return FAILURE;
    }

    fseek(fptr, 0, SEEK_END);   //checking is file is empty or not by Moving file pointer to end to check size
    if(ftell(fptr) == 0){
        printf(BRED "ERROR: File %s is empty\n" RESET, filename);
        return FAILURE;
    }

    return SUCCESS;    // File is valid
}


int insert_last(F_node **head, char *f_name)
{
    F_node * newnode = malloc(sizeof(F_node));   // Allocate memory for new file node
    if (newnode == NULL)
        return FAILURE;
        
    strcpy(newnode -> f_name, f_name);   // Copy file name into node
    newnode->link = NULL;
    
    if (*head == NULL)       //empty list case
        *head = newnode;
    else{
        F_node *temp = *head;   //head is double pointer: To get actual first node: *head
        while(temp->link != NULL){    // Traverse till last node
            temp = temp -> link;
        }
        temp->link= newnode;   // Attach new node at end
    }
    return SUCCESS;
}


int check_duplicates(F_node *head, char *f_name)
{
    F_node *temp = head;
    while(temp->link != NULL){     // Traverse entire file list
        if (strcmp(temp->f_name, f_name) == 0)    //if matched - duplicate is there
            return FAILURE;    
        else temp = temp->link;      // move the temp to next node to check
    }
    return SUCCESS;    // No duplicate found
}

int get_index(char *word)
{
    if(isalpha(word[0]))     // If first character is alphabet
        return tolower(word[0])-'a';    // map a-z -> 0-25
    else   return 26;        // special characters
}
