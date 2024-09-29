#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	const char data[20];

	//data += 21; 

	printf("First character : %c, strlen : %ld \n", *data, strlen(data));

	return 0;
}
