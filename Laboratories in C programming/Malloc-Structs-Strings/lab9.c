
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define LINESIZE 100


typedef struct {
	char* pos ; 			 //position word
	int   dis; 			//distance of word
}infoT;




int main(int argc,char *argv[]){
	char  *sentence;
	int i,temp=0;
	char * pch;
	
	
	infoT *words;
	
	sentence=(char *) malloc(LINESIZE*sizeof(char));  	//dinamiki desmeusi mnimis gia to string sentence
	scanf("%s",sentence);								//anagnosi protasis

	
	
	words=(infoT *) malloc((LINESIZE/2)*sizeof(infoT)); //dinamiki desmeusi mnimis gia ton pinaka words

	
	pch = strtok (sentence,"!@#$%^&*");
	
	for(i=0;i<LINESIZE;i++){							//euresi ari8mou mi alfari8mitikon xaraktiron p periexetai sto string
		if(isalpha(sentence[i])){
		}else{
			temp++;
			
		}
	}
		

		
	for(i=0;i<=temp;i++){ 			
		while (pch != NULL){
			words[i].pos=pch;
			words[i].dis=pch-&sentence[0];
			pch = strtok (NULL," !@#$%^&*");
			
		}
	}

	
return 0;
}

