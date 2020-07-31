#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/************************************************************************/

typedef struct node {
	char *name;
	int age;
	struct node *next;
} personT;

/************************************************************************/
personT *clone (personT *someone);
personT *initialize ();
void print(personT *first);
void clear(personT *first);

/************************************************************************/
int main (int argc, char *argv[]) {
	personT *first;

	first = initialize();
	print(first);

	while (first->age < 10)
	{
		first = clone(first);
		print(first);
	}
	
	clear(first);

	return 0;
}


/************************************************************************
* Apeleutherwnei oli ti dunamika desmeumeni mnimi tou programmatos.              
************************************************************************/

void clear(personT *first) {
	while (first != NULL) 
	{
		personT *cur = first;
		first = first -> next;
		
		free(cur->name);
		free(cur);
	}
}
	

/************************************************************************
* Ektupwnei ta periexomena mias listas apo sprites ksekinwntas apo ton 
* kombo first      
************************************************************************/

void print(personT *first) {
	while (first != NULL) {
		printf("[%s, %d] ", first->name, first->age);
		first = first -> next;
	}
	printf("\n");
}


/************************************************************************
* Dimiourgei ena neo kombo pou periexei ta idia stoixeia me ton kombo
* kombo someone, alla ilikia megalyteri kata 1, kai ton topothetei 
* amesws prin ton someone. Epistrefei ti dieuthunsi tou neou kombou.
* An exei parousiastei opoiodipote problima, tote apodesmeuetai oli i 
* dunamika desmeumeni mnimi mexri twra kai i sunartisi epistrefei NULL.
************************************************************************/
personT *clone (personT *someone) {
	personT* new = (personT*) malloc(sizeof(personT));
	if (!new)
	{
		puts("malloc error!!");
		return NULL;
	}

	new->name = (char*) malloc((strlen(someone->name) + 1) * sizeof(char));
	if (!new->name)
	{
		free(new);
		puts("malloc error!");
		return NULL;
	}

	strcpy(new->name, someone->name);
	new->age = someone->age + 1;
	new->next = someone;

	return new;
}


/************************************************************************
* Kataskeuazei ena neo kombo listas me onoma "Adam" kai ilikia 1, ki 
* epistrefei ti dieuthunsi tou.
* I lista pou telika tha dimiourgithei prepei na einai apla diasundedemeni, 
* mi-kukliki, xwris sentinel.
* Ylopoiiste auti ti sunartisi sto erwtima 1.
************************************************************************/
personT *initialize () {
	personT* adam = (personT*) malloc(sizeof(personT));
	if (!adam)
	{
		puts("malloc error!!");
		return NULL;
	}

	adam->name = (char*) malloc((strlen("Adam") + 1) * sizeof(char));
	if (!adam->name)
	{
		free(adam);
		puts("malloc error!");
		return NULL;
	}

	strcpy(adam->name, "Adam");
	adam->age = 1;
	adam->next = NULL;

	return adam;
}
