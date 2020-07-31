#include<stdio.h>
#include<string.h>
#define SIZE 11

int main(int argc , char* argv[]) {
	char substring[SIZE];
	char formatstring[13];
	int middle_len , i;
	int num_char_similar = 0;
	int pos=0;
	
	sprintf(formatstring , "%%%ds" , SIZE-1);
	printf("Enter word: ");
	scanf(formatstring , substring);
	
	pos=  strlen(substring);
	middle_len = strlen(substring) / 2;
	
	for(i=0; i<pos; i++) {
		if(substring[i] == substring[middle_len+ i]) {
				num_char_similar++;
			}
		}
		
	if(pos % 2 == 0) { /*h lexh dld exei artio mikos..prepei na isxuei giati le3eis "twin string" einai se morfh ka8refth */
		if(num_char_similar == middle_len) { 
			printf("%s is a twin string.\n" , substring);
		}
		else {
			printf("%s is not a twin string.\n" , substring);
		}	
	}
	else {
		printf("%s is not a twin string.\n" , substring);
	}
	
	return (0);
}