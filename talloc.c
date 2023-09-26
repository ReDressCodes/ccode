#include <talloc.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
        unsigned int value = 20, value1 = 15;

        unsigned int diff = value1 - value;

        int unsigned real_value = diff + 10;

        //if (diff > 100U) return -1;

        char src[20], dst[20];

        //memcpy(src, dst, diff);

        printf(" %d \n", real_value);

        return 0;
}
