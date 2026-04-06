#include "inverted.h"

void create_database(M_node *HT[], F_node *head)
{
    F_node *temp = head;     // start from first file
    char word[50];          // to store each word from file

    while(temp != NULL)    //Traverse thorugh linked list of valid input files
    {
        FILE *fptr = fopen(temp->f_name, "r");
        if (fptr==NULL){
            printf(BRED "Unable to open the file %s" RESET, temp->f_name);
            return;
        }

        printf("INFO: %s is Processing...\n", temp->f_name);
        int index;
        while (fscanf(fptr, "%s", word) != EOF)    // Read word by word from file
        {
            index = get_index(word);      // get hash index based on first char
            
             // CASE 1: NO MAIN NODE EXISTS 
            if (HT[index] == NULL){         //Index has no Address means no mainnode- no words stored previously
                M_node *mainnode = malloc(sizeof(M_node));   // Create main node
                S_node *subnode = malloc(sizeof(S_node));   // Create sub node

                strcpy(mainnode->word, word);    // Fill main node
                mainnode->file_count = 1;
                mainnode->main_link = NULL;

                strcpy(subnode->filename, temp->f_name);   // Fill sub node
                subnode->word_count = 1;
                subnode->sub_link = NULL;

                mainnode->sub_link = subnode;

                HT[index] = mainnode;    // Insert into hash table
            }
            else{                  //CASE 2: MAIN NODE EXISTS  - Address is there - main node is present in index
                M_node *Mtemp = HT[index];
                while (Mtemp != NULL)
                {      //traverse through the main node, to check the nodes for current word is created or not
                    if (strcmp(Mtemp->word, word) == 0)    //if word matched, traverse through the subnodes of that main node by comparing the filenames
                    {
                        S_node *Stemp = Mtemp->sub_link;
                        while(Stemp != NULL){            //Travesring through all subnodes to find the filename 
                            if(strcmp(Stemp->filename, temp->f_name) == 0){
                                Stemp->word_count++;
                                break;
                            }
                            Stemp = Stemp->sub_link;  // moving to next subnode in current main node
                        }

                        if (Stemp == NULL){     //means we checked the all subnodes, but the current filename is not matched with all this, so creating new subnode for this file
                            S_node *newsubnode = malloc(sizeof(S_node));

                            strcpy(newsubnode->filename, temp->f_name);
                            newsubnode->word_count = 1;
                            newsubnode->sub_link = Mtemp->sub_link;   

                            Mtemp->sub_link = newsubnode;   //insert first logic
                            Mtemp->file_count++;     // increase file count
                        }
                        break;
                    }
                    Mtemp = Mtemp->main_link;   //moving to next main node
                }

                // CASE 3: WORD NOT FOUND  - means we checked the current words with all main nodes, but the current word is not matched
                // so creating new mainnode for this word
                if (Mtemp == NULL)   
                {
                    M_node *mainnode = malloc(sizeof(M_node));
                    S_node *subnode = malloc(sizeof(S_node));

                    strcpy(mainnode->word, word);
                    mainnode->file_count = 1;
                    mainnode->main_link = NULL;

                    strcpy(subnode->filename, temp->f_name);
                    subnode->word_count = 1;
                    subnode->sub_link = NULL;

                    mainnode->sub_link = subnode;   
                    mainnode->main_link = HT[index];   //insert first logic
                    HT[index] = mainnode;               
                }
            }
        }
        fclose(fptr);    //close current file and go to next file

        temp = temp->link;  //moving to next file
    }
}
