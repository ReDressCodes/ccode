#include <stdio.h>

static int fs_name(unsigned int index)
{
	for (int i = index +  100; i > 0; i--, index--)
	{
		printf("index value : %d \n", index);
	}

}

int main(int argc, char *argv[])
{
	unsigned int index = 10;

	fs_name(index);

	return 0;
}
