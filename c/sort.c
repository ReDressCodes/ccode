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

typedef int (*compare)(void *a, void *b);

typedef void (*selection_sort)(void *ptr, int elements, size_t element_size, compare fn);

typedef void (*quick_sort)(void *ptr, int elements, size_t element_size, compare fn);

typedef void (*bubble_sort)(void *ptr, int elements, size_t element_size, compare fn);

typedef void (*heap_sort)(void *ptr, int elements, size_t element_size, compare fn);

typedef void (*merge_sort)(void *ptr, int elements, size_t element_size, compare fn);

int main(int argc, char *argv[])
{
	char *str = "The quick brown fox jumps over the lazy dog";

	char *to_sort = malloc(strlen(str) + 1);

	strcpy(to_sort, str);

	printf("%s \n", to_sort);

	return 0;
}
