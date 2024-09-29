#include <stdio.h>

int main(int argc, char *argv[])
{
        int data = 20;
        int data0 = 10;

        int value = (data + data0 ) / 0.1 - 20;

        printf(" %d \n", value);

        return 0;
}
