#include<stdio.h>
#define BASIC_INCOME 20000
#define BASIC_TAX_FACTOR 0.22
#define UP_TAX_FACTOR 0.35
#define KID_DISCOUNT 0.01
#define TAX_DISCOUNT 0.005

int main (int argc, char *argv[]) {
	double income , tax;
	char kids_char , tax_char;
	
	
	printf("Income (Euro): ");
	scanf("%lf" , &income);
	printf("Any kids? (y/n): ");
	scanf(" %c" , &kids_char);
	
	printf("Paid tax for last year? (y/n): ");
	scanf(" %c" , &tax_char);
	
	if(income <=BASIC_INCOME) {
	
		if((kids_char == 'y') && (tax_char == 'y')) {
			tax = income * (BASIC_TAX_FACTOR - KID_DISCOUNT - TAX_DISCOUNT);
		}
		if((kids_char == 'n') && (tax_char =='y')) {
			tax = income * (BASIC_TAX_FACTOR - KID_DISCOUNT);
		}
		if((kids_char == 'y') && (tax_char == 'n')) {
			tax = income * (BASIC_TAX_FACTOR - TAX_DISCOUNT);
		}
		if((kids_char == 'n') && (tax_char == 'n')) {
			tax = income * BASIC_TAX_FACTOR;
		}
	}
	else {
		if((kids_char == 'y') && (tax_char == 'y')) {
			tax = (((income-BASIC_INCOME) * (UP_TAX_FACTOR - KID_DISCOUNT - TAX_DISCOUNT)) + (BASIC_INCOME * (BASIC_TAX_FACTOR -KID_DISCOUNT - TAX_DISCOUNT)));
		}
		if((tax_char == 'n') && (kids_char =='y')) {
			tax = (((income-BASIC_INCOME) * (UP_TAX_FACTOR - KID_DISCOUNT)) + (BASIC_INCOME * (BASIC_TAX_FACTOR - KID_DISCOUNT)));
		}
		if((tax_char == 'y') && (kids_char == 'n')) {
			tax = (((income-BASIC_INCOME) * (UP_TAX_FACTOR - TAX_DISCOUNT)) + (BASIC_INCOME * (BASIC_TAX_FACTOR - TAX_DISCOUNT)));
		}
		if((tax_char == 'n') && (kids_char == 'n')) {
			tax = (((income - BASIC_INCOME) * UP_TAX_FACTOR ) + (BASIC_INCOME * BASIC_TAX_FACTOR));
		}
	}
		printf("\n");
		printf("Income: %.2lf\n" , income);
		printf("Tax: %.2lf\n" , tax);
	return 0;
}
