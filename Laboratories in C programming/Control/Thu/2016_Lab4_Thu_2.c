#include<stdio.h>

int main (int argc, char *argv[]) {
	char user_choice;
	const int coke = 60;
	const int sprite= 65;
	const int water= 75;
	int payment , choice , returnings;
	
	printf("\tC. Coke\n");
	printf("\tD. Diet Coke\n");
	printf("\tS. Sprite\n");
	printf("\tW. Water\n");
	printf("\t==>");

	scanf(" %c" ,&user_choice);
	switch(user_choice) {
		case 'C' :
		case 'D' : 
					printf("Pay %d cents: " , coke);
					choice = coke;
					break;
		case 'S' : 
					printf("Pay %d cents: " , sprite);
					choice = sprite;
					break;
		case 'W' : 
					printf("Pay %d cents: " , water);
					choice = water;
					break;
		default : 
					printf("Invalid selection.\n");
					return 1;
	}
	scanf("%d" , &payment);
	returnings = payment - choice;
	
	if(returnings > 0) {
		printf("Change: %d cents\n" , returnings);
	}
	
	return 0;
}
	
