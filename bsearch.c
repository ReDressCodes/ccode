#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	const int *left = (int *)a;
	const int *right = (int *)b;

	return *left - *right;
}

int main(int argc, char *argv[])
{
	int key = 4;
	int data[] = {1, 2, 3, 5, 6, 7, 8, 9};

	void *result = bsearch(&key, data, sizeof(data) / sizeof(int), sizeof(int), compare);
	
	if (result)
		printf("Found value 4 \n");
	else
		printf("Didn't find value 4\n");
	return 0;
}
