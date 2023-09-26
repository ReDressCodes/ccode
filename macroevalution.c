#include <stdio.h>

#define PAGE_SIZE 4096
#if (65536/PAGE_SIZE + 1) < 16
#define MAX_SKB_FRAGS 16UL
#else
#define MAX_SKB_FRAGS (65536/PAGE_SIZE + 1)
#endif

int main(int argc, char *argv[])
{  
    printf(" %u \n", MAX_SKB_FRAGS);

    return 0;
}
