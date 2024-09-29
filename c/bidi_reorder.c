#include <stdio.h>
#include <wchar.h>

int main(int argc, char *argv[])
{
    wchar_t *str = L"\542f\7528\591a\5e10\53f7\767b\5f55\540e\ff0c\4f60\7684\53f7\7801\5c06\88ab\8bbe\7f6e\6210\8bb0\4f4f\5bc6\7801\3002";

    wprintf(L"%s \n", str);

    return 0;
}
