#include "inverted.h"

int main(int argc, char *argv[])
{
    F_node *head = NULL;
    M_node *HT[27];
	for(int i = 0; i < 27; i++)   //intializing Hash table with NULL (all indexes)
        HT[i] = NULL;

    // Validate_files
	if (argc>1){
		for (int i=1; i<argc; i++)
		{
			if (validate_files(argv[i], &head) == SUCCESS){
				printf(BGREEN "INFO: Validation is done for %s" RESET, argv[i]);
				if (insert_last(&head, argv[i]) && check_duplicates(head, argv[i])){
					printf(BGREEN " And also added to list\n" RESET);
				}
				else
					printf(BRED " And It is a duplicate File or its insertion Failed\n" RESET);
			}
		}
	}
	else{
		printf(BRED "INFO: No input files given.\n" RESET);
        printf(BRED "You can use 'Update Database' to load previous files data from saved file(Ex:Database.txt).\n" RESET);
	}

    int option, db_created=0;
    do
    {
		printf(BMAGENTA "\nSelect your choice among following operations:\n" RESET
			   "1. Create Database\n2. Display Database\n3. Save Database\n" 
			   "4. Search\n5. Update Database\n6. Exit\n"
			   BYELLOW "Enter your choice : " RESET);

		scanf("%d", &option);

		switch (option)
		{
			case 1:
				if (db_created == 1)    printf(BRED "ERROR: Database already created. Cannot create again.\n" RESET);
				else if (head == NULL)    printf(BRED "ERROR: No files available to create database\n" RESET);
				else{
					create_database(HT, head);
					db_created = 1;
					printf(BGREEN "INFO: Database created successfully\n" RESET);
				}
				break;

			case 2:
				if (db_created == 0)    printf(BRED "ERROR: Database is empty. Create or update first.\n" RESET);
				else    display_database(HT);
                break;

			case 3:
				if (db_created == 0)    printf(BRED "ERROR: Database is empty. Nothing to save.\n" RESET);
				else{
					save_database(HT);
					printf(BGREEN "INFO: Database saved successfully in database.txt\n" RESET);
				}
                break;

			case 4:
				if (db_created == 0)    printf(BRED "ERROR: Database is empty. Cannot search.\n" RESET);
				else    search_database(HT);
                break;

			case 5:
				if (db_created == 1)
					printf(BRED "ERROR: Update allowed only on empty database.\n" RESET);

				else{
					if (update_database(HT, &head) == SUCCESS)
						db_created = 1;
					printf(BGREEN "INFO: Database loaded successfully\n" RESET);
				}
				
				break;

			case 6:
			    printf("INFO: Exiting program\n");
			    break;

			default:
			printf(BRED "INFO : Please enter a valid option\n" RESET);
		}
    }while( option != 6 );

    return 0;
}
