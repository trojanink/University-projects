/* Program that calculates a power bill using the following pricing information:
 * 0-2000 KWh ==> 0.0681 euros/KWh
 * >2000 ==> 0.09227 euros/KWh   
 * and applying discounts based on credit history
 *
 * Date: Oct. 10, 2016
 * Author: V. Doufexi
 */

#include<stdio.h>

int main (int argc, char *argv[]) {
	
	const int LIMIT = 2000;  
	const double LOW_PRICE = 0.0681, HIGH_PRICE = 0.09227;
	const double LOW_DISCOUNT = 7.5/100, HIGH_DISCOUNT = 15.0/100; /* discount rates */
	int consumption;
	char period1_paid, period2_paid;
	double init_charge, discount, final_charge;

	printf("Consumption (KWh): ");
	scanf("%d", &consumption);
	printf("Last bill on time? (y/n) ");
	scanf(" %c", &period1_paid);
	printf("Second to last bill on time? (y/n) ");
	scanf(" %c", &period2_paid);

	if (consumption <= LIMIT) {
		init_charge = consumption * LOW_PRICE;
	}
	else {
		init_charge = LIMIT * LOW_PRICE + (consumption - LIMIT) * HIGH_PRICE;
	}

	if (period1_paid == 'y' && period2_paid == 'y') {
		discount = init_charge * HIGH_DISCOUNT;
	}
	else if (period1_paid == 'y' || period2_paid == 'y') {
		discount = init_charge * LOW_DISCOUNT;
	}
	else  {
		discount = 0;
	}

	final_charge = init_charge - discount;
	
	printf("\nCharge: %.2lf\n", init_charge);
	printf("Discount: %.2lf\n", discount);
	printf("Total: %.2lf\n", final_charge);
	
	return 0;
}
