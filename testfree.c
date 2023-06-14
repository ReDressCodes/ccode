#include <stdio.h>
#include <stdlib.h>

struct data
{
	int **value;
	int status;
};

int main(int argc, char *argv[])
{
	int *local = NULL;

	struct data *testvalue;

	if (local)
		printf("Pointer value valid \n");
	else
		printf("Pointer value invalid \n");

	testvalue = malloc(sizeof(struct data));
	testvalue->value = &local;
	*(testvalue->value) = malloc(sizeof(int));

	//free(testvalue);
	testvalue->value = NULL;

	if (local)
		printf("Pointer value valid \n");
	else
		printf("Pointer value invalid \n");

	return 0;
}
