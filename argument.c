#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *data1 = malloc(sizeof(int));
    int *data = malloc(sizeof(int));

    if (!(data1 && data)) printf("Hello, World!");

    return 0;
}
