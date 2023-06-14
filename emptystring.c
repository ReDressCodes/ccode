#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *initial = "";

	if (initial)
	{
		printf("String valid. String length : %ld \n", strlen(initial));
	}
	else
	{
		printf("String invalid \n");
	}

	return 0;
}
