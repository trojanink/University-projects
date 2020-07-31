#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15
#define WORDLEN 10


int main (int argc, char *argv[]) {
	char words[SIZE][WORDLEN] = {"mu", "nu", "xi", "eta", "beta", "iota", 
								"zeta", "alpha", "gamma", "delta", "theta", 
								"kappa", "lambda", "epsilon", "omicron"};
	char *pwords[SIZE] = {NULL};
	int i = 0;
	int len = -1;
	int j;

	for (j = 0; j < SIZE; j++)
	{
		if (len != strlen(words[j]))
		{
			len = strlen(words[j]);
			pwords[i] = words[j];
			i++;
		}
	}

	for (j = 0; j < SIZE && pwords[j] != NULL; j++)
		printf("pos: %d, len: %d, word: %s\n", (pwords[j] - words[0]) / WORDLEN,
				strlen(pwords[j]), pwords[j]);

	return 0;
}
