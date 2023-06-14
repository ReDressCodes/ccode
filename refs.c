#include <stdio.h>

int main(int argc, char *argv[])
{
	int data = 24;

	int after = --data;

	printf(" Value after decrement %d \n", after);

	if (!after)
		printf("Bullshit \n");

	return 0;
}
