#include <stdio.h>

int main(int argc, char *argv[])
{
	/* 0xdc00, 0xd800 */
	int a = 0xf0908080;

	/* 0xdbff, 0xdfff */
	int b = 0x8fbfbf61;

	unsigned long diff = a - b;

	printf(" %#lx.\n", diff);

	int c = 0xc4;
	int d = 0x80;

	printf(" %#x.\n", c + d);

	return 0;
}
