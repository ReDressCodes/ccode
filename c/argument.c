#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *data1 = malloc(sizeof(int));
    int *data = malloc(sizeof(int));

    int and_test = 46 & 0xf;

    int array[3][3][3] = {{1, 2, 4, 5}, {2, 1}};

    char str[3] = {'a','b','c'};

    strlen(str);
    
    printf(" %d\n", and_test);

    if (!(data1 && data)) printf("Hello, World!");

    return 0;
}
