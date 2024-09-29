#include <stdio.h>
#include <stdarg.h>

static float get_argument(int data, ...)
{
    va_list args;
    va_start(args, data);

    float d = va_arg(args, double);

    va_end(args);

    return d;
}

int main(int argc, char *argv[])
{
    float data = get_argument(0.25f, 0.87f);

    printf(" %f \n", data);

    return 0;
}
