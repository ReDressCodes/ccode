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
int end = 1000; // 有多少个数据
int mod = 100;  // 指示多少个数一列
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
    MessageBox(NULL, _T("我猜测是空间不足了"), _T("注意这里有一个问题"), NULL);

    return 1;
  }

  hInst = hInstance;

  HWND hWnd =
      CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                   CW_USEDEFAULT, 517, 618, NULL, NULL, hInstance, NULL);

  if (!hWnd) {
    MessageBox(NULL, _T("只能说是一个窗口创建失败的大动作！"),
               _T("注意这里有一个问题"), NULL);

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
  HFONT hFont; //字体句柄
  HGDIOBJ oldFont;
  HFONT hFont1;
  HFONT hFont2;
  PAINTSTRUCT ps;
  TEXTMETRIC tm;

  WCHAR lpszTx1[] = L"微软雅黑这么大"; // MiSans
  WCHAR lpszTx2[] = L":  ";
  WCHAR lpszTx3[] = L"蓝色大号斜体并带有下划线！";
  WCHAR lpszTx4[] =
      L"OSOSOS启用多帐号登录后，你的号码将被设置成记住密码。"; // Noto
  WCHAR lpszTx6[] = {0x1c, 0xd83c, 0xdf4a, 0};                 // Noto
  WCHAR lpszTx7[] = {0xd83c, 0xdf4a, 0};                       // Noto
  WCHAR lpszTx5[] = L"aaaaaaaABCDa我bcd";

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

    hFont = CreateFont(-20, 0,  //高度20, 宽取0表示由系统选择最佳值
                       0, 0,    //文本倾斜，与字体倾斜都为0
                       400,     //粗体
                       0, 0, 0, //非斜体，无下划线，无中划线
                       0,       //字符集
                       0, 0x40,
                       0, //一系列的默认值
                       0x36,
                       L"Noto Sans CJK SC" //字体名称
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
    GetTextExtentPoint32(hdc, lpszTx6, wcslen(lpszTx6), &size); //计算高宽
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
    GetTextExtentPoint32(hdc, lpszTx7, wcslen(lpszTx7), &size); //计算高宽
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
