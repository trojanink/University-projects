#include<stdio.h>
#include<math.h>

int main(int argc , char* argv[]) {
	double a_value , b_value , c_value , root1 , root2;
	double number;
	
	printf("Coefficients:\n");
	
	printf("Quadratic: ");
	scanf("%lf" , &a_value);
	
	printf("Linear: ");
	scanf("%lf" , &b_value);
	
	printf("Constant: ");
	scanf("%lf" , &c_value);
	
	root1 = ((-b_value + sqrt(b_value*b_value - 4*a_value *c_value)) / (2* a_value));
	root2 = ((-b_value - sqrt(pow(b_value, 2) - 4*a_value *c_value)) / (2* a_value));
	
	printf("\n");
	printf("root1 = %.4lf," , root1);
	printf(" root2 = %.4lf\n" , root2);
	
	return(0);
}