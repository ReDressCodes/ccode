#include <stdio.h>

int main(int argc, char *argv)
{
     int flags = 0x1000;
     int mask = 0x2000;

         printf("value %x\n", flags | mask);

     return 0;
}
