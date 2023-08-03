#include <cstdio>
#include <windows.h>
#include <gdiplus.h>
#include <tlhelp32.h>

using namespace Gdiplus;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main(int argc, char *argv[]) {
  WNDCLASSA properties;

  memset(&properties, 0, sizeof(properties));
  properties.lpszClassName = "AddString";
  properties.lpfnWndProc = WindowProc;
  properties.hInstance = GetModuleHandleA(0);
  properties.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
  RegisterClassA(&properties);

  CreateWindowA("AddString", "AddString test",
                 WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                 CW_USEDEFAULT, 800, 600, 0, 0, GetModuleHandleA(0), 0);

  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
  switch (uMsg) {
  case WM_PAINT: {
    struct GdiplusStartupInput gdiplusStartupInput;
    GraphicsPath path;
    ULONG_PTR gdiplusToken;

    gdiplusStartupInput.GdiplusVersion = 1;
    gdiplusStartupInput.DebugEventCallback = NULL;
    gdiplusStartupInput.SuppressBackgroundThread = 0;
    gdiplusStartupInput.SuppressExternalCodecs = 0;

    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HDC hdc = GetDC(hwnd);
    Graphics graphics(hdc);
    Pen pen(Color(255, 255, 255), 10.0f);

    path.AddArc(-136.33f, 20.00f, 786.00f, 786.00f, -105.00f, 30.00f);
    path.AddArc(256.67f, 413.00f, 0.00f, 0.00f, -75.00f, -30.00f);
    path.CloseFigure();

    path.Flatten(NULL, 1.0);

    /*
    path.Reset();
    path.AddBezier(154.950806f, 33.391144f, 221.586075f, 15.536285f, 291.747314f, 15.536285f, 358.382568f, 33.391144f);
    path.AddBezier(256.666809f, 412.999512f, 256.666718f, 412.999481f, 256.666656f, 412.999481f, 256.666565f, 412.999512f);
    path.CloseFigure();
    path.Flatten(NULL, 1.0);
    */

    graphics.DrawPath(&pen, &path);
    ReleaseDC(hwnd, hdc);
    return 0;
  }
  default:
    printf("Other message\n");
    break;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
