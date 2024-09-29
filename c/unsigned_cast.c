#include <stdio.h>
#include <stdlib.h>

#define MAX_ERRNO 4095

#define IS_ERR_VALUE(x) (x) >= (unsigned long)-MAX_ERRNO

static inline long IS_ERR(const void *ptr)
{
        return IS_ERR_VALUE((unsigned long) ptr);
}

int main(int argc, char *argv)
{
        if (IS_ERR(NULL))
                printf("Error \n");
        else
                printf("No error \n");

        return 0;
}
