#include<stdio.h>
int main (int argc, char *argv[]) {
	int integer1 , integer2  , result;
	char ops;
	
	printf("Enter expression: ");
	scanf("%d%c%d", &integer1,&ops,&integer2);
	
	if(ops == '+') {
		result = integer1 + integer2;
	}
	if(ops == '-') {
		result = integer1 - integer2;
	}
	if(ops == '*') {
		result = integer1 * integer2;
	}
	if(ops == '/') {
		if(integer2 == 0) {
			printf("Division by zero.\n");
			return 1;
		}
		result = integer1 / integer2;
	}
	if(ops != '+' && ops != '-' && ops != '*' && ops != '/') {
		printf("Invalid selection.\n");
		return 1;
	}
	printf("%d\n" , result);
	
	return 0;
}
