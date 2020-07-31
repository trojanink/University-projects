#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

int main(int argc , char* argv[]) {
	int array[SIZE];
	int number , i , curr_distance , max_distance=0, max_i=-1 , num_elements;
	
	for(i=0;i<SIZE;i++) { /* initialize array */
		array[i] = 0;
	}
	for(i=0;i<SIZE;i++) {
		printf("Enter number: ");
		scanf("%d" , &number);
			if(number > 0) {
				array[i] = number;
			}
			if(number <= 0){
				break;
			}
	}
	for(i=0;i<SIZE;i++) {
		printf("%d\n" , array[i]);
	}
	num_elements = i;
	for(i=0;i<num_elements-1;i++) {			
		curr_distance = (abs(array[i]-array[i+1]));
		if (curr_distance > max_distance) {
			max_distance = curr_distance;
			max_i = i;
		}
	}
	printf("Max distance %d at position %d\n" , max_distance ,max_i);
	
	return (0);
}
	
	