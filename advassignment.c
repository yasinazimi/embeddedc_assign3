/**************************************************************************
48430 Embedded C - Advanced Assignment
Name: Yasin Azimi
Student ID: 11733490
Date of submission: 08/06/2016
A brief statement on what you could achieve (less than 50 words): High Distinction
A brief statement on what you could NOT achieve (less than 50 words): Nothing


***************************************************************************/

/**************************************************************************
List of header files and preprocessing directives
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>


/**************************************************************************
Structs
***************************************************************************/
struct node{
	char c;		/*variable c is a char to store an input character*/
	struct node *next;	/*next is a pointer to the next struct node*/
};
typedef struct node node_n;	/*typedef assigns alternative variable 'node_n' to the existing struct 'node'*/


/**************************************************************************
Function prototypes
***************************************************************************/
int main(int argc, char* argv[]);
void printmenu(void);
void printlinkedlist(node_n*head);
int delhead(node_n**head);
int delvowels(node_n**head);


/**************************************************************************
Main
***************************************************************************/
int main(int argc, char* argv[]) {
	int m, n;	/*Initialise variables: m is the indicator of words in argv and n is the indicator of the number of characters in each word within argv*/
	char option;	/*Keyword 'char' keeps track of the switch statement*/
	while (argc == 1) {		/*The name of the program is always the first argument(input argument)*/
		printf("Parse a sentence");		/*Prints out to the terminal if no words are entered after the name of the program*/
		return 1;	/*If there are no input arguments then terminate the program with status of 'return 1'(error)*/
	}
	
	node_n* head = NULL;	/*Initialises the linkedlist*/
	head = malloc(sizeof(node_n));	/*Dynamically allocates memory for the progarm*/
	if (head == NULL) {	/*Checks if there is an error dynamically allocating memory to the first element of the linked list*/
		return 1;	/*Terminate the program with status of 'return 1'(error)*/
	}
	
	node_n* curr = head;	/*The current element is used as temporary to fill the list*/
	for (m = 1; m < argc; m++) {	/*Assigns an integer value of 1 (name of the program is the [0] element so we start from 1) to the variable 'm'. A condition is passed so that it loops over all the input arguments (words within the sentence). This will then proceed to to execute the following loop and hence, continues the iterations 'n++'*/
		for (n = 0; argv[m][n] != '\0'; n++) {	/*Assigns an integer value of 0 to the variable 'n'. A condition is passed so that it loops over all the characters in the input arguments (each character within each word)*/
			curr->c = argv[m][n];	/*Adds the character to the linked list*/
			curr->next = malloc(sizeof(node_n));	/*Dynamically allocates memory for the next element*/
			if (argv[m][n+1] != '\0' || m < argc - 1)	/*Sets the current to the pointer for the next element in the linked list so that the iteration continues adding to the list instead of changing the same element. This loop checks for a null character in the input stream and if the next element happens to be a null character it sets the next element to the current*/
				curr = curr->next;
		}
	} curr->next = NULL;	/*NULL pointer is designated to the end of the list*/
	
	do {
		printmenu();	/*Prints out the menu*/
		printf("Enter your choice>");	/*Prompts user to select an option from the menu*/
		char temp[2];	/*Scanf temporary returns this*/
		int checkinput = scanf("%1[^\n]", temp);	/*Reads in only 1 character from the user input and terminates the loop when it reads a new line*/
		option = temp[0];	/*Option is set to the first character of the temporary string*/
		if (!checkinput)	/*Checks if the user entered any input*/
			option = '\0';	/*Option is set to an invalid value*/
		while (getchar() != '\n') {		/*Clears the input stream entered after the scanf*/
			option = '0'; }	/*Option is set to an invalid value*/		
		switch (option) {	/*Switch cases for the menu*/
			case '1':
					printlinkedlist(head);	/*Prints out the linked list to the console*/
					break;
			case '2':
					if (head != NULL)	/*Checks for a NULL and calls the delhead() function*/
						delhead(&head);
					else 
						printf("Pop failed.\n");	/*Prints out error while trying to remove elements from an empty list*/
					break;
			case '3':
					if (head != NULL)	/*Checks for a NULL and calls the delvowels() function*/
						delvowels(&head);
					else 
						printf("Del failed.\n");	/*Prints out error while trying to remove elements from an empty list*/
					break;
			case '4':
					exit(0);	/*Exit the program */
			default:
					printf("Invalid choice.\n");	/*Prints out error message if any other value is entered outside of the above cases*/
					break;
		}
	}
	while (option != 4);	/*Condition checking for any other cases but case '4'*/
	return 0;	/*Return success with status 0*/
}


/**************************************************************************
Menu
***************************************************************************/
void printmenu(void){
	printf("\n\n"
		"1. print input arguments (no spaces)\n"
		"2. remove first character\n"
		"3. remove vowels\n"
		"4. exit program\n");
}


/**************************************************************************
Print all nodes in a linked list of struct node type
***************************************************************************/
void printlinkedlist(node_n*head) {
	node_n* curr = head;	/*An index is initialised to keep count of the current element in the list*/
	while (curr != NULL) {	/*Execute the following lines until the end reaches NULL*/
		printf("%c", curr->c);	/*Each character in the list is printed*/
		curr = curr->next;		/*Assigns the current to the pointer for the next element*/
	}
	printf("\n");
}


/**************************************************************************
Delete the head (first node) of a linked list of type struct node
***************************************************************************/
int delhead(node_n**head) {
	node_n* new_node = NULL;	/*Declares NULL to the initialised 'new_node' which will be the temporary new head*/
	if (*head != NULL) {	/*Checks if the first element is not empty, if so an element can be removed from*/
		new_node = (*head)->next;	/*Set the new head to the next element*/
		free(*head);	/*Deallocates the node*/
		*head = new_node;	/*Set the first pointer to the temporary 'new_node' head*/
		return 1;	/*Return's status 1 in an instance where the head node could not be deleted*/
	}
	else {
		return 0;	/*Return's status 0 if the first element of the linked list is empty*/
	}
}


/**************************************************************************
Delete the vowels (a,e,i,o,u) in a sentence
***************************************************************************/
int delvowels(node_n**head) {
	int q, r;	/*Initialises variables: q is the indicator of vowels in the array, r is the indicator of how many vowels removed from the input stream*/
	char v[] = {'a','A','e','E','i','I','o','O','u','U'};	/*Initialises the array of characters for each of the vowel characters to be removed from the input*/
	for (q = 0, r = 0; q <= 10; q++) {
        node_n* temp = *head, *pre;	/*Initialising the previous head and assigning the head as temporary*/
        char key = v[q];	/*Initialises the keyword 'key' to hold the current instance of vowels to be removed*/
		while (temp != NULL && temp->c == key) {	/*Condition is passed to check if head node itself holds the key or multiple instances of key*/
            *head = temp->next;	/*Temporary head is updated*/
            free(temp);		/*Deallocates the node*/
            temp = *head;	/*Next head is updated from the temporary*/
			r++; }	/*Increment and update the count of vowels removed*/
			
        while (temp != NULL) {		/*Deletes instances other than the head*/
            while (temp != NULL && temp->c != key) {	/*Checks for 'key' which holds the current vowels to be removed*/
                pre = temp;	/*Assigns temporary to previous*/
				temp = temp->next; }	/*Checks for a 'key' to be deleted while keeping count of the previous node*/
            if (temp == NULL)	/*Checks if no vowels exist in the linked list*/
				continue;
            pre->next = temp->next;		/*Removes the node from the list*/
            free(temp);		/*Deallocates the node*/
            temp = pre->next;	/*Temporary is updated for the next iteration*/
            r++; 	/*Increment and update the count of vowels removed*/
        }
    }
	return 0;	/*Only returns a status 0 if the vowels were successfully removed*/
}