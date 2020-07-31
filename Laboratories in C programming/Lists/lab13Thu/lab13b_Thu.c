#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

int countOnes(char* s)
{
	if (s[0] != '\0')
	{ // an de ftasame sto telos sunexizoume tin anadromi 
		return (s[0] == '1' ? 1 : 0) + countOnes(s + 1);
	}

	return 0;
}

int main (int argc, char *argv[]) {
	
	char *string;

	string = (char *)malloc(sizeof(char)*SIZE);
	if (!string) {
		printf("Error in memory allocation of string. Exiting...\n");
		return 1;
	}
	printf("Enter a string of 1s and 0s: ");
	fgets(string, SIZE-1, stdin);  	// xrisimopoioume fgets kai oxi scanf gia na 
	*strchr(string, '\n')='\0';		// mporoume eukola na diabasoume kai keno string.

	printf("There are %d 1s in \"%s\"\n", countOnes(string), string);
	free(string);
	return 0;
}

	
	
