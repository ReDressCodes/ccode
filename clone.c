#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *data;
    int **data0 = malloc(sizeof(int*));
    *data0 = malloc(sizeof(int));
    int **data1 = &data;

    **data0 = 10;

    if (data0) printf("Value %d \n", **data0);

    return 0;
}
