
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 26
#define M 10

typedef struct table{
	double timi;
	char title[50];
	struct table * nxt_title;
	struct table * nxt_timi;
}list;



//sinartisi dimiourgias taxinomimenon liston kata titlo kai timi
void insert(list *titles[],char *name,list *prices[],int timi){
	
	int tcell,pcell;   //pcell=>keli pinaka timon ______tcell=>keli pinaka titlon
	list *curr,*new,*prv;
	
	//dimiourgia neou komvou 
	new=(list*)malloc(sizeof(list));
	if(new==NULL){
		printf("memory allocation problem\n");
		exit(1);
	}
	new->timi=timi;
	strcpy(new->title, name);
	
	//euresi 8esis ston pinaka timon 
	for(pcell=0;pcell<10;pcell++){	
		if((timi>=(pcell*10)&&(timi<(pcell+1)*10))){break;}
	}
	
	//elegxos gia keni lista
	if(prices[pcell]==NULL){
		prices[pcell]=new;				
		prices[pcell]->nxt_timi=NULL;
	}
	else{
		//euresi 8esis topo8etisis tou kainourgiou komvou 
		for(curr=prices[pcell];curr->nxt_timi!=NULL&&curr->timi<timi;curr=curr->nxt_timi){prv=curr;}
			//periptosi pou to stoixeio einai mikrotero se timi apo ola 
			if(curr==prices[pcell]&&curr->timi>=timi){						
				new->nxt_timi=curr;	
				prices[pcell]=new;					
			}
			//endiameses periptoseis
			else if(curr->timi>=timi){							
				new->nxt_timi=curr;	
				prv->nxt_timi=new;
			}
			//periptosi pou dn iparxei kanena stoixeio megalitero apo to neo
			else{
				new->nxt_timi=curr->nxt_timi;
				curr->nxt_timi=new;
			}
	}
	

	//i metavliti c ka8orizei se poia 8esi tou pinaka 8a mpei to stoixeio
	//aferoume me 65 pou einai o kodikos ASCII tou xarakthra 'A'gia na vroume
	//tin apostash toy protou xarakthra tou titlou
	tcell=name[0]-65;
	
	//elegxos gia keni list
	if(titles[tcell]==NULL){
		titles[tcell]=new;				
	}
	else{
		//euresi 8esis topo8etisis tou kainourgiou komvou 
		for(curr=titles[tcell];curr->nxt_title!=NULL&&strcmp(curr->title,name)<=0;curr=curr->nxt_title){prv=curr;}
		//periptosi pou to stoixeio einai mikrotero se timi apo ola 
		if(curr==titles[tcell]&&strcmp(curr->title,name)>0){
			new->nxt_title=curr;	
			titles[tcell]=new;					
		}				
		//endiameses periptoseis
		else if(strcmp(curr->title,name)>0){
			new->nxt_title=curr;	
			prv->nxt_title=new;
		}
		//periptosi pou dn iparxei kanena stoixeio megalitero apo to neo
		else{
			new->nxt_title=curr->nxt_title;
			curr->nxt_title=new;
		}				
	}
}

//sinartisi ektiposis stoixeion sta arxeia 
void save(char sel,FILE *output,list **array,int size){
	int j;
	list *curr;
	
	//apothikeusi
	for(j=0;j<size;j++){
		if(array[j]!=NULL){		
			for(curr=array[j];curr!=NULL;(sel=='t') ? (curr=curr->nxt_title):(curr=curr->nxt_timi)){
				//ektiposi analoga me tin epilogi sel
				(sel=='t') ? (fprintf (output, "%.2lf (%s)\n", curr->timi, curr->title) ) :
				(fprintf (output, "%s (%.2lf)\n", curr->title, curr->timi) );
			}
		}
	}
	

}


//sinartisi apodesmeusis sinolikis  mnimis
void free_memory(list **titles,list **prices,char *tname,char* pname){
	list *curr, *next;
	int i;
	
	for(i=0;i<N;i++){
		for(curr=titles[i];curr!=NULL;curr=next){
			next=curr->nxt_title;
			free(curr);
		}
	}
	
	free(tname); //apeleutherosi mnimis tou onomatos arxeiou titlwn
	free(pname); //apeleutherosi mnimis tou onomatos arxeiou timwn
}

int main(int argc,char* argv[]){

	char *tname,*pname,name[50];
	int i;
	list *prices[M],*titles[N];
	FILE *ftitles,*fprices,*file;	
	double timi;
	
	//arxikopoiisi pinakon 
	for(i=0;i<M;i++){
		prices[i]=NULL;	
	}
	for(i=0;i<N;i++){
		titles[i]=NULL;
	}
	
	//elegxos gia eisagosi arxeiou
	if(argc!=2){
		printf("Missing Parameters\n");
		return 1;
	}
	
	//desmeusi mnimis gia onoma ton 2 arxeion 
	tname=(char*)malloc(strlen(argv[1])+7);
	pname=(char*)malloc(strlen(argv[1])+8);
	
	if(tname==NULL || pname==NULL){
		printf("Problem allocating memory \n");
		return 1;	
	}
	
	//dimiourgia titlon arxeion
	strcpy(pname,argv[1]);	
	strcpy(tname,argv[1]);	
	strcat(pname,".prices"); 
	strcat(tname,".titles");
	

	file=fopen(argv[1],"r");
	
	if(file==NULL){
		printf("error opening file \n");
		return(1);
	}

	//anagnosi seira seira to periexomeno tou arxeio pou dothike apo tin grammi entolon
	while(fscanf(file,"%s %lf",name,&timi)!=EOF){
		insert (titles,name,prices,timi);
	}
	
	
	ftitles=fopen(tname,"w");			
	fprices=fopen(pname,"w");
	
	if(ftitles==NULL || fprices==NULL){
		printf("Problem allocating memory \n");
		return 1;	
	}
	
	save('t',ftitles,titles,N);
	save('p',fprices,prices,M);

	//apothikeusi alagon kai kleisimo arxeiwn
	fflush(ftitles);
	fflush(fprices);
	fclose(file);
	fclose(ftitles);
	fclose(fprices);
	
	//apodesmeusi sinolikis desmeumenis mnimis
	free_memory(titles,prices,tname,pname);

return 0;
}
