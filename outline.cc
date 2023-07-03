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

   Pen bluePen(Color(255, 0, 0, 255));
   Pen greenPen(Color(255, 0, 255,  0), 10.0f);

   PointF points[] = {
      PointF(20.0f, 20.0f),
      PointF(160.0f, 100.0f),
      PointF(140.0f, 60.0f),
      PointF(60.0f, 100.0f)};

   GraphicsPath path;
   path.AddClosedCurve(points, 4);

 ///  path.Widen(&greenPen);
   graphics.DrawPath(&bluePen, &path);

   path.Outline();

//   graphics.TranslateTransform(180.0f, 20.0f);
   graphics.DrawPath(&bluePen, &path);
  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return 0;
}
