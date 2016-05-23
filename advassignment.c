/**************************************************************************
48430 Embedded C - Advanced Assignment
Name: Yasin Azimi
Student ID: 11733490
Date of submission: 23/05/2016
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
Structs:
***************************************************************************/
struct node{
	char c;
	struct node* next;
};

typedef struct node point;


/**************************************************************************
Function prototypes
***************************************************************************/
void printmenu(void);
void printlinkedlist();
int delhead();
int delvowels(char vowel);


/**************************************************************************
Main
***************************************************************************/
int main() {
	int vowel = 0;
	char option;
	
	do {
		printmenu();
		printf("Enter your choice>");
		scanf("%c", &option);
		switch (option)
		{
			case '1': printlinkedlist(); break;
			case '2': delhead(); break;
			case '3': delvowels(vowel); break;
			case '4': exit(0); break;
			default: exit(EXIT_SUCCESS);
		}
	} while (option != '4');
	return 1;
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
Print all nodes in a linked list of struct node type. Follow the print
format of the executable provided. Pass ONLY ONE PARAMETER to this
function ("Parse a sentence")
***************************************************************************/
void printlinkedlist(point**ptr){
	char c;
	c = getchar();
	printf("Parse a sentence> ");
	while((c = getchar()) != '\n') {
		putchar(c);
	}	
}


/**************************************************************************
Delete the head (first node) of a linked list of type struct node. Pass
ONLY ONE PARAMETER to this function.
return 0 - if the head of the linked list could be deleted successfully
return 1 - otherwise
***************************************************************************/
int delhead(){
	return 0;
}


/**************************************************************************
Delete the vowels (a,e,i,o,u) in a sentence
***************************************************************************/
int delvowels(char vowel){
	switch(vowel) {
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