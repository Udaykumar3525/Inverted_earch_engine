#include "inverted.h"

void save_database(M_node *HT[])
{
    FILE *fptr = fopen("database.txt", "w");
    
    if (fptr == NULL){
        printf("ERROR: Unable to open file for saving\n");
        return;
    }

    // Traversing all indexes
    for (int i = 0; i < 27; i++)
    {
        if (HT[i] != NULL)
        {
            M_node *temp_main = HT[i];

            // Traverse main nodes
            while (temp_main != NULL)
            {
                // Print main node details
                fprintf(fptr, "#%s;%d;", temp_main->word, temp_main->file_count);

                S_node *temp_sub = temp_main->sub_link;

                // Traverse sub nodes
                while (temp_sub != NULL)
                {
                    fprintf(fptr, "%s;%d;", temp_sub->filename, temp_sub->word_count);
                    temp_sub = temp_sub->sub_link;
                }

                fprintf(fptr, "#\n");   // end of one word entry

                temp_main = temp_main->main_link;
            }
        }
    }

    fclose(fptr);
}   

/*
Right now your database is stored in RAM (temporary memory)
If program closes: Entire database is lost, You must rebuild from files again (time consuming)
Solution: SAVE DATABASE
We store your inverted index into a file
So later: You can reload it using update_database(), No need to reprocess all input files
SAVE function: It converts your linked structure → file format
From this (memory): HT -> Main node -> Sub nodes
To this (file): #word;file_count;file1;count;file2;count#
*/