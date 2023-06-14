#include <stdio.h>

typedef struct strval
{
	char *value;
	int length;
	int start;
} strval;

typedef struct parse_context
{
	strval current;
	strval next;
} ctx;

bool is_space(char c)
{
	return c == ' ' || c == '\t' || c == '\v' || c == '\r';
}

int main(int argc, char *argv[])
{
	char *str = "The quick brown fox jumps over the lazy dog";

	char *to_sort = malloc(strlen(str) + 1);

	strcpy(to_sort, str);

	printf("%s \n", to_sort);

	return 0;
}
