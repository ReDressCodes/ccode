#include <handleapi.h>
#include <iphlpapi.h>
#include <iprtrmib.h>
#include <minwindef.h>
#include <processthreadsapi.h>
#include <winerror.h>
#include <winnt.h>
#include <winsock.h>
#include <stdio.h>

#define THREADS 25

DWORD looper(LPVOID lpParameter) {
  DWORD thread = GetCurrentThreadId();
  while (1) {
    PVOID pTcpTable = NULL;
    DWORD pdwSize = 0;
    WINBOOL trying = TRUE;
    while (trying) {
      printf("%0.4x: requesting buffer of size %u to %X\r\n", thread, pdwSize, pTcpTable);
      DWORD result = GetExtendedTcpTable(pTcpTable, &pdwSize, FALSE, AF_INET,
                                         TCP_TABLE_OWNER_PID_ALL, 0);
      switch (result) {
      case NO_ERROR:
        trying = FALSE;
        printf("%0.4x: successfully got tcp table!\r\n", thread);
        break;
      case ERROR_INSUFFICIENT_BUFFER:
        if (pTcpTable != NULL) {
          free(pTcpTable);
        }
        pdwSize *= 2;
        printf("%0.4x: resizing tcp table buffer\r\n", thread);
        pTcpTable = malloc(pdwSize);
        break;
      case ERROR_INVALID_PARAMETER:
        if (pTcpTable != NULL) {
          free(pTcpTable);
        }
        trying = FALSE;
        printf("%0.4x: total fail\r\n", thread);
        return 1;
        break;
      }
    }
  }
  return 0;
}

int main() {
  HANDLE threads[THREADS];
  for (int i = 0; i < THREADS; i++) {
    HANDLE thread = CreateThread(NULL, 0, looper, NULL, 0, NULL);
    threads[i] = thread;
    if (thread == NULL) {
      printf("FAILED TO CREATE THREAD %d\r\n", i);
    }
  }
  WaitForMultipleObjects(THREADS, threads, TRUE, INFINITE);
  for (int i = 0; i < THREADS; i++) {
    CloseHandle(threads[i]);
  }
  return 0;
}

