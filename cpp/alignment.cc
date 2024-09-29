#include <stdio.h>
#include <windows.h>
#include <gdiplus.h>

using namespace Gdiplus;

int main(int argc, char *argv[]) {
  HWND hwnd;
  struct GdiplusStartupInput gdiplusStartupInput;
  ULONG_PTR gdiplusToken;

  WNDCLASSA properties;
  memset(&properties, 0, sizeof(properties));
  properties.lpszClassName = "AddString";
  properties.lpfnWndProc = DefWindowProc;
  properties.hInstance = GetModuleHandleA(0);
  properties.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
  RegisterClassA(&properties);

  hwnd = CreateWindowA("AddString", "AddString test",
                       WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                       CW_USEDEFAULT, 800, 600, 0, 0, GetModuleHandleA(0), 0);

  gdiplusStartupInput.GdiplusVersion = 1;
  gdiplusStartupInput.DebugEventCallback = NULL;
  gdiplusStartupInput.SuppressBackgroundThread = 0;
  gdiplusStartupInput.SuppressExternalCodecs = 0;

  GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

  HDC hdc = GetDC(hwnd);

  Graphics graphics(hdc);
  StringFormat format;
  format.SetFormatFlags(StringFormatFlagsNoClip);
  format.SetAlignment(StringAlignmentNear);
  RectF layoutRect(0.0f, 0.0f, 0.0f, 0.f);
  SolidBrush blackBrush(Color(255, 0, 0, 0));

  Font font(L"Times New Roman", 48);

  graphics.DrawString(
                  L"Hello, World!",
                  -1,
                  &font,
                  layoutRect,
                  &format,
                  &blackBrush);

  Pen mypen(Color::Black, 3);
  graphics.DrawRectangle(&mypen, layoutRect);

  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return 0;
}
