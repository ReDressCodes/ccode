#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//TODO - qsort
//
static int array[] = {7, 5, 0, 8, 2, 5, 7, 9, 1, 3, 9, 5, 4, 2, 0, 6, 8, 3, 5, 7};

static void array_print(int *p, int elements)
{
	printf("All elements: ");

	for(int i = 0; i < elements; i++) 
	{
		printf(" %d", p[i]);

		if (i != elements - 1) printf(",");
	}

	printf("\n");
}

/* 
 * apparently, they refer to this as insertion sort 
 */
static void insertion_sort(int *p, int elements)
{
	for (int i = 0; i < elements; i++){
		for (int j = 0; j < elements; j++) {
			if (p[i] < p[j]) {
				int tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}
int main(int argc, char *argv[])
{

	array_print(array, sizeof(array)/sizeof(array[0]));

	insertion_sort(array, sizeof(array)/sizeof(array[0]));

	array_print(array, sizeof(array)/ sizeof(array[0]));

	return 0;
}
