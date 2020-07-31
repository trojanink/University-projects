#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int num;
	struct node *next;
} nodeT;

void printreverse(nodeT *head) {
  
  if (head==NULL) {
    return;
  }
  printreverse(head->next);
  printf("%d\n", head->num);

  
}
  
  




int main (int argc, char *argv[]) {
	nodeT *head, *newnode, *curr;
	head = NULL;
	int i;
	for (i=10; i>0; i--) {
		newnode=(nodeT*)malloc(sizeof(newnode));
		if (newnode == NULL) {
			printf("Error\n");
			exit(1);
		}
		newnode->num = i;
		newnode->next = head;
		head = newnode;
	}
	
	printreverse(head);
	
	
	/* katharismos listas */
	curr = head;
	
	
	
	while (curr != NULL) {
		head = head->next;
		free(curr);
		curr = head;
	}
	return 0;
} 