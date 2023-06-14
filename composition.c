#include <stdio.h>
#include <windows.h>
#include <dwmapi.h>

int main(int argc, char *arvg[])
{
    //BOOL *value = (int *)malloc(sizeof(BOOL));

    BOOL *value;
    HRESULT hr = DwmIsCompositionEnabled(value);

    if (hr == S_OK) 
            printf("Hello, World!, hr : %d, pointer : %p\n", hr, value);
    else
            printf("Didn't quite work, hr : %d \n", hr);

    return 0;
}
