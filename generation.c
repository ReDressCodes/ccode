#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	printf(" %lu\n", ~((uint64_t)0) + 20UL);

	for (uint64_t i = 0; i < UINT64_MAX; i++)
		;

	return 0;
}
