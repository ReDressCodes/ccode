#include <stdio.h>
#include <stdint.h>

#define NO_GENERATION ~((uint64_t)0)

int main(int argc, char *argv[])
{
	uint64_t gen = NO_GENERATION;

	printf("%lu \n", gen);

	return 0;
}
