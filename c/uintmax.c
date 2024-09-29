#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned long value = ~0UL;

	printf(" %ld \n", value / 1024 / 1024 / 1024 / 1024);

	return 0;

}
