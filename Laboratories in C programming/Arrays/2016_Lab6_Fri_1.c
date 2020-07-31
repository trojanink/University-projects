#include<stdio.h>
#define SIZE 4

int main(int argc, char* argv[]) {
	int numbers[SIZE], below_numbers[SIZE];
	int i , sum=0 , number;
	double average;
	int counter=-1;
	
	for(i=0;i<SIZE;i++) {
		numbers[i] = 0;
		below_numbers[i] = 0;
	}
	
	for(i=0;i<SIZE;i++) {
		printf("Enter number: ");
		scanf("%d" , &number);
		if(number > 0) {
			numbers[i] = number;
		}
		else {
			break;
		}
	}
	
	for(i=0;i<SIZE;i++) {
		sum = sum + numbers[i];
	}
	average = (double)sum / i;

	for(i=0;i<SIZE;i++) {
		if(average > numbers[i]) {
			below_numbers[i] = numbers[i];
			counter = i;
		}
	}

	printf("%d" , counter);
	printf("Average %.2lf Numbers below average " , average);
	for(i=0;i<=counter;i++) {
		printf(" %d" , below_numbers[i] );
	}
	printf("\n");
	return (0);
}
	
	