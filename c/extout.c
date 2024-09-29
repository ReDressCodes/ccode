#include <assert.h>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <usp10.h>
#include <windows.h>
//#include <atlstr.h>

static TCHAR szWindowClass[] = _T("Desktop");

// static TCHAR szTitle[] = _T("This is a title");
static TCHAR szTitle[] = _T("");

HINSTANCE hInst;

int NNMMLL = 0;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int sum_noto = 0, sum_ms = 0;
int end = 1000; // �ж��ٸ�����
int mod = 100;  // ָʾ���ٸ���һ��
double sum_double = 0, sub_double = 0.0000;

wchar_t b[100];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {

  WNDCLASSEX wcex;

  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
  wcex.lpszMenuName = NULL;
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

  if (!RegisterClassEx(&wcex)) {
    MessageBox(NULL, _T("�Ҳ²��ǿռ䲻����"), _T("ע��������һ������"), NULL);

    return 1;
  }

  hInst = hInstance;

  HWND hWnd =
      CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                   CW_USEDEFAULT, 517, 618, NULL, NULL, hInstance, NULL);

  if (!hWnd) {
    MessageBox(NULL, _T("ֻ��˵��һ�����ڴ���ʧ�ܵĴ�����"),
               _T("ע��������һ������"), NULL);

    return 1;
  }

  ShowWindow(hWnd, nCmdShow);

  UpdateWindow(hWnd);

  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
  HDC hdc;
  HFONT hFont; //������
  HGDIOBJ oldFont;
  HFONT hFont1;
  HFONT hFont2;
  PAINTSTRUCT ps;
  TEXTMETRIC tm;

  WCHAR lpszTx1[] = L"΢���ź���ô��"; // MiSans
  WCHAR lpszTx2[] = L":  ";
  WCHAR lpszTx3[] = L"��ɫ���б�岢�����»��ߣ�";
  WCHAR lpszTx4[] =
      L"OSOSOS���ö��ʺŵ�¼����ĺ��뽫�����óɼ�ס���롣"; // Noto
  WCHAR lpszTx6[] = {0x1c, 0xd83c, 0xdf4a, 0};                 // Noto
  WCHAR lpszTx7[] = {0xd83c, 0xdf4a, 0};                       // Noto
  WCHAR lpszTx5[] = L"aaaaaaaABCDa��bcd";

  lpszTx5[0] = 0x1;
  lpszTx5[1] = 0x22;
  lpszTx5[2] = 0x3;
  lpszTx5[3] = 0x4;
  lpszTx5[4] = 0x5;
  lpszTx5[5] = 0x6;
  lpszTx5[6] = 0x7;
  lpszTx5[7] = 0x8;
  lpszTx5[8] = 0x22;
  lpszTx5[9] = 0x1C;

  WCHAR buf[16];

  int StartX = 20, StartY = 20;

  int x = StartX, y = StartY, y1 = StartY, y2 = StartY;

  int linex = StartX, liney = StartY;

  int LZC = 0;

  int LZC_NOTE = 0, LZC_MS = 0;

  int xi = 0;
  int yi = 0;

  int temp = 0;
  FILE *fp;
  FILE *fpq;

  int DN[1200];
  int DM[1200];
  DN[0] = end;
  DM[0] = end;
  RECT CRect = {0, 0, 1000, 10000};

  int num;
  int lenn;

  SIZE size;

  CString str;

  switch (iMsg) {

  case WM_PAINT:

    assert(0);
    assert(1);

    hdc = BeginPaint(hWnd, &ps);

    hFont = CreateFont(-20, 0,  //�߶�20, ��ȡ0��ʾ��ϵͳѡ�����ֵ
                       0, 0,    //�ı���б����������б��Ϊ0
                       400,     //����
                       0, 0, 0, //��б�壬���»��ߣ����л���
                       0,       //�ַ���
                       0, 0x40,
                       0, //һϵ�е�Ĭ��ֵ
                       0x36,
                       L"Noto Sans CJK SC" //��������
    );
    SelectObject(hdc, hFont);

    TextOut(hdc, x, y, lpszTx6, lstrlen(lpszTx6));
    ExtTextOutW(hdc, x, y + 100, ETO_CLIPPED, &CRect, lpszTx6, wcslen(lpszTx6),
                0);

    x += 100;
    NNMMLL = lstrlen(lpszTx6);
    str.Format(_T("%d"), NNMMLL);
    TextOut(hdc, x, y, str, str.GetLength());

    x += 50;
    GetTextExtentPoint32(hdc, lpszTx6, wcslen(lpszTx6), &size); //����߿�
    NNMMLL = size.cx;
    str.Format(_T("%d"), NNMMLL);
    TextOut(hdc, x, y, str, str.GetLength());

    x += 50;
    TextOut(hdc, x, y, lpszTx7, wcslen(lpszTx7));

    x += 50;
    NNMMLL = wcslen(lpszTx7);
    str.Format(_T("%d"), NNMMLL);

    TextOut(hdc, x, y, str, str.GetLength());

    x += 50;
    GetTextExtentPoint32(hdc, lpszTx7, wcslen(lpszTx7), &size); //����߿�
    NNMMLL = size.cx;
    str.Format(_T("%d"), NNMMLL);
    TextOut(hdc, x, y, str, str.GetLength());

    ExtTextOutW(hdc, x + 50, y + 50, ETO_CLIPPED, &CRect, lpszTx6,
                wcslen(lpszTx6), 0);

    EndPaint(hWnd, &ps);
    DeleteObject(hFont);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, iMsg, wParam, lParam);
  }
  return 0;
}
