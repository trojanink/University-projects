/* Program that implements a simple vending machine transaction 
 * 
 * Date: Oct. 18, 2016
 * Author: V. Doufexi
 */

#include<stdio.h>

int main (int argc, char *argv[]) {
	
	char selection;
	const int COKE_PRICE = 60;  /* prices in cents */
	const int SPRITE_PRICE = 65;
	const int WATER_PRICE = 75;
	int price, payment;

	printf("\tC. Coke\n");
	printf("\tD. Diet Coke\n");
	printf("\tS. Sprite\n");
	printf("\tW. Water\n");
	printf("\t==>");
	scanf(" %c", &selection);

	switch(selection) {
		case 'C': 
		case 'D': price = COKE_PRICE;
				break;
		case 'S': price = SPRITE_PRICE;
				break;
		case 'W': price = WATER_PRICE;
				break;
		default: printf("Invalid selection.\n");
				return 0;
	}

	printf("Pay %d cents: ", price);
	scanf("%d", &payment);
	if (payment - price > 0) {
		printf("Change: %d cents\n", payment-price);
	}
	return 0;
}
	
