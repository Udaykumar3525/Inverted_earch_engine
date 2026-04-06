#include "inverted.h"

void display_database(M_node *HT[])
{
    printf("----------------------------------------------------------------------------\n");
    printf(BBLUE "%-10s %-20s %-12s %-20s %-10s\n","Index", "Word", "File_Count", "File_Name", "Word_Count" RESET);
    printf("----------------------------------------------------------------------------\n");

    for(int i = 0; i < 27; i++)
    {
        M_node *Mtemp = HT[i];

        while(Mtemp != NULL)      //Traversing Through all main nodes -  all words in that index
        {   
            S_node *Stemp = Mtemp->sub_link;

            while(Stemp != NULL)    //Traversing Through all subnodein each main node
            {
                if(Stemp == Mtemp->sub_link)
                    printf("%-10d %-20s %-12d %-20s %-10d\n",i,Mtemp->word,Mtemp->file_count,Stemp->filename,Stemp->word_count);
                else
                    printf("%-10s %-20s %-12s %-20s %-10d\n","", "", "",Stemp->filename,Stemp->word_count);

                Stemp = Stemp->sub_link;
            }
            Mtemp = Mtemp->main_link;
        }
    }
    printf("----------------------------------------------------------------------------\n");
}
