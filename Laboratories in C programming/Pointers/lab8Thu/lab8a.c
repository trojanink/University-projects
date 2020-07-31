#include <stdio.h>

#define SIZE 15

int main (int argc, char *argv[]) 
{
	int numbers[SIZE] = {4, 7, 3, 1, 2, 3, 4, 5, 7, 1, 3, 2, 4, 6, 7};
	int *pnums[SIZE];
	int l = 1;
	int r = SIZE - 1;
	int i = 1;

	pnums[0] = &numbers[0];

	while (i < SIZE)
	{
		if (numbers[i] <= numbers[0])
		{
			pnums[l] = &numbers[i];
			l++;
		}
		else
		{
			pnums[r] = &numbers[i];
			r--;
		}
		i++;
	}

	i = 0;
	while (i < SIZE)
	{
		printf("%d ", *pnums[i]);
		i++;
	}
	printf("\n");

	return 0;
}
