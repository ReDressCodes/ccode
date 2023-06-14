#include <stdio.h>

int main(int argc, char *argv[])
{
	int first = 0xdc00;
	int last = 0xdfff;
	int diff = 0x0100 - 0xdc00;

	diff = ((0x0 - 0xd800) * 0x400) + diff;

	printf("Difference : %#x \n", diff);
	printf("Code point is : %#x \n", diff + 0x10000);
	printf("Difference : %#x \n", last - first);
	printf("First : %d \n", first);
	printf("Last : %d \n", last);
	printf("Difference : %d \n", last - first);

	int hexvalue = 0x400;

	printf(" Value in hex : %d \n", hexvalue);

	return 0;
}
