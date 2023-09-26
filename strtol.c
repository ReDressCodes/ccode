#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        char *value = "3";
        char *end;

        strtol(value, &end, 0);

        if (!*value || *end) printf("Error processing string \n");

        return 0;
}
