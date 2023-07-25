#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  char *buffer = "C:\\Users\\ghoul\\Documents\\injectandhook\\inject.dll";
  int procID = 652;

  HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
  if (process == NULL) {
    printf("Error : the specified process couldn’t be found.\n");
  }

  LPVOID addr =
      (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
  if (addr == NULL) {
    printf("Error : the LoadLibraryA function was not found inside kernel32.dll library.\n");
  }

  LPVOID arg = (LPVOID)VirtualAllocEx(process, NULL, strlen(buffer),
                                      MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
  if (arg == NULL) {
    printf("Error : the memory could not be allocated inside the chosen process.\n");
  }

  int n = WriteProcessMemory(process, arg, buffer, strlen(buffer), NULL);
  if (n == 0) {
    printf("Error : there was no bytes written to the process’s address space.\n");
  }

  HANDLE threadID = CreateRemoteThread(
      process, NULL, 0, (LPTHREAD_START_ROUTINE)addr, arg, NULL, NULL);
  if (threadID == NULL) {
    printf("Error : the remote thread could not be created.\n");
  } else {
    printf("Success : the remote thread was successfully created.\n");
  }

  CloseHandle(process);
  getchar();

  return 0;
}
