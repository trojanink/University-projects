#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

int countones(char *string){
  
  if (*string=='\0') {
    return 0;
  }
  
  if (*string=='1')  {
    return 1+countones(string+1);
  }else {
    return countones(string+1);
  }
}




int main (int argc, char *argv[]) {
	
	char *string;
	 int assoi;
	string = (char *)malloc(sizeof(char)*SIZE);
	if (!string) {
		printf("Error in memory allocation of string. Exiting...\n");
		return 1;
	}
	printf("Enter a string of 1s and 0s: ");
	fgets(string, SIZE-1, stdin);  	// xrisimopoioume fgets kai oxi scanf gia na 
	*strchr(string, '\n')='\0';		// mporoume eukola na diabasoume kai keno string.
	
	
	assoi=countones(string); 
	
	printf("assoi: %d\n", assoi);
	
  
	return 0;
}
