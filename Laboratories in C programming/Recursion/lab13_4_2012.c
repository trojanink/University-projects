#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100

int recStrlen(char *string) {
  
  if (*string=='\0') {
    return 0;
  } else {
    return 1 + recStrlen(string+1);
  }
}



int main (int argc, char *argv[]) {
	
	char *string;
	int mikos;
	

	string = (char *)malloc(sizeof(char)*SIZE);
	if (!string) {
		printf("Error in memory allocation of string. Exiting...\n");
		return 1;
	}
	printf("Enter a string: ");
	fgets(string, SIZE-1, stdin); 	// xrisimopoioume fgets kai oxi scanf gia na 
	*strchr(string, '\n')='\0';  	// mporoume eukola na diabasoume kai keno string.

	 mikos=recStrlen(string);
	 printf("mikos: %d\n", mikos);
	 
	 
	return 0;
}