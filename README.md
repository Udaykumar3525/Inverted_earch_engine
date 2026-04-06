# Inverted Search Engine  
```
Name: Udaykumar Upputuri  
Description: Developed an Inverted index Search system in C language  
Mail: udayupputuri3525@gmail.com  
```

# 📌 Project Overview  
The Inverted Search project is a command-line based application written in C that creates an inverted index from multiple text files.  
It maps words -> list of files -> word occurrence count, enabling fast searching similar to how search engines work.  
Instead of scanning entire files during search, the program builds a structured database using Hash Table + Linked Lists, making search
operations efficient.  

# 📖 What is Inverted Search  
```
Inverted Search (Inverted Index) is a data structure used to store:  
Word -> File(s) -> Count  
Example:  
📂 Input Files  
file1.txt → uday kumar upputuri  
file2.txt → uday done bachelors and Uday  
🔍 Word Breakdown  
file1.txt → uday, kumar, upputuri  
file2.txt → uday, done, bachelors, and, uday     

Word: uday  
→ file1.txt (1 time)  
→ file2.txt (2 times)   
File Count: 2  

Word: kumar  
→ file1.txt (1 time)  
File Count: 1  

same like for remaining words - upputuri, done, bachelors, and,  
This allows fast lookup of words across multiple files.  
```

# 💡 Why Inverted Index  
Without an inverted index:  
You must scan entire files every time you search  
Time complexity is high  

With inverted index:  
Direct access using hashing  
Faster search  
Organized data structure  

# ⚙️ Features
- Supports multiple input text files  
- Efficient search using Hash Table  
- Tracks word frequency in each file  
- Displays complete database  
- Save database to file (database.txt)  
- Reload database using update feature  
- Handles duplicate and invalid files  
- Case-insensitive indexing  

# 📂 Project Structure  
```
Inverted_Search
├── main.c
├── inverted.h
├── inverted.c
├── create.c
├── display.c
├── search.c
├── save.c
├── update.c
└── README.md
```


# 📄 File Description  
```
File	          Description
main.c	          Entry point, handles menu and user interaction
inverted.h	      Structure definitions, macros, function declarations
inverted.c	      Helper functions (validation, insertion, hashing)
create.c	      Creates inverted database from input files
display.c	      Displays entire database
search.c	      Searches for a word
save.c	          Saves database to file
update.c	      Loads database from saved file
README.md	      Project documentation
```

# 🧠 Data Structures Used  
1️⃣ File Linked List  
Stores all valid input files  
F_node: filename → next file  
2️⃣ Main Node (Word Level)  
M_node: word, file count, subnode link, next main node link  
3️⃣ Sub Node (File Level)  
S_node: filecount, word_count, next subnode link  
4️⃣ Hash Table  
Size: 27  
Index mapping: a-z → 0 to 25  and others → 26  

# Overall Project Workflow  
1️⃣ Input Files  
User provides input files via command line: ./a.out file1.txt file2.txt file3.txt  

2️⃣ File Validation  
Checks: File extension (.txt), File exists, File is not empty, Duplicate files  
Functions used: validate_files(), check_duplicates()  

3️⃣ Create Database  
Read each file word by word  
Generate index using first character  
Insert into hash table  
Cases handled:  
New word → create main node  
Existing word → update sub node  
New file for existing word → create sub node  
Function: create_database()  

4️⃣ Display Database  
Displays in structured format: Index | Word | File Count | File Name | Word Count  
Function: display_database()  

5️⃣ Search Operation  
User enters a word  
Hash index is calculated  
Traverse main node → sub nodes  
Output: Files containing word, Number of occurrences  
Function: search_database()  

6️⃣ Save Database  
Stores database into file (database.txt)  
Format:  #word;file_count;file1;count;file2;count#  
Function: save_database()  

7️⃣ Update Database  
Loads database from file and Reconstructs hash table  
Function: update_database()  

# 🔑 Hashing Logic  
if alphabet:  
    index = tolower(word[0]) - 'a'  
else:  
    index = 26  


# 🔧 Important Functions  
'''
Function	              Purpose
validate_files()	      Check file validity
insert_last()	      Insert file into list
check_duplicates()	  Avoid duplicate files
get_index()	          Generate hash index
create_database()	  Build inverted index
display_database()	  Show database
search_database()	  Search word
save_database()	      Save to file
update_database()	  Reload database
'''

# 🧠 Applications  
- Search Engines (Google, Bing)  
- Document indexing systems  
- Information retrieval systems  
- Text analysis tools  
- Digital libraries  
- Log analysis systems  

# ✅ Advantages  
- Fast searching  
- Efficient data organization  
- Reduces repeated file scanning  
- calable for large datasets  
- Demonstrates hashing + linked list concepts  

# ❌ Disadvantages  
- More memory usage  
- Initial database creation takes time  
- Complex implementation  
- Not ideal for very small datasets  
-----------------------------------------> Thank you <--------------------------------------------