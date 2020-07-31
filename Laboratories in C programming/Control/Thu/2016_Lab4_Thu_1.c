/* Programma pou upologizei logariasmo ilektrikou reumatos me bash ena timologio */

#include<stdio.h>
#define CHARGE_LIMIT 2000
#define CHARGE_BASIC 0.0681 //eurw/ kwh
#define CHARGEUP2000 0.09227 //eurw/ kwh
#define SALE2 0.15 //ekptwsh gia egkairh plhrwmh 2 teleytaiwn logariasmwn
#define SALE1 0.075 //ekptwsh gia plhrwmh 1/2 teleytaiwn logariasmwn


int main(int argc , char* argv[]) {
	double consumption , charge , discount,final_charge;
	char last_billing_char, second_last_billing_char;
	
	
	printf("Consumption (KWh): ");
	scanf("%lf" , &consumption);
	
	if(consumption <= CHARGE_LIMIT) {
		charge = consumption * CHARGE_BASIC;
	}
	else {
		charge = (CHARGE_LIMIT * CHARGE_BASIC) + ((consumption - CHARGE_LIMIT) * CHARGEUP2000) ;
	}
		

	printf("Last bill on time? (y/n) ");
	scanf(" %c" , &last_billing_char);

	printf("Second to last bill on time? (y/n)\n ");
	scanf(" %c" , &second_last_billing_char);
	
		if((last_billing_char == 'y') && (second_last_billing_char == 'y')) {
			discount = charge * SALE2;
		}
		if(((last_billing_char == 'n') && (second_last_billing_char == 'y')) || ((last_billing_char == 'y') && (second_last_billing_char == 'n'))){
			discount = charge * SALE1;
		}
		if((last_billing_char == 'n') && (second_last_billing_char == 'n')) {
			discount = 0;
		}
	final_charge = charge - discount;
	
	printf("Charge: %.2lf\n" , charge);
	printf("Discount: %.2lf\n" , discount);
	printf("Total: %.2lf\n" , final_charge);
	
	return 0;
}