#include <stdio.h>

int mystrlen(const char *s)
{
	const char *p = s;

	while (*p) p++;

	return p - s;
}

int main(int argc, char *argv[])
{
	char test_string[] = {'T', 'H', 'I', 'S'};

	printf(" %d \n", mystrlen(test_string));

	return 0;
}
