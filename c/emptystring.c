#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define streq(a,b) (strcmp((a),(b)) == 0)

#define strstarts(a,b) (strncmp((a),(b),strlen(b)) == 0)

static inline bool strends(const char *a, const char *b)
{
        if (strlen(a) < strlen(b))
                return false;

        return streq(a + strlen(a) - strlen(b), b);
}

int main(int argc, char *argv[])
{
	char *initial = "";
	char *cmp = "This";

	if (strends(initial, "/")) printf("hello\n");

	if (strstr(initial, "//")) printf("world\n");

	if (sscanf(initial, "/local/domain/%5u/%n", 20, 15) != 1)
		printf(" %s \n", initial);

	return 0;
}
