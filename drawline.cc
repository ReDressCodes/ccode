#include <stdio.h>
#include <windows.h>
#include <gdiplus.h>

using namespace Gdiplus;

void check_fallback(FontFamily *family)
{
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

  path.AddLine(PointF(-20.f, 175.f), PointF(300.f, 175.f));
  path.AddLine(PointF(80.f, 175.f), PointF(40.f, 175.f));
  path.AddLine(PointF(30.f, 75.f), PointF(250.f, 175.f));
  path.AddLine(PointF(50.f, 50.f), PointF(1000.f, 1000.f));

  Pen pen(Color(255, 0, 0, 0), 8);
  pen.SetStartCap(LineCapArrowAnchor);
  pen.SetEndCap(LineCapRoundAnchor);
  graphics.DrawPath(&pen, &path);

  /*
  FontFamily fontFamily(L"Times New Roman");

 //  check_fallback(&fontFamily);

  path.AddString(
     L"Hello World",
     -1,                 // NULL-terminated string
     &fontFamily,
     FontStyleRegular,
     48,
     PointF(50.0f, 50.0f),
     NULL);

  Pen pen(Color(255, 255, 0, 0));
  graphics.DrawPath(&pen, &path);

  */
  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return 0;
}
