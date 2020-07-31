#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100

int recStrlen(char* s)
{
	if (s[0] != '\0')
	{ // an de ftasame sto telos sunexizoume tin anadromi 
		return 1 + recStrlen(s + 1);
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
	printf("Enter a string: ");
	fgets(string, SIZE-1, stdin); 	// xrisimopoioume fgets kai oxi scanf gia na 
    *strchr(string, '\n')='\0';  	// mporoume eukola na diabasoume kai keno string.

	printf("\"%s\" has length %d\n", string, recStrlen(string));
	free(string);

	return 0;
}

	
	
