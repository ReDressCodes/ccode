#include <stdio.h>
#include <windows.h>
#include <gdiplus.h>

using namespace Gdiplus;

HINSTANCE hinstLib;
char saved_buffer[5];
FARPROC hooked_address;

int __stdcall proxy_function(GpGraphics*, REAL , REAL, GpMatrixOrder);
void reinstall_hook()
{
     VOID *proxy_address;
     DWORD *relative_offset;
     DWORD *hook_address;
     DWORD src;
     DWORD dst;
     CHAR patch[5] = {0};
     FARPROC function_address = NULL;

     function_address = GetProcAddress(hinstLib, "GdipTranslateWorldTransform");

     ReadProcessMemory(GetCurrentProcess(), function_address, saved_buffer, 5, NULL);

     proxy_address  = &proxy_function;
     src = (DWORD) function_address + 5;
     dst = (DWORD) proxy_address;
     relative_offset = (DWORD *)(dst - src);

     memcpy(patch, "\xE9", 1);
     memcpy(patch + 1, &relative_offset, 4);

     WriteProcessMemory(GetCurrentProcess(), (LPVOID)function_address, patch, 5, NULL);
}

int __stdcall proxy_function(GpGraphics *graphics, REAL dx, REAL dy, GpMatrixOrder order)
{
     FILE *file;

     fopen_s(&file, "C:\\Users\\ghoul\\Documents\\injectandhook\\dump.txt", "a+");
     fprintf(file, "X offset : %f, Y offset : %f \n", dx, dy);

     fclose(file);

     WriteProcessMemory(GetCurrentProcess(), (LPVOID)hooked_address, saved_buffer, 5, NULL);

     DllExports::GdipTranslateWorldTransform(graphics, dx, dy, order);

     reinstall_hook();

     return 0;
}

void install_hook()
{
     VOID *proxy_address;
     DWORD *relative_offset;
     DWORD src;
     DWORD dst;
     CHAR patch[5] = {0};
     FARPROC function_address = NULL;

     hinstLib = LoadLibraryA(TEXT("gdiplus.dll"));
     hooked_address = function_address = GetProcAddress(hinstLib, "GdipTranslateWorldTransform");

     ReadProcessMemory(GetCurrentProcess(), function_address, saved_buffer, 5, NULL);

     proxy_address  = &proxy_function;
     src = (DWORD) function_address + 5;
     dst = (DWORD) proxy_address;
     relative_offset = (DWORD *)(dst - src);

     memcpy(patch, "\xE9", 1);
     memcpy(patch + 1, &relative_offset, 4);

     WriteProcessMemory(GetCurrentProcess(), (LPVOID)function_address, patch, 5, NULL);
}

INT APIENTRY DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved) {

  switch (Reason) {
  case DLL_PROCESS_ATTACH:
  {
    FILE *file;

    fopen_s(&file, "temp.txt", "a+");
    fprintf(file, "Dumping");

    fclose(file);
    install_hook();
    break;
  }
  case DLL_PROCESS_DETACH:
    break;
  }

  return TRUE;
}
