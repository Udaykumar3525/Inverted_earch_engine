#include "inverted.h"

int update_database(M_node *HT[], F_node **head)
{ 
    FILE *fptr = fopen("database.txt", "r");
    if (fptr == NULL){
        printf("ERROR: File not found\n");
        return FAILURE;
    }

    // Step 1: Initialize
    for (int i = 0; i < 27; i++)
        HT[i] = NULL;
        
    char line[200];

    // Step 2: Read line by line
    while (fgets(line, sizeof(line), fptr))
    {
        // Remove newline
        line[strcspn(line, "\n")] = '\0';

        // Remove starting '#'
        if (line[0] == '#')
        {
            for (int i = 0; line[i] != '\0'; i++)
            {
                line[i] = line[i + 1];
            }
        }

        // Remove ending '#'
        int len = strlen(line);
        if (line[len - 1] == '#')
        {
            line[len - 1] = '\0';
        }

        // Step 3: Split using strtok
        char *token = strtok(line, ";");

        // Create main node
        M_node *new_main = malloc(sizeof(M_node));
        strcpy(new_main->word, token);

        token = strtok(NULL, ";");
        new_main->file_count = atoi(token);

        new_main->sub_link = NULL;
        new_main->main_link = NULL;

        S_node *sub_last = NULL;

        // Step 4: Create sub nodes
        while ((token = strtok(NULL, ";")) != NULL)
        {
            S_node *new_sub = malloc(sizeof(S_node));

            strcpy(new_sub->filename, token);

            token = strtok(NULL, ";");
            new_sub->word_count = atoi(token);

            new_sub->sub_link = NULL;

            // Link sub nodes
            if (new_main->sub_link == NULL)
            {
                new_main->sub_link = new_sub;
                sub_last = new_sub;
            }
            else
            {
                sub_last->sub_link = new_sub;
                sub_last = new_sub;
            }
        }

        // Step 5: Insert into hash table
        int index = get_index(new_main->word);

        if (HT[index] == NULL)
        {
            HT[index] = new_main;
        }
        else
        {
            M_node *temp = HT[index];
            while (temp->main_link != NULL)
            {
                temp = temp->main_link;
            }
            temp->main_link = new_main;
        }
    }

    fclose(fptr);
    return SUCCESS;
}

/*
Update function is required because the database stored in memory is lost when the program terminates. 
It allows reloading the previously saved database from a file into memory without reprocessing input files
Same run - No need update
After restart - Use update
New files - Use create
*/