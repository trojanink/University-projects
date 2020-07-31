#include<stdlib.h>
#include<stdio.h>

/* ----------------------------------------- */

typedef struct node {
	char data;	
	struct node *next;
	struct node *prev;
} listT;

/* ----------------------------------------- */

void addToFront(listT** head, char c);
void printList(listT *head);
void clearList(listT *head);
listT* recInterleave(listT *h1, listT *h2);
/* ----------------------------------------- */

int main (int argc, char *argv[]) {
	listT *head = NULL;
	listT *head2 = NULL;


	addToFront(&head2, '7');
	addToFront(&head2, '6');
	addToFront(&head2, '5');

	addToFront(&head, 'd');
	addToFront(&head, 'c');
	addToFront(&head, 'b');
	addToFront(&head, 'a');

	addToFront(&head2, '4');
	addToFront(&head2, '3');
	addToFront(&head2, '2');
	addToFront(&head2, '1');

	printf("Created list 1: \n");
	printList(head);

	printf("Created list 2: \n");
	printList(head2);
	
	printf("\nCreate mixed list: \n");
	head = recInterleave(head, head2);
	printList(head);
	clearList(head);

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
		printf("%c ", head->data);
		tail = head;
		head = head->next;
	}
	printf("]\n");

	printf("\tBackward: [ ");
	while (tail != NULL) {
		printf("%c ", tail->data);
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

/* ----------------------------------------- */

listT* recInterleave(listT *h1, listT *h2)
{
	listT* tmp;

	if (h1)
	{
		if (h2)
		{
			tmp = h2->next;

			h2->next = h1->next;
			h1->next = h2;
			h2->prev = h1;

			if (h2->next)
			{
				h2->next->prev = h2;
			}

			recInterleave(h2->next, tmp);

			if (!h2->next)
			{ // BONUS !!
				h2->next = tmp;
			}

		}

		return h1;
	}
	else if (h2)
	{
		return h2;
	}

	return NULL;
}
