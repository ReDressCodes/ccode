#include <stdio.h>
#include <windows.h>
#include <gdiplus.h>

using namespace Gdiplus;

void check_fallback(FontFamily *family) {
  if (family)
    printf("fallback font \n");
  else
    printf("no fallback font \n");
}

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
  GraphicsPath path;

  /*
  path.AddBezier(154.950806f, 33.391144f, 221.586075f, 15.536285f, 291.747314f,
                 15.536285f, 358.382568f, 33.391144f);

  path.AddBezier(256.666809f, 412.999512f, 256.666718f, 412.999481f, 256.666656f,
                 412.999481f, 256.666565f, 412.999512f);

  Pen pen(Color(255, 0, 0, 0), 8);

  path.Flatten(NULL, 10.0f);
  graphics.DrawPath(&pen, &path);
  */
 
  FontFamily fontFamily(L"Times New Roman");

  StringFormat stringFormat;

  path.AddString(
     L"Hello World",
     -1,                 // NULL-terminated string
     &fontFamily,
     FontStyleRegular,
     48,
     PointF(50.0f, 50.0f),
     &stringFormat);


  Pen pen(Color(255, 255, 0, 0), 10.0f);
  Pen pen1(Color(255, 0, 0, 0));
  path.Widen(&pen);
  path.Outline();
  graphics.DrawPath(&pen1, &path);

  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return 0;
}
