#include <stdio.h>

struct data
{
    char *dptr;
    char *name;
};

static struct data datanull;

int main(int argc, char *argv[])
{
    if (datanull.dptr) printf("Hello, World\n");

    return 0;
}
