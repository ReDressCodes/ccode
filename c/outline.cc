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
  //HDC hdc = CreateCompatibleDC(NULL);
  HDC memDC = CreateCompatibleDC ( hdc );
  HBITMAP memBM = CreateCompatibleBitmap ( hdc, 400, 300 );
  SelectObject ( memDC, memBM );


  /*
    RectF rect;
    BITMAP structBitmapHeader = {0};
    HGDIOBJ hBitmap = GetCurrentObject(hdc, OBJ_BITMAP);

    GetObjectW(hBitmap, sizeof(BITMAP), &structBitmapHeader);

    printf(" %ld %ld \n", structBitmapHeader.bmWidth, structBitmapHeader.bmHeight);
    */

   Graphics graphics(hdc);
   Pen bluePen(Color(255, 0, 0, 255));
   Pen greenPen(Color(255, 0, 255,  0), 10.0f);
   GraphicsPath path;

   PointF points[] = {
      PointF(20.0f, 20.0f),
      PointF(160.0f, 100.0f),
      PointF(140.0f, 60.0f),
      PointF(60.0f, 100.0f)};

   path.AddClosedCurve(points, 4);

   //path.Widen(&greenPen);
   //graphics.DrawPath(&bluePen, &path);

  graphics.TranslateTransform(180.0f, 20.0f);

   PointF points2[] = {
      PointF(30.0f, 30.0f),
      PointF(170.0f, 110.0f),
      PointF(150.0f, 70.0f),
      PointF(70.0f, 110.0f)};

  path.AddClosedCurve(points2, 4);
  path.Flatten();
  /*
   path.AddBezier(154.950806f, 33.391144f,
                  221.586075f, 15.536285f,
                  291.747314f, 15.536285f,
                  358.382568f, 33.391144f);
   path.AddBezier(256.666809f, 412.999512f,
                  256.666718f, 412.999481f,
                  256.666656f, 412.999481f,
                  256.666565f, 412.999512f);

  graphics.DrawPath(&bluePen, &path);

  GraphicsPath path2;
   path2.AddBezier(154.950806f, 33.391144f,
                  221.586075f, 15.536285f,
                  291.747314f, 15.536285f,
                  358.382568f, 33.391144f);
   path2.AddBezier(256.666809f, 412.999512f,
                  256.666718f, 412.999481f,
                  256.666656f, 412.999481f,
                  256.666565f, 412.999512f);

  graphics.TranslateTransform(150.0f, 150.0f);
  path2.Flatten(NULL, 0.25);

  */
  graphics.DrawPath(&bluePen, &path);

  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return 0;
}
