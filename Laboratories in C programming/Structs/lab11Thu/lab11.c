#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NUMSPRITES 10
#define NUMNAMES 10


/************************************************************************/
typedef enum {GREMLIN, IMP} typeT;

typedef struct node {
	typeT species;   /* Eidos */
	char *name;
	int lives;
	struct node *next;
} creatureT;


/************************************************************************/
creatureT *getGremlins (creatureT sprites[]);

void initialize (creatureT sprites[]);

void printGremlins(creatureT *first);

void killGremlins(creatureT *first);

/************************************************************************/
int main (int argc, char *argv[]) {

	creatureT sprites[NUMSPRITES];

	initialize(sprites);

	creatureT *grems = getGremlins(sprites);
	printGremlins(grems);
	killGremlins(grems);

	return 0;
}


/************************************************************************
* Pairnei ena pinaka apo sprites, ton diatrexei, kai gia kathe ena apo 
* auta elegxei an einai GREMLIN 'i IMP. 
* An einai GREMLIN tote kataskeuazei ena neo kombo listas, antigrafei
* se auton ta stoixeia autou tou gremlin kai prosthetei ton kombo stin 
* arxi mias listas.
* Sto telos epistrefei (deikti pros) tin kefali tis listas. 
* An exei parousiastei opoiodipote problima, tote apodesmeuetai oli i 
* dunamika desmeumeni mnimi mexri twra kai i sunartisi epistrefei NULL.
* I lista prepei na einai apla diasundedemeni, mi-kukliki, xwris sentinel.
* Ylopoiiste auti ti sunartisi sto erwtima 1.
************************************************************************/
creatureT *getGremlins (creatureT table[]) {
	int i;
	creatureT* temp;
	creatureT* head = NULL;

	for (i = 0; i < NUMSPRITES; i++)
	{
		if (table[i].species == GREMLIN)
		{
			temp = (creatureT*) malloc(sizeof(creatureT));
			if (!temp)
			{
				puts("malloc error!!");
				killGremlins(head);
				break;
			}

			temp->name = (char*) malloc((strlen(table[i].name) + 1) * sizeof(char));
			if (!temp->name)
			{
				puts("malloc error!");
				free(temp);
				killGremlins(head);
				break;
			}

			strcpy(temp->name, table[i].name);
			temp->species = table[i].species;
			temp->lives = table[i].lives;
			temp->next = NULL;

			if (head)
			{
				temp->next = head;
			}
			head = temp;
		}
	}

	return head;
}


/************************************************************************
* Apeleutherwnei oli ti dunamika desmeumeni mnimi tou programmatos.
************************************************************************/
void killGremlins(creatureT *first) {
	while (first != NULL) 
	{
		creatureT *cur = first;
		first = first -> next;
		
		free(cur->name);
		free(cur);
	}
}
	

/************************************************************************
* Ektupwnei ta periexomena mias listas apo sprites ksekinwntas apo ton 
* kombo first      
************************************************************************/
void printGremlins(creatureT *first) {
	while (first != NULL) {
		printf("[%s, %d] ", first->name, first->lives);
		first = first -> next;
	}
	printf("\n");
}


/************************************************************************
* Arxikopoiei ena pinaka apo sprites me tuxaia onomata, ilikies, eidi.    
*************************************************************************/

void initialize (creatureT sprites[]) {
	int i;
	char *names[NUMNAMES]={"Bob", "Alice", "Mary", "Harry", "Jim", "Anne", 
							"Natasha", "Boris", "Pete", "Sarah"};
	//srand((int)time(NULL)); 
	srand(0);
	printf("Initial population:\n");
	for (i=0; i<NUMSPRITES; i++) {
		sprites[i].species = (rand()%2)? GREMLIN : IMP;
		sprites[i].name = names[rand()%NUMNAMES];
		sprites[i].lives = rand()%9+1;
		printf("\t%d: %s, %s, %d\n", \
				i, \
				(sprites[i].species==GREMLIN)? "Gremlin" : "Imp", \
				sprites[i].name, \
				sprites[i].lives \
		);
	}
}
