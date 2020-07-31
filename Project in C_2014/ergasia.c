/*Mixalis Chatziparaskeuas 1629, Ioannis Vlachos 1637 project ston programmatismo I */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define WORDLEN 30

 /* orisma tupou enum gia arithmisi taksinomimenhs listas i oxi*/
enum theme {SOR,UNS};         

typedef union index_nod {      
	int num_nod;
	char *word_nod;
}nod_T;

typedef struct list{
	enum theme feature;
	nod_T elements;
	struct list *nxt;
	struct list *prv;
}list_T;

/* Anafora twn synartisewn-sxolia gia thn leitourgia kathe sunartisis parakatw*/
void randomz(char *str1,list_T *head);         
void printlist(list_T *root);
void printlist_path(list_T *root);
void free_list(list_T *root);
int Available_or_No(char *runner_str,list_T *head);
int diff_word(char *s1,char *s2);
int check_arguments(int x,char *argv[],int *wordlen, int *stp);
char *getWord(char *filename);
list_T *create(int length,char *word);
list_T *create_path(list_T *head);
list_T *insert_path(char *word,list_T *head);
list_T *create_sort(list_T *head);
list_T *insert_sort(list_T *head1,list_T *head2,list_T *head3);

int main(int argc, char *argv[]) {
	
	int control,i,pos;
	int steps,word_length;
	list_T *list1,*list_path=NULL,*list_sort=NULL;
	char start_word[WORDLEN],target_word[WORDLEN],runner_str[WORDLEN],ch;
	
	
	control=check_arguments(argc,argv,&word_length,&steps);  /* klisi sinartisis elegxou orismatwn*/  
	if (control==1) {		
		srand( (int) time(NULL));
		do{
		list1=create(word_length,argv[3]);        /*dimiourgia listas pou periexei oles tis lekseis tou sugkekrimenou mikous*/ 
		if(list1==NULL){
			printf("Too few words\n");
			exit(1);
		}
		randomz(start_word,list1);            /* tuxaia epilogh apo thn lista leksewn sugkekrimenou mikous */ 
		randomz(target_word,list1);
		printf("\tStarting word: %s\n\tTarget word: %s\nTry to go from \"%s\" to \"%s\" in no more %d steps\n",start_word,target_word,start_word,target_word,steps);
		list_path=create_path(list_path);
		list_path=insert_path(start_word,list_path);
		list_sort=create_sort(list_sort);
		list_sort=insert_sort(list1,list_path,list_sort);
		i=0;                                  /* metraei tous gurous pou exoume paiksei */
		while(i<steps){
			if(list_sort->elements.num_nod==0){   /* elegxos gia to an uparxoun diathesimes lekseis pou apexoun kata ena gramma apo thn teleutaia leksi tou monopatiou*/ 
				i=steps;
				free_list(list_sort);
				printf("There are no words to choose from.Sorry\n");
				break;
			}
			if(list_path->feature==UNS){          /* elegxos me thn voitheia ths enum gia katalili ektypwsi*/ 
				printlist_path(list_path);
			}
			printf("Remaining steps %d\n",steps-i); /* ektypwnei ta vimata pou apomenoun*/
			printf("Target: %s\n",target_word);
			if(list_sort->feature==SOR){
				printlist(list_sort);
			}
			printf("\nEnter selection:");
			scanf("%s",runner_str);
			pos=Available_or_No(runner_str,list_sort);    /* elegxos gia to an i leksi pou diabasame uparxei mesa sthn lista*/
			if(pos==0){
				printf("ERROR: Your selection is not available. Try again\n\n");
				continue;
			}
			free_list(list_sort);                        /* apodesmeush mnimis ths taksinomimenis listas dioti se kathe vima allazei*/
			if(strcmp(runner_str,target_word)==0){
				list_path=insert_path(runner_str,list_path);
				break;
			}
				
			list_path=insert_path(runner_str,list_path);
			list_sort=create_sort(list_sort);
			list_sort=insert_sort(list1,list_path,list_sort);
			i++;
		}
		if(i<steps){
			printf("\n");
			printf("GOOD WORD! ");
			printlist_path(list_path);
			printf("\n");
		}else{
			printf("\n");
			printf("TOO BAD :( ");
			printlist_path(list_path);
			printf("\n");
			printf("Target was is %s",target_word);
			printf("\n");
		}
		free_list(list1);                  /* apodesmeush mnimis tis listas pou periexei oles tis lekseis tou sugkekrimenou mikous*/
		free_list(list_path);              /* apodesmeush mnimis ths listas pou perixei tis lekseis tou monopatiou kathe xroniki stigmh*/
		printf("\n");
		do{
			printf("Play again? (y/n):");
			scanf(" %c",&ch);
			if((ch!='y') && (ch!='Y') && (ch!='n') && (ch!='N')){     /* elegxos gia enarksi neou paixnidi i oxi*/
				printf("Please enter y for yes or n for no.\n");
			}
		}while((ch!='y') && (ch!='Y') && (ch!='N') && (ch!='n'));
		if((ch=='n') || (ch=='N')){
			exit(1);
		}
		}while((ch=='y') || (ch=='Y'));
	}	
	return 0;
}	
/* sunartisi i opoia dialegei mia tyxaia leksi apo to leksiko*/
void randomz(char *str1,list_T *head){
	list_T *curr;
	int key=0,i;
	key=rand() % head->elements.num_nod;    
	curr=head->nxt;
	for(i=1;i<key;i++){
		curr=curr->nxt;			
	}
	strcpy(str1,curr->elements.word_nod);
}
/* sunartisi i opoia entwpizei an i leksi pou diabazoume yparxei mesa sthn lista pou periexei tis proteinomenes lekseis*/
int Available_or_No(char *runner_str,list_T *head){   
	list_T *curr;
	curr=head->nxt;
	while(curr!=head){
		if(strcmp(runner_str,curr->elements.word_nod)==0){
			return 1;
		}
		curr=curr->nxt;
	}
	return 0;
}
 /*  synartisi poy tha pairnei 2 strings me to idio mikos kai tha briskei posa grammata exoyn diafora*/
int diff_word(char *s1,char *s2){  
	int i,counter=0;
	for(i=0;s1[i]!='\0';i++){
		if(s1[i]!=s2[i]){	
			counter++;
		}
	}
	
	return counter;
}
 /*elegxos orismatwn kai egkures i akires times*/
int check_arguments(int x,char *argv[],int *wordlen, int *stp){ 
	if(x<4){	
		printf("Insufficient arguments.\n");
		printf("%s LENGTH STEPS DICTIONARY\n\tLENGTH: REQUESTED LENGTH OF WORD.\n\tNsteps: requested number of steps. Must be >0\n\tDICTIONARY: name of dictionary file\n",argv[0]);
		return 0;
	}
	if(x>4){
		printf("Too many arguments.\n");
		printf("%s LENGTH STEPS DICTIONARY\nLENGTH: REQUESTED LENGTH OF WORD.\nNsteps: requested number of steps. Must be >0\nDICTIONARY: name of dictionary file\n",argv[0]);
		return 0;
	}
	*wordlen=atoi(argv[1]);
	*stp=atoi(argv[2]);
	if(*stp<0){
		do{
			printf("You may not have fewer than one steps. Specify a different number of steps:\n");
			scanf("%d",stp);
		}while(*stp<0);
	}
	return 1;
}

/* Given the name of a file, read and return the next word from it, 
or NULL if there are no more words */

char *getWord(char *filename)  {
	char formatstr[15], *word;
	static FILE *input;
	static int firstTime = 1;
	if (firstTime) { 
		input = fopen(filename, "r");
		if (input == NULL) {
			printf("ERROR: Could not open file \"%s\"\n", filename);
			exit(1);
		}
		firstTime = 0;
	}
	word = (char*)malloc(sizeof(char)*WORDLEN);
	if (word == NULL) {
		printf("ERROR: Memory allocation error in getWord\n");
		exit(1);
	}
	sprintf(formatstr, "%%%ds", WORDLEN-1);
	fscanf(input, formatstr, word);
	if (feof(input)) {
		fclose(input);
		firstTime = 1;
		return NULL;
	}
	return word;
}
/*lista i opoia periexei oles tis lekseis tou leksikou pou exoun to epithimito mikos*/
list_T *create(int length,char *word){ 
	list_T *root;
	list_T *new;
	char *run_str;
	root=(list_T*)malloc(sizeof(list_T));
	if(root==NULL){
		printf("No memory\n");
		exit(1);
	}
	root->feature=UNS;
	root->elements.num_nod=0; 
	root->nxt=root;
	root->prv=root;
	do{
		run_str=getWord(word);                               /* epilogh leksewn mesa apo thn getword*/
		if(run_str !=NULL && length==strlen(run_str)){       /* elegxos gia to an exei ftasei sto telos kai an exoun to epithimito mikos*/
			root->elements.num_nod=root->elements.num_nod+1;
			new=(list_T*)malloc(sizeof(list_T));
			if(new==NULL){
				exit(1);
			}
			new->elements.word_nod=(char*)malloc(sizeof(char));
			if(new->elements.word_nod==NULL){	
				exit(1);
			}
			new->feature=UNS;
			strcpy(new->elements.word_nod,run_str);
			new->nxt=root->nxt;
			new->prv=root;
			new->nxt->prv=new;
			new->prv->nxt=new;
		}	
	}while(run_str!=NULL);	
	if(root->elements.num_nod<=2){
		free_list(root);
		return NULL;
	}
	return root;		
}

/* sunartisi pou dimiourgei thn kefali tis listas tou monopatiou*/
list_T *create_path(list_T *head){
	list_T *root;
	root=(list_T*)malloc(sizeof(list_T));
	root->feature=UNS;
	if(root==NULL){
		printf("No memory\n");
		exit(1);
	}
	root->elements.num_nod=0; 
	root->nxt=root;
	root->prv=root;
	return root;
}
/* sunartisi pou dimiourgei thn kefali tis taksinomimenhs listas*/
list_T *create_sort(list_T *head){
	list_T *root;
	root=(list_T*)malloc(sizeof(list_T));
	root->feature=SOR;
	if(root==NULL){
		printf("No memory\n");
		exit(1);
	}
	root->elements.num_nod=0; 
	root->nxt=root;
	root->prv=root;
	return root;
}		

 /* sunartisi pou eisagei lekseis sthn lista tou monopatiou*/
list_T *insert_path(char *word,list_T *head){
	list_T *curr,*new;
	new=(list_T*)malloc(sizeof(list_T));
	if(new==NULL){
		exit(1);
	}
	new->feature=UNS;
	new->elements.word_nod=(char*)malloc(sizeof(char));
	if(new->elements.word_nod==NULL){
		exit(1);
	}
	strcpy(new->elements.word_nod,word);
	curr=head->prv;

	new->nxt=head;
	new->prv=head->prv;
	curr->nxt=new;
	head->prv=new;
	head->elements.num_nod++;
	return head;
}
/*sunartisi pou eisagei lekseis sthn taksinomimeni listas*/	
list_T *insert_sort(list_T *head1,list_T *head2,list_T *head3){
	list_T *curr2;
	list_T *curr1;
	list_T *curr;
	list_T *new;
	int pos=0;
	curr2=head2->nxt;
	while(curr2->nxt!=head2){
		curr2=curr2->nxt;
	}
	curr1=head1->nxt;
	while(curr1!=head1){
		pos=diff_word(curr1->elements.word_nod,curr2->elements.word_nod); /* elegxos tis sunartisis gia to an oi duo lekseis apexoun kata ena gramma*/
		if(pos==1){
			new=(list_T*)malloc(sizeof(list_T));
			if(new==NULL){
				exit(1);
			}
			new->feature=SOR;
			new->elements.word_nod=(char*)malloc(sizeof(char));
			if(new->elements.word_nod==NULL){
				exit(1);
			}
			strcpy(new->elements.word_nod,curr1->elements.word_nod);
			curr=head3->nxt;
			while(curr!=head3 && (strcmp(new->elements.word_nod,curr->elements.word_nod))<=0){  /* taksinomisi tis listas */
					curr=curr->nxt;
			}
			new->nxt=curr->nxt;
			new->prv=curr;
			new->prv->nxt=new;
			new->nxt->prv=new;
			head3->elements.num_nod++;
		}	
		curr1=curr1->nxt;
	}
	return head3;	
}

/*ektipwsi taksinomimenhs listas*/
void printlist(list_T *root){         
	list_T *curr;
	int counter=1;
	curr=root->nxt;
	printf("Choose one of the following words:\n");
	for(curr=root->nxt;(curr!=root);curr=curr->nxt){
		printf("%s  ",curr->elements.word_nod);
		if (counter%4==0 && curr->nxt!=root) printf("\n");
		counter++;
	}
	printf("\n");
}

/* sunartisi pou ektupwnei tis lekseis tou monopatiou*/
void printlist_path(list_T *root){
	list_T *curr;
	printf("Progress so far:  ");
	for(curr=root->nxt;(curr!=root);curr=curr->nxt){
		if(curr->nxt!=root){
			printf("%s--->",curr->elements.word_nod);
		}else{
			
			printf("%s",curr->elements.word_nod);
		}
	}
	printf("\n");
}

/*apodesmeush ths mnimis tis listas*/
void free_list(list_T *root){ 
	list_T *curr;
	while(root->nxt!=root){
		curr=root->nxt;
		root->nxt=curr->nxt;
		free(curr->elements.word_nod);
		free(curr);
	}
	free(root);
}