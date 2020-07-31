#include<stdio.h>
#define DISCOUNT_1 0.15
#define DISCOUNT_2 0.35

int main(int argc , char* argv[]) {
	double ticket_price , discount , total_price;
	int tickets;
	
	
	printf("Ticket price: ");
	scanf("%lf" , &ticket_price);
	
	printf("How many: ");
	scanf("%d" , &tickets);
	
	discount = (tickets < 10) ?  DISCOUNT_1*tickets*ticket_price : DISCOUNT_2*tickets*ticket_price;
	
	total_price = (tickets * ticket_price ) -discount;
	
	printf("\n");
	printf("Tickets: %d @ %.2lf\n" , tickets , ticket_price);
	printf("Discount: %.2lf\n" , discount);
	printf("Final price: %.2lf\n" , total_price);
	
	return(0);
}
	