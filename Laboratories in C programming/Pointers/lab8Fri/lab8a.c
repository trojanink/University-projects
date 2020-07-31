#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

int main(int argc, char *argv[]) {
	int numbers[SIZE] = {1,1,2,2,2,3,5,5,5,6,6,9,9,10,10};
	int *pnums[SIZE] = {NULL};
	int i = 1;
	int num = numbers[0];
	int j;

	pnums[0] = &numbers[0];

	for (j = 1; j < SIZE; j++)
	{
		if (num != numbers[j])
		{
			num = numbers[j];
			pnums[i] = &numbers[j];
			i++;
		}
	}

	for (j = 0; j < SIZE && pnums[j] != NULL; j++)
		printf("pos: %d, val: %d\n", (pnums[j] - numbers), *pnums[j]);


	return 0;
}
	
		
		
