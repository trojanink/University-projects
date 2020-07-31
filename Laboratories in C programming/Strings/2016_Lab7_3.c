#include<stdio.h>
#include<string.h>
#define SIZE 11

int main(int argc , char* argv[]) {
	char substring[SIZE];
	char formatstring[13];
	int middle_len , i , j;
	int num_char_similar = 0;
	int pos=0;
	int palindrome=0;
	
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
	for(i=0 , j=pos-1;i<middle_len && j>=middle_len;i++,j--) { /* Sxolio sto telos tou program gia auto to shmeio */
			if(substring[i] == substring[j]) {
				palindrome++;
			}
	}
	if(pos % 2 == 0) { /*h lexh dld exei artio mikos..prepei na isxuei giati le3eis "twin string" einai se morfh ka8refth */
		if(palindrome == middle_len) { /* in case even px 8 xarakthres gia na einai palindrome arkei 4/4 na einai isoi */
			printf("%s is a palindrome.\n" , substring);
		}
		else {
			printf("%s is not a palindrome.\n" , substring);
		}
		if(num_char_similar == middle_len) { 
			printf("%s is a twin string.\n" , substring);
		}
		else {
			printf("%s is not a twin string.\n" , substring);
		}
		if(palindrome != middle_len && num_char_similar != middle_len) {
			printf("%s is nothing special.\n" , substring);
		}
	}
	else {
		if(palindrome == middle_len) { /* in case odd px 7 xarakthres gia na einai palindrome arkei 3/3 omoious kai ena diaxwristiko */
			printf("%s is a palindrome.\n" , substring);
		}
		else {
			printf("%s is not a palindrome.\n" , substring);
			printf("%s is nothing special.\n" , substring);
		}
		printf("%s is not a twin string.\n" , substring);
	}
	
	return (0);
}


/* poia diafora exei h for syn8eth opws edw kai h for efwleumenh ..Egw to antilambanomai ws mia sun8eth pra3h gi auto kai meta apo dokimh moy bghke etsi..einai omws etsi sthn pragmatikothta? enw h for for efwleumenh gia ka8e ena stoixeio tou i trexoun ola ta j ..pragma pou dn ginetai parallhla dld na me kanei search mpros pisw tautoxrona */