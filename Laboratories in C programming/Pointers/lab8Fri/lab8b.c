#include <stdio.h>
#include <string.h>

#define SIZE 15
#define WORDLEN 10

void findMinAndSwap (int start, char *words[]);

int main (int argc, char *argv[]) {
	char *words[SIZE] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
						"eta", "theta", "iota", "kappa", "lambda", "mu", "nu",
						"xi", "omicron"};
	int i;

	for (i = 0; i < SIZE; i++)
		findMinAndSwap(i, words);

	for (i = 0; i < SIZE; i++)
		printf("%s\n", words[i]);

	return 0;
}
	
void findMinAndSwap (int start, char *words[]) 
{
	int i;
	int min = strlen(words[start]);
	int min_pos = start;

	for (i = start + 1; i < SIZE; i++)
	{
		if (min > strlen(words[i]))
		{
			min = strlen(words[i]);
			min_pos = i;
		}
	}

	if (start != min_pos)
	{
		char *temp = words[start];
		words[start] = words[min_pos];
		words[min_pos] = temp;
	}


}

