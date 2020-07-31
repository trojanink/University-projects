#include <stdlib.h> //uparxei mesa #define RANDOM_MAX 
#include <time.h> //gia na ginei initialize h rand function
#include <math.h> //to thelw gia th function fabs
#include <stdio.h>

int main(int argc, char *argv[]) {
	double random_double;
	double guess;
	const double MAX_LIMIT= 10;
	const double DIFF= 0.2;
	
	
	srand(time(NULL)); //initialize srand function of stdlib
	
	random_double = rand()/(RAND_MAX + 1.0) * MAX_LIMIT; //range 0-10 xwris to MAX_LIMIT
	
	while (1) {
	printf("Enter positive number < 10: ");
	scanf("%lf" , &guess);
		
		if( fabs(guess- random_double) <= DIFF) {
			break;
		}
	
		if(guess > random_double) {
			printf("Try smaller\n");
		}
		else {
			printf("Try larger\n");
		}
	}	
	printf("Congratulations! You found it\n");
	printf("%lf" , random_double);
	
	return (0);
	
	}
	