#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FMTLEN	8
#define WORDLEN 100

char* getPart(char* src, char* start, char*  end)
{
	int part_len = end - start;

	char* part = (char*) malloc((part_len + 1) * sizeof(char)); // +1 for '\0'

	if (part_len < 0 || !part)
	{
		return NULL;
	}

	return strncpy(part, start, part_len);
}

int main (int argc, char *argv[]) 
{
	char fmt[FMTLEN];
	char* delim = (char*) malloc((1 + 1) * sizeof(char)); // +1 for '\0'
	char* s = (char*) malloc((WORDLEN + 1) * sizeof(char)); // +1 for '\0'
	char* part = NULL;
	char* start;

	if (!s || !delim)
	{
		printf("malloc() error!!");

		return -1;
	}

	sprintf(fmt, "%%%ds", WORDLEN);

	printf("Enter word: ");
	scanf(fmt, s);
	
	printf("Enter delimiter: ");
	scanf("%1s", delim);

	start = strchr(s, delim[0]) + 1; // exclude start
	part = getPart(s, start, strchr(start, delim[0]));

	if (part)
	{
		printf("%s\n", part);
		free(part);
	}
	else
	{
		printf("No word\n");
	}
	free(delim);
	free(s);


	return 0;
}

