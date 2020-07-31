#include<stdio.h>
#define DISCOUNT 0.1
#define INCREMENT 0.25

int main(int argc , char* argv[]) {
	double base_price ,discount_increment , total_price;
	int value;
	
	printf("Base price: ");
	scanf("%lf" , &base_price);
	
	printf("+/- ");
	scanf("%d" , &value);
	
	discount_increment = (value%2==0) ? (base_price * INCREMENT) : (- base_price * DISCOUNT);
	
	total_price = base_price + discount_increment;
	
	printf("\n");
	printf("Base price: %.2lf\n" , base_price);
	printf("Mod amount: %.2lf\n" , discount_increment);
	printf("Final price: %.2lf\n" , total_price);
	
	return(0);
}
	
	