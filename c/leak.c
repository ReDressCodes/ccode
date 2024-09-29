#include <stdio.h>
#include <stdlib.h>

typedef struct data{
	short whatever;
	short value2;
	short value3;
	short value4;
	short value5;
}data;


int main(int argc, char *argv[])
{
	data *This = malloc(sizeof(*This));
	This->whatever = 200;
	This->value2 = 300;
	This->value3 = 100;
	This->value4 = 400;
	This->value5 = 500;

	void *value = *(void**)This;

	printf(" %p \n", value);

	*(void**)This = 0;

	value = *(void**)This;

	printf(" %p \n", value);

	return 0;
}
