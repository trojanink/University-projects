#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	const double MAX_NUMBER = 10.00;
	const double ERROR_MARGIN = 0.2;
	double secret, guess;
  
	srand(time(NULL));
	secret = (rand() / ((double)RAND_MAX+1)) * MAX_NUMBER;

	while(1) {
		printf("Enter positive number < 10: ");
		scanf("%lf", &guess);
		if (guess - secret >= ERROR_MARGIN) {
			printf("Try smaller\n");
		}
		else if (secret - guess >= ERROR_MARGIN) {
			printf("Try larger\n");
		}
		else {
			break;
		}
	}	
	printf("Congratulations! You found it.\n");
 
	return 0;
} 
