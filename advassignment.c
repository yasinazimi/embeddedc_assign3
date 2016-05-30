/**************************************************************************
48430 Embedded C - Advanced Assignment
Name: Yasin Azimi
Student ID: 11733490
Date of submission: 30/05/2016
A brief statement on what you could achieve (less than 50 words):
= 

A brief statement on what you could NOT achieve (less than 50 words):
= 


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
	char c;
	struct node *next;
};

typedef struct node node_n;


/**************************************************************************
Function prototypes
***************************************************************************/
int main(int argc, char* argv[]);
void printmenu(void);
void printlinkedlist(node_n*first);
int delhead(node_n**first);
int delvowels(node_n**first);
int isvowel(char v);


/**************************************************************************
Main
***************************************************************************/
int main(int argc, char* argv[]) {
	int m, n;
	char option;
	while (argc <= 1) {
		printf("Parse a sentence");
		return 1;
	}
	
	node_n* first = NULL;
	first = malloc(sizeof(node_n));
	if (first == NULL) {
		return 1;
	}
	
	node_n* curr = first;
	for (m = 1; m < argc; m++) {
		for (n = 0; argv[m][n] != '\0'; n++) {
			curr->c = argv[m][n];
			curr->next = malloc(sizeof(node_n));
			curr = curr->next;
		}
	} curr->next = NULL;
	
	do {
		printmenu();
		printf("Enter your choice>");
		scanf("%c", &option);
		switch (option) {
			case '1': printlinkedlist(first); break;
			case '2': delhead(&first); break;
			case '3': break;
			case '4': exit(0);
			default: printf("Invalid choice.\n"); break;
		}
		while (getchar() != '\n');
	} while (option != 4);
	return 0;
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
void printlinkedlist(node_n*first) {
	node_n* curr = first;
	do {
		printf("%c", curr->c);
		curr = curr->next;
	} while (curr != NULL);
	printf("\n");
}


/**************************************************************************
Delete the head (first node) of a linked list of type struct node
***************************************************************************/
int delhead(node_n**first) {
	node_n* next_node = NULL;
	if (*first != NULL) {
		next_node = (*first)->next;
		free(*first);
		*first = next_node;
		return 1;
	}
	else {
		return 0;
	}
}


/**************************************************************************
Delete the vowels (a,e,i,o,u) in a sentence
***************************************************************************/
int delvowels(node_n**first) {
	int isvowel(char v);
	node_n *resetfirst = 0;
	*first = resetfirst;
	
	while (first != 0) {
		if(isvowel(*first->c) == 1) {
			first->c = 1;
		}
		first = first->next;
	}
	*first = resetfirst;
	
	while (first != 0) {
		if (first->c != 1) {
			printf("%c", first->c);
		}
		first = first->next;
	}
	
}


/**************************************************************************
Delete the vowels (a,e,i,o,u) in a sentence
***************************************************************************/
int isvowel(char v) {
	switch(v) {
		case 'a': return 1;
		case 'e': return 1;
		case 'i': return 1;
		case 'o': return 1;
		case 'u': return 1;
		case 'A': return 1;
		case 'E': return 1;
		case 'I': return 1;
		case 'O': return 1;
		case 'U': return 1;
		default: return 0;
    }
}