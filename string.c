#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strcat( char *dst, const char *src )
{
    char *d = dst;
    while (*dst) dst++;
    while ((*dst++ = *src++));
    return dst;
}

int main()
{
	const char to_add[] = {'I', 'S', '\0'};

	char *data = malloc(100);

	strcpy(data, "THIS");

	printf("%s \n", data);

	strcat(data, to_add);

	printf("%s \n", data);

	return 0;
}
