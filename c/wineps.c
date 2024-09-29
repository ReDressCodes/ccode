#include <stdio.h>
#include <stdint.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    WCHAR data[] = L"wineps";
    char *data1 = (char *)data;

    printf(" %s", data1);

    return 0;
}
