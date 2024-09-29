#include <stdio.h>
#include <windows.h>
#include <gdiplus.h>
#include <string>

using namespace Gdiplus;

int main(int argc, char *argv[]) {
  HWND hwnd;
  struct GdiplusStartupInput gdiplusStartupInput;
  ULONG_PTR gdiplusToken;

  WNDCLASSA properties;
  memset(&properties, 0, sizeof(properties));
  properties.lpszClassName = "MeasureString";
  properties.lpfnWndProc = DefWindowProc;
  properties.hInstance = GetModuleHandleA(0);
  properties.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
  RegisterClassA(&properties);

  hwnd = CreateWindowA("MeasureString", "MeasureString",
                       WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                       CW_USEDEFAULT, 1920, 1080, 0, 0, GetModuleHandleA(0), 0);

  gdiplusStartupInput.GdiplusVersion = 1;
  gdiplusStartupInput.DebugEventCallback = NULL;
  gdiplusStartupInput.SuppressBackgroundThread = 0;
  gdiplusStartupInput.SuppressExternalCodecs = 0;

  GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

  HDC hdc = GetDC(hwnd);
  //const WCHAR to_draw[] = {'S', 'p', 'i', 'c', 'e'};
  const WCHAR to_draw[] = L"Spice";

  Graphics graphics(hdc);
  StringFormat stringFormat;
  Font font(L"Arial", 48);
  RectF size;

  stringFormat.SetAlignment(0);
  stringFormat.SetLineAlignment(1);
  stringFormat.SetHotkeyPrefix(0);
  stringFormat.SetFormatFlags(0x3000);

  SolidBrush brush(Color::Black);

  graphics.MeasureString(to_draw, 5, &font, PointF(300.f, 300.f), &size);
  printf(" %f \n", size.Height);
  size.Height = size.Height - 50;
  graphics.DrawString(to_draw, 5, &font, size, &stringFormat, &brush);

  printf("Hello, World\n");
  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return 0;
}
