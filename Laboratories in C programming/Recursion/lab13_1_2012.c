#include<stdlib.h>
#include<stdio.h>

typedef enum {ORIGINAL=1, COPY} stateType;

typedef struct node {
	char data;	
	stateType state;
	struct node *next;
	struct node *prev;
} listT;

/* ----------------------------------------- */

void addToFront(listT** head, char c);
void printList(listT *head);
void clearList(listT *head);

/* ----------------------------------------- */

int main (int argc, char *argv[]) {

	listT *head = NULL;

	addToFront(&head, '9');
	addToFront(&head, '7');
	addToFront(&head, '5');
	addToFront(&head, '3');
	addToFront(&head, '1');

	printf("Created list : \n");
	printList(head);
	
	printf("\nDuplicate list: \n");

	/* Prostheste kwdika edw */

	return 0;
}


/* ----------------------------------------- */

void addToFront(listT** head, char c) {
	listT *newnode;

	newnode = (listT*) malloc (sizeof(listT));
	if (newnode == NULL) {
		printf("Memory allocation for new node failed. Action canceled.\n");
		return ;
	}
	
	newnode->data = c;
	newnode->state = ORIGINAL;
	newnode->next = *head;
	newnode->prev = NULL;

	if (*head) {
		(*head)->prev = newnode;
	}
	(*head) = newnode;
}

/* ----------------------------------------- */

void printList(listT *head) {

	listT *tail;

	printf("\tForward: [ ");
	tail = NULL;
	while (head != NULL) {
		printf("%c(%c) ", head->data, head->state==ORIGINAL? 'o': 'c');
		tail = head;
		head = head->next;
	}
	printf("]\n");

	printf("\tBackward: [ ");
	while (tail != NULL) {
		printf("%c(%c) ", tail->data, tail->state==ORIGINAL? 'o': 'c');
		tail = tail->prev;
	}
	printf("]\n");
}  

/* ----------------------------------------- */

void clearList(listT *head) {

	listT *save;
	while (head != NULL) {
		save = head->next;
		free(head);
		head = save;
	}
}
