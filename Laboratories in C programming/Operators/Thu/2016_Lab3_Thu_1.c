#include<stdio.h>
#include<math.h>
#define PI 3.14159
int main(int argc , char* argv[]) {
	double radius , height ,  area , volume;
	
	
	printf("Radius: ");
	scanf("%lf" , &radius);
	
	printf("Height: ");
	scanf("%lf" , &height);
	
	area = PI * radius * (radius + sqrt( pow(radius , 2) + pow(height , 2)) );
	volume = ((double)1/3 * PI * pow(radius , 2) * height);
	
	printf("\n");
	printf("Area: %.3lf, Volume: %.3lf\n" , area , volume);

	return(0);
}