#include <cstdio>
#include <windows.h>
#include <gdiplus.h>
#include <tlhelp32.h>

using namespace Gdiplus;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main(int argc, char *argv[]) {
  HWND hwnd;
  struct GdiplusStartupInput gdiplusStartupInput;
  ULONG_PTR gdiplusToken;

  WNDCLASSA properties;
  memset(&properties, 0, sizeof(properties));
  properties.lpszClassName = "AddString";
  properties.lpfnWndProc = WindowProc;
  properties.hInstance = GetModuleHandleA(0);
  properties.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
  RegisterClassA(&properties);

  hwnd = CreateWindowA("AddString", "AddString test",
                       WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                       CW_USEDEFAULT, 1920, 1080, 0, 0, GetModuleHandleA(0), 0);

  gdiplusStartupInput.GdiplusVersion = 1;
  gdiplusStartupInput.DebugEventCallback = NULL;
  gdiplusStartupInput.SuppressBackgroundThread = 0;
  gdiplusStartupInput.SuppressExternalCodecs = 0;

  GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

  HDC hdc = GetDC(hwnd);

  Graphics graphics(hdc);
  // Create a string.
  WCHAR string[] = L"Kontakt";

  // Initialize arguments.
  Font myFont(L"Arial", 160);
  RectF layoutRect(3168.0f, 3079.0f, 0.0f, 0.0f);
  StringFormat format;
  format.SetAlignment(0);
  format.SetLineAlignment(1);
  format.SetHotkeyPrefix(0);
  format.SetFormatFlags(3000);
  SolidBrush blackBrush(Color(255, 255, 0, 0));

  // Draw string.
  graphics.DrawString(
  string,
  -1,
  &myFont,
  layoutRect,
  &format,
  &blackBrush);

  // Draw layoutRect.
  Pen mypen(Color::Black, 3);
  graphics.DrawRectangle(&mypen, layoutRect);

  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  Sleep(100000);

  return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
  switch (uMsg) {
  case WM_PAINT: {
    printf("WM_PAINT\n");
    break;
  }
  default:
    printf("Other message\n");
    break;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
