#include<stdio.h>
#include<stdlib.h>


void asterakia(int stars, int grammes) {
	int i;
	for (i=0; i<grammes; i++) {
		printf("*");
	}
	printf("\n");
	if (grammes == stars) {
		return ;
	}
	asterakia(stars, grammes+1);
	for (i=0; i<grammes; i++) {
		printf("*");
	}
	printf("\n");
}




int main(int argc,char *argv[]) {
	int stars;
	if (argc<2) {
		printf("dwse ton arithmo apo asteria\n");
		return 0;
	}
	if ((stars=atoi(argv[1]))<=0) {
		printf("dwse 8etiko ari8mo apo asteria\n");
		return 0;
	}
	asterakia(stars,1);
	return 0;
}



	