#include <stdio.h>
#include <string.h>

typedef struct
{
    int data;
    int value;
} payload;

void modify(payload *payloads)
{
     printf(" modify started \n");
     payload tmp = { 0 };
     //payloads = &tmp;
     payloads++;
     printf(" modify ended \n");
}

int main(int argc, char *argv[])
{
    payload payloada[3] = { { 0, 0}, { 10, 10}, {20, 20} };;
    //memset(payloada, 0, 20 * sizeof(payload));

    modify(&payloada);

    printf(" data : %d, value : %d \n", payloada[2].data, payloada[2].value);

    return 0;
}
