#include <stdio.h>
#include <wchar.h>

int main(int argc, char *argv[])
{
     wchar_t *string = L"m\4284\e000\3f5a\9e40\429d\c000\3ee7\0c00\c1ad\0c00\41ad\8000\3fd4";

     wprintf(L" %ls \n", string);

     return 0;
}
