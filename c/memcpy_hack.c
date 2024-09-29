#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
	char data[1000];
};

void changepointer(char **pointer)
{
	*pointer = NULL;
}

int main(int argc, char *argv[])
{
	char *to_copy = "This the string \n";
	struct data mydata;
	char **copy;
	struct data *mypointer = &mydata;

	memset(mypointer, 0, sizeof(struct data));

	&mypointer->data = NULL;

	memcpy(mypointer->data, to_copy, strlen(to_copy));

	printf(" %s \n", mypointer->data);

	return 0;
}
