#include <stdio.h>

void populatePointer(void **data)
{
	if (!data)
	{
		printf("Valid pointer \n");
	}
	else
	{
		printf("Invalid pointer \n");
	}
}

int main(int argc, char *argv[])
{
	void **to_test;

	populatePointer(to_test);

	return 0;
}
