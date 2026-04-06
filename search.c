#include "inverted.h"

void search_database(M_node *HT[])
{
    char search_word[30];
    printf("Enter the word to search: ");
    scanf("%s", search_word);

    int index = get_index(search_word);

    if (HT[index] == NULL){        // No words at this index
        printf("INFO: Word '%s' not found in database\n", search_word);
        return;
    }

    M_node *temp_main = HT[index];

    while (temp_main != NULL)
    {
        if (strcmp(temp_main->word, search_word) == 0)    // Word matched
        {
            printf("INFO: Word '%s' is found in %d file(s)\n", temp_main->word, temp_main->file_count);

            S_node *temp_sub = temp_main->sub_link;
            while (temp_sub != NULL)
            {
                printf("File: %s\t& Word Count: %d\n", temp_sub->filename, temp_sub->word_count);
                temp_sub = temp_sub->sub_link;
            }
            return;
        }
        temp_main = temp_main->main_link;
    }

    printf("INFO: Word '%s' not found in database\n", search_word);
}

/*
to find whether a given word is present in your inverted database
If the word is present, it should show: 
the word
in how many files it is present
each filename
how many times it appears in that file
*/