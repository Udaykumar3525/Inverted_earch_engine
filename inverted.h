#ifndef INVERTED_H
#define INVERTED_H

// Standard libraries
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

// Color macros
#define BRED     "\033[1;31m"
#define BGREEN   "\033[1;32m"
#define BYELLOW  "\033[1;33m"
#define BBLUE    "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN    "\033[1;36m"
#define BWHITE   "\033[1;37m"
#define RESET   "\033[0m"

// Return values for functions
#define SUCCESS		1
#define FAILURE		0

//File linked list - Stores the input valid files
typedef struct file
{
    char f_name[20];     //file name ex: File1.txt
    struct file *link;  //pointer to next file
}F_node;

//Subnode - Stores the file details for a word
typedef struct Sub
{
    int word_count;          //how many times word appear in this file
    char filename[20];      //File name
    struct Sub *sub_link;   //Pointer to next sub node
}S_node;

//Main node - Stores the word and its file list
typedef struct Main
{
    char word[25];        //Actual word ex:Uday
    int file_count;      //in how many files that word present
    S_node *sub_link;        //pointer to subnode(file details)
    struct Main *main_link;  //Pointer to nxt word of same index
}M_node;


// Return values for functions - prototypes
void create_database(M_node *HT[], F_node *head);
void display_database(M_node *HT[]);
void search_database(M_node *HT[]);
void save_database(M_node *HT[]);
int update_database(M_node *HT[],F_node **head);

// Helper functions
int validate_files(char *filename, F_node **head);
int insert_last(F_node **head, char *f_name);
int check_duplicates(F_node *head, char *f_name);
int print_filenames(F_node *head);
int get_index(char *word);

#endif
