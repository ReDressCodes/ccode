#include <stdio.h>

int main(int argc, char *argv[])
{
	int low = 0xD800;
	int high = 0xDC00;

	int code_point = low + high;

	printf(" %lx \n", code_point);

	return 0;
}
