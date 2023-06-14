#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(const char *left, char *right)
{
	char *to_change = right;
	const char *reversed = left;
	size_t len = strlen(reversed);

	reversed = reversed + (len - 1);
	while (len)
	{
		*to_change = *reversed;

		to_change++;
		reversed--;
		len--;
	}

	*to_change = '\0';
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s "<string>" \n", argv[0]);
		return 1;
	}

	char *reversed = argv[1];
	char *normal = malloc(strlen(reversed) + 1);

	reverse(reversed, normal);

	printf("%s \n", normal);

	return 0;
}
