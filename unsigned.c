#include <stdio.h>
#include <stdint.h>

int main()
{
    uint16_t data = 80000;

    uint16_t cmp = 200;

    unsigned int value = 20;

    uint16_t a = 40000;
    uint16_t b = 40000;
    uint16_t c = a + b;

    if (a + b > 60000)
        printf(" %u \n", a + data );

    if (data > 2000)
	printf("1 integer overflow %d \n", data);


    a -= data;

    if (data > cmp)
	printf("2 Integer overflow %d \n", a);

    
    printf("1 integer overflow %d \n", a);
    printf("the value of 'a' Integer overflow %u \n", data);

    return 0;
}
