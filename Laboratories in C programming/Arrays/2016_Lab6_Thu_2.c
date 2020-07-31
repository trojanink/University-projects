#include<stdio.h>
#define SIZE 3

int main(int argc , char* argv[]) {
	int array_2D[SIZE][SIZE];
	int i,j, number , count ,all_elements , main_diagonal;
	
	for(i=0; i<SIZE; i++) {
		for(j=0;j<SIZE;j++) {
			array_2D [i][j] = 0;
		}
	}
	
	for(i=0; i<SIZE; i++) {
		for(j=0;j<SIZE;j++) {
			printf("Enter number: ");
			scanf("%d" , &number);
			if(number >=0 ) {
				array_2D[i][j] = number;
			}
			else {
				break;
			}
		}
	}
	for(i=0; i<SIZE; i++) {
		for(j=0;j<SIZE;j++) {
			printf("|%d|\n" , array_2D[i][j]);
		}
	}
	count = 0;
	all_elements = 0;
	main_diagonal = 0;
	for(i=0; i<SIZE; i++) {
		for(j=0;j<SIZE;j++) {
			if(i==j) {
				if(array_2D[i][j] == 0) {
					main_diagonal++;
				}
			}
			if (i>j) {
				all_elements++;
					if(array_2D[i][j] == 0) {
						count++;
					}
			}
		}
	}
	if((count == all_elements) && (main_diagonal ==0 )){
		printf("\nupper triangular matrix");
	}
	else {
		printf("\nNOT upper triangular matrix");
	}
		
	printf("\n");
			
	return (0);
}		