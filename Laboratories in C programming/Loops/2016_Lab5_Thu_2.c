#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc , char* argv[]) {
	int counter_of_try;
	int random_int;
	int guess;
	
	srand((int)time(NULL));
	
	random_int = rand()%100 + 1;
	
	counter_of_try = 7;
	
	while(counter_of_try != 0) {
		
		printf("[%d] Enter positive integer <= 100: " , counter_of_try);
		scanf("%d" , &guess);
		
		if(guess == random_int) {
			break;
		}
		counter_of_try --;
		
		if( guess > random_int) {
			printf("Try smaller\n");
		}
		else {
			printf("Try larger\n");
		}
	}

	if(counter_of_try == 0) {
		printf("Sorry , you missed number %d\n" , random_int);
	}
	else {
		printf("Congratulations! You found it.\n");
	}
	
	return (0);
}
		
		