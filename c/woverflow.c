#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void setvalue(char *values, int *count)
{
    *count = 50;
    values = malloc(*count);

    for (int i = 0; i < *count; i++)
    {
         *values = 50;
         values++;
    }
}

int main(int argc, char *argv[])
{
    int count;
    char *values;

    setvalue(values, &count);
    char *types = malloc(count);

    memcpy(types, values, count);

    return 0;
}

