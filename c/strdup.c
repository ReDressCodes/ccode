#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *strndupA(const char *str,  int len)
{
	char *ret;
	size_t size;

	if (!str)
		return NULL;

	if (len == -1)
		len = strlen(str);

	size = (len + 1) * sizeof(char);
	ret = malloc(len + 1);

	if (ret)
	{
		memcpy(ret, str, size);
		//ret[len] = 0;
	}

	return ret;
}


int main(int argc, char *argv[])
{
	char *copied = strndupA("This is trash", 5);

	printf(" %s \n", copied);

	return 0;
}
