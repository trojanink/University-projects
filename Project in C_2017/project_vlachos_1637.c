/* Ioannis Vlachos 1637 Project ston Programmatismo I 2017-2018 */

/*Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* This is the struct describing of a list node */
typedef struct nodelist {
	char* word_list;
	int num_words; /*plithos emfanisewn le3hs se kritikes */
	double total_score; /*a8roisma score le3hs */
	struct nodelist *next; /*deikths ston epomeno node of list */
} entryT;

/* This is the struct describing of a hash bucket/node */
typedef struct nodehash {
	int size_of_hash_table;
	int num_entries; /*plithos le3ewn-eggrafwn pou exoun mpei ston hashtable */
	entryT *table; /*o hashtable */
} hashT;

/* The global hash bucket , type of hashT ,which need to access table  */
hashT hashbucket;

/*Anafora-dhlwsh sunarthsewn gia thn parakatw leitourgia tous */
void init_hash() ;
double add_hash(char *word , int score);
void print_hash();
void free_hash();
void rehash();
double search_hash(char *word);
int hash_function (char *word);
double add_list (entryT* root , char* word , int score);
entryT* search_list (entryT* root , char* word);
void free_list (entryT* root);
void print_list(entryT* root);
entryT* substract_list(entryT* root , char *word);
char *read_next_line(char *filename);
void tolow(char* string);
entryT *list_best_score(entryT *root, entryT *curr);
entryT *table_best_score(entryT *table[], int pos);
void hash_best_score();

int main(int argc , char* argv[]) {
	char *line;
	char *token;
	int number;
	int num_words;
	double total_score;	
	double load_factor;
	char *p;
	char *str = "-p";
	char line_word[1024];
	double res;

	/*elegxos orismatwn kai ektupwsh katallhlwn mhnymatwn*/
	if((argc > 3) || (argc < 2)) { 
		printf("Incorrect number of parameters.\n");
		return (0);
	}
	if(argc == 3) {
		if(strcmp(argv[2] ,str)!=0){
			printf("Second argument is not -p.\n");
			return (0);
		}
	}
	if(argc >= 2) {
		init_hash();
		line = read_next_line(argv[1]); /*klhsh etoimis sunarthshs gia diabasma ka8e grammhs */
		while (line != NULL) {
			
			p = strtok(line , " "); /* separate se tokens me ton delimiter keno */
			if (p!=NULL) {
				number = atoi(p);
				token = strtok(NULL , " ");
				while(token != NULL) {
					tolow(token); /*function convert to lowercase */
					if (strcmp(token,"")!=0) {
						load_factor=add_hash(token , number);
						if(load_factor >= 3.0) { /*load factor limit gia leitourgia rehash kai klhsh ths */
							rehash();
						}
					}
					token = strtok(NULL , " ");
				}
			}
			free(line);
			line = read_next_line(argv[1]);
		}
		
		hash_best_score();
		printf("\n");
		if(argc == 3) {
			if(strcmp(argv[2] ,str)==0){
				print_hash();
			}
		}
	
		while(1) {
			printf("\n");
			printf("Enter review or DONE to finish:\n");
			fgets(line_word , sizeof line_word , stdin);
			token = strchr(line_word, '\n');
			if (token!=NULL) {
				*token='\0';
			}
			
			if(strcmp(line_word , "DONE") == 0) { /*me thn leksi DONE bgainei */
				break;
			}
				
			token = strtok(line_word , " ");
			total_score=0.0;
			num_words=0;
			while(token != NULL) {
				tolow(token);
				res = search_hash(token);
				if (res>=0) {
					total_score=total_score+res;
					num_words++;
				}
				token = strtok(NULL , " ");
			}
			if(num_words == 0) { /*periptwsh plithous leksewn 0 */
				printf("Sorry, there is no score for this review!\n");
			}
			else { /*upologismos score aksiologisis kai sugkriseis me to 2 , ektupwsh katallhlwn mhnymatwn */
				total_score=total_score/num_words;
				printf("Review score: %.4lf\n" , total_score);
				if(total_score < 2.0) {
						printf("This review is negative");
				}
				else if(total_score == 2.0) {
						printf("This review is neutral");
				}
				else {
						printf("This review is positive");
				}
				printf(".\n");
			}
		}
		free_hash();
	}
		
	return (0);
}
		
	/*A func initialization of hash and its contents*/
void init_hash() {
	int i;
		
	hashbucket.size_of_hash_table = 100;
	hashbucket.num_entries = 0;
	hashbucket.table = (entryT*)malloc(hashbucket.size_of_hash_table*sizeof(entryT));
	if(hashbucket.table == NULL) {
		printf("Error allocating memory\n");
		exit(1);
	}
	
	for(i=0; i< hashbucket.size_of_hash_table; i++) {
		hashbucket.table[i].word_list = NULL;
		hashbucket.table[i].total_score = 0;
		hashbucket.table[i].num_words = 0;
		hashbucket.table[i].next = &hashbucket.table[i];
	}
}

	/*A func that add node/insert word in list in a certain pos */
double add_hash(char *word , int score) {
	int hashfuctionpos;
	double load_factor;
	
	hashfuctionpos = hash_function(word);
	
	load_factor=add_list(&hashbucket.table[hashfuctionpos] , word , score);
	return load_factor;
}

	/*A func that print contents of hash */
void print_hash() {
	int i;
	for(i=0; i<hashbucket.size_of_hash_table; i++) {
		if ( hashbucket.table[i].next!=&hashbucket.table[i]) {
			printf("%4d: ", i);
			print_list(&hashbucket.table[i]);
		}
	}
	printf("\n");
}

	/*A func that destroy hash and its contents */
void free_hash() {
	int i;
	
	for(i=0; i<hashbucket.size_of_hash_table; i++) {
		free_list(&hashbucket.table[i]);
	}
	
	free(hashbucket.table);
}
		
	/* Hash function. Takes a word a returns the bucket (the position in the hash *
   table where the list in which the word "belongs" starts). */ 
int hash_function (char *word) {
  unsigned long hash = 5381;
  int c;
  
  while ((c = *word++))
    hash = ((hash << 5) + hash) + c;
  
  return hash % hashbucket.size_of_hash_table; /*epistrofh thesis ston pinaka pou prepei na apothikeutei h leksi */
}

	/* A func that rehashing a table */
void rehash() {
	int i  , hashfuctionpos;
	entryT *table2;
	entryT* curr;
	
	hashbucket.size_of_hash_table = 2*hashbucket.size_of_hash_table; /*diplasio megethos apo ton uparxon kai desmeush mnhmhs */
	table2 = (entryT*)malloc(hashbucket.size_of_hash_table*sizeof(entryT));
	if(table2 == NULL) {
		printf("Error allocating memory\n");
		exit(1);
	}
	
	for(i=0; i< hashbucket.size_of_hash_table; i++) {
		table2[i].word_list = NULL;
		table2[i].total_score = 0;
		table2[i].num_words = 0;
		table2[i].next = &table2[i];
	}
	
	for(i=0; i< hashbucket.size_of_hash_table / 2; i++) {
		while(hashbucket.table[i].next != &hashbucket.table[i]) {
			curr = hashbucket.table[i].next;
			hashbucket.table[i].next = curr->next;
			hashfuctionpos = hash_function(curr->word_list);
			curr->next = table2[hashfuctionpos].next;
			table2[hashfuctionpos].next = curr;
		}
	}
	free(hashbucket.table);
	hashbucket.table = table2;
}
	/* A func to search hash */
double search_hash(char *word) {
	int hashfuctionpos;
	entryT *curr;
	
	hashfuctionpos = hash_function(word);
	
	curr=search_list(&hashbucket.table[hashfuctionpos] , word );
	if (curr==NULL) {
		return -1.0;
	}
	else {
		return curr->total_score/curr->num_words;
	}
}

	/* A func to insert the new node in the list */
double add_list (entryT* root , char* word , int score) {
	entryT* newnode = NULL;
	entryT* curr = NULL;
	double load_factor;
	
	curr = search_list(root , word);
	if(curr == NULL) { /*an den ton vrei ton prosthetei sthn arxh ths kuklikis aplis listas , pernaei to score , au3anei tis eggrafes ston hash , kai kanei to plithos twn leksewn 1 */
		newnode = (entryT*)malloc(sizeof(entryT));
		if(newnode == NULL) {
			printf("Error allocating memory for a new node\n");
			exit(1);
		}
	
		newnode->next = root->next;
		root->next = newnode;
		newnode->word_list = (char*)malloc((strlen(word)+1)*sizeof(char));
		if(newnode->word_list == NULL) {
			printf("Error allocating memory for field of node word_list\n");
			exit(1);
		}
	
		strcpy(newnode->word_list , word);
		newnode->total_score = score;
		newnode->num_words = 1;
		hashbucket.num_entries++;
	}
	else {
		curr->total_score = curr->total_score + score; /*an tin vrei prosthetei to score sto uparxon kai au3anei to plithos twn leksewn */
		curr->num_words++;
	}

	load_factor = (double) hashbucket.num_entries / hashbucket.size_of_hash_table; /*Calculate load factor kai epistrofh tou gia xrhsh */
	return load_factor;
}

	/* A func to search my list for the same word */
entryT* search_list (entryT* root , char* word) {
	entryT* curr = NULL;
	
	for(curr = root->next; curr != root; curr = curr->next) {
		if(strcmp(curr->word_list , word)==0) {
			return curr;
		}
	}
	return NULL;
}

	/* A func to free my list */
void free_list (entryT* root) {
	entryT* curr = NULL;
	
	while(root != root->next) {
		curr = root->next;
		root->next = curr->next;
		free(curr->word_list);
		free(curr);
	}
}

	/* A func to print the contents in the nodes of a list */
void print_list(entryT* root) {
	entryT* curr=NULL;
	
	for(curr = root->next; curr != root; curr = curr -> next) {
		printf("[ \"%s\" %d %.2lf ]" , curr->word_list , curr->num_words , curr->total_score);
		if (curr->next!=root) {
			printf(", ");
		}
	}
	
	printf("\n");
}
	/* A func to substract node which is same as the word given */
entryT* substract_list(entryT* root , char *word) {
	entryT* curr = NULL;
	entryT* last = NULL;
	
	for(curr = root->next , last = root; curr != root; curr = curr -> next , last = last ->next) {
		if(strcmp(curr->word_list , word)==0) { /*eyresh katallhlhs leksis ston komvo , metakinisi deiktwn-afairesh , meiwsh eggrafwn ston hash*/
			last->next = curr->next;
			hashbucket.num_entries--;
				return curr;
		}
	}
	return NULL;
}
	/* A given read_next_line func */
char *read_next_line(char *filename) {
	static int firstrun = 1;
	static FILE *fp;
	if (firstrun) {
		fp = fopen(filename, "r");
		if (fp == NULL) {
			fprintf(stderr, "Error opening file \"%s\" for reading.\n", filename);
			exit(1);
		}
		firstrun = 0;
	}
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	linelen = getline(&line, &linecap, fp);	
	if (linelen == -1) {
		fclose(fp);
		firstrun = 1;
		return NULL;
	}
	char *newline = strchr(line, '\n');
	if (newline) *newline='\0';
	return line;
}
	/*A func that convert uppercase to lowercase letters of a string */
void tolow(char* string) {
	 int i;
	 
	for(i =0; string[i] != '\0'; i++) {
		if (isupper(string[i])) {
			string[i]=tolower(string[i]);
		}
	}
	if (string[i-1]=='\t') { /*remove tab and put backslash_zero */
		string[i-1]='\0';
	}
 }
 
	/*Anadromiki euresh ths leksis pou exei to kalutero meso score , an einai adeia h an den exw leksi epistrefei NULL. Otan bre8w ston teleutaio komvo autos 8a einai o megistos. Epishs briskw anadromika thn kalyterh leksi gia thn epomenh lista. Upologizw score1 , score2 kai katopin epistrefw ton megalutero apo ton trexonta h apo th lush ths anadromikis */
entryT *list_best_score(entryT *root, entryT *curr) {
	entryT *curr_best_score;
	double score1, score2;
	
	if (curr==root) return NULL;
	if (curr->next == root) return curr;
	
	curr_best_score=list_best_score(root, curr->next);
	if (curr_best_score!=NULL) {
		score1=curr_best_score->total_score/curr_best_score->num_words;
	} else {
		score1=0.0;
	}
	if (curr!=NULL) {
		score2=curr->total_score/curr->num_words; 
	} else {
		score2=0.0;
	}
	if (score1>score2) {
		return curr_best_score;
	}
	else {
		return curr;
	}
		
 }
 
	/*Idia leitourgia me prin , prwto stoixeio einai to megisto , skopos mou einai phgainontas apo to telos pros thn arxh na vrw to teleutaio pou einai "best" */
entryT *table_best_score(entryT *table[], int pos) {
	entryT *curr_best_score;
	double score1, score2;
	
	if (pos==0) return table[pos];
	curr_best_score=table_best_score(table, pos-1);
	if (curr_best_score!=NULL) {
		score1=curr_best_score->total_score/curr_best_score->num_words;
	}
	else {
		score1=0.0;
	}
	if (table[pos]!=NULL) {
		score2=table[pos]->total_score/table[pos]->num_words; 
	} 
	else {
		score2=0.0;
	}
	if (score1>=score2) {
		return curr_best_score;
	}
	else {
		return table[pos];
	}
}
 
void hash_best_score() {
	entryT **best_score_table;
	entryT *best_score;
	double res;
	int i;
	
	best_score_table = (entryT**)malloc(hashbucket.size_of_hash_table*sizeof(entryT*));
	if(best_score_table == NULL) {
		printf("Error allocating memory\n");
		exit(1);
	}
	
	for(i=0; i< hashbucket.size_of_hash_table; i++) {
		best_score_table[i] = list_best_score(&hashbucket.table[i], hashbucket.table[i].next); /*klhsh listas euresh anadromika kalyterou kombou*/
	}
	
	best_score=table_best_score(best_score_table, hashbucket.size_of_hash_table-1);/*klhsh pinaka euresh anadromika kalyterou kombou*/
	
	if (best_score!=NULL) {
		res=best_score->total_score/best_score->num_words;
		printf("The most positive word is \"%s\" with a score of %.3lf\n",best_score->word_list,res);
	} else {
		printf("No data in hash table.\n");
	}

	free(best_score_table);
 }
