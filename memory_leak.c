#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alloc()
{
	int condition = 1;

	int *value = malloc(sizeof(int) * 20);

	if (!value || condition)
	    return;
	else
            free(value);
}

int main(int argc, char *argv)
{

	alloc();

	return 0;
}
