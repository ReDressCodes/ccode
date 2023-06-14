#include <stdio.h>
#include <string.h>

int main(int argc, char argv[])
{
        int arrayA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

        int arrayB[10];
        memset(arrayB, 0, 10 * sizeof(int));

        for (int i = 0; i < 10; i++)
                printf("ArrayA[%d] : %d , ArrayB[%d], %d \n", i, arrayA[i], i, arrayB[i]);

        memcpy(&arrayB[0], &arrayA[0], /*sizeof(arrayA)/sizeof(arrayA[0]) */ 10 * sizeof(int));

        for (int i = 0; i < 10; i++)
                printf("ArrayA[%d] : %d , ArrayB[%d], %d \n", i, arrayA[i], i, arrayB[i]);

        char myname[] = "Pierre de Fermat";
        char copy[100];
        memset(copy, 0, 100);
        /* using memcpy to copy string: */
        //memcpy ( person.name, myname, sizeof(myname) );

        return 0;
}
