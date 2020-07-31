#include<stdio.h>
#include<string.h>
#define SIZE 11 /* with character backslash_zero */

int main(int argc , char* argv[]) {
	int num_strings;
	char formatstring[13];
	char string[SIZE];
	char max_len[SIZE];
	char max_alpha[SIZE];
	int i;

	strcpy(max_len , " ");
	strcpy(max_alpha , " ");
	sprintf(formatstring , "%%%ds" , SIZE-1);
	printf("Enter number: ");
	scanf("%d" , &num_strings);
	
	for(i=0; i<num_strings; i++) {
		scanf(formatstring , string);
		printf("\n");
		if(strlen(max_len) <= strlen(string)) {
			strcpy(max_len , string);
		}
		else {
			strcpy(max_len , max_len);
		}
		if(strcmp(max_alpha , string) <=  0) {
			strcpy(max_alpha , string);
		}
		else {
			strcpy(max_alpha , max_alpha);
		}
	}
	printf("Max len: %s\n" , max_len);
	printf("Max alpha: %s\n", max_alpha);
			
	return (0);
}
		