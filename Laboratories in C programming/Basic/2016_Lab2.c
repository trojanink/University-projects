/* Grapse ena programma to opoio diabazei ton kwdiko mias xwras , ton plh8usmo ths se ekatomuria kai thn hmeromhnia ths e8nikis tis eortis kai meta printarei tis plhrofories autes */

#include<stdio.h>

int main(int argc , char* argv[]) {
	
	char code_1, code_2;
	double population;
	int day, month;
	
	
	printf("Country code: ");
	scanf(" %c%c",&code_1 , &code_2);
	
	printf("Pop (m): ");
	scanf("%lf",&population);
	
	printf("National hol: ");
	scanf("%d %d",&day , &month);
	printf("\n");
	
	printf("%c%c has a population of %.2lf million\nand the national holiday is on %d/%d.\n",code_1 , code_2 , population , day , month);
	
	return(0);
	
}
	