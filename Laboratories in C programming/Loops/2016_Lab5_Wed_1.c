#include<stdio.h>

int main(int argc , char* argv[]) {
	int i , j , size;
	
	printf("Enter size: ");
	scanf("%d" , &size);
	
	for(i=1; i<=1; i++) {
		for(j=i; j<=size; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	for(i=2; i<=size-1; i++) {
		for(j=1; j<=1; j++) {
			printf("*");
		}
		for(j=2; j<=size-1; j++) {
			if(j==i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		for(j=size; j<=size; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	for(i=size; i<=size; i++) {
		for(j=1; j<=size; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	
	return(0);
}