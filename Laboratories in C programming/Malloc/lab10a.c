#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getPart(char* src, char* start, char*  end)
{
	int part_len = end - start + 1; // +1 to include end

	char* part = (char*) malloc((part_len + 1) * sizeof(char)); // +1 for '\0'

	if (part_len < 0 || !part)
	{
		return NULL;
	}

	return strncpy(part, start, part_len);
}

int main (int argc, char *argv[]) 
{
	char* s = "four-nine-two";
	char* p = getPart(s, strchr(s, 'n'), strchr(s, 'e'));

	printf("%s\n", p);

	free(p);

	return 0;
}

