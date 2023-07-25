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
                       CW_USEDEFAULT, 800, 600, 0, 0, GetModuleHandleA(0), 0);

  gdiplusStartupInput.GdiplusVersion = 1;
  gdiplusStartupInput.DebugEventCallback = NULL;
  gdiplusStartupInput.SuppressBackgroundThread = 0;
  gdiplusStartupInput.SuppressExternalCodecs = 0;

  GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

  HDC hdc = GetDC(hwnd);

  SetMapMode( hdc, MM_ISOTROPIC);
  SetWindowExtEx(hdc, 200, 200, NULL);
  SetViewportExtEx(hdc, 100, 100, NULL);
  SetViewportOrgEx(hdc, 200, 200, NULL);
  // Draw string.
  //xform.eM11 = 0.5;
  //xform.eM22 = 0.5;
  //xform.eDx = 100.0;
  //xform.eDy = 100.0;

  //SetGraphicsMode(hdc, GM_ADVANCED);
  //BOOL status = SetWorldTransform(hdc, &xform);

  Graphics graphics(hdc);

  // Create a string.
  XFORM xform = { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0 };
  WCHAR string[] = L"Kontakt";

  // Initialize arguments.
  Font myFont(L"Arial", 50);
  RectF layoutRect(0.0f, 0.0f, 200.0f, 200.0f);
  RectF boundingBox;
  StringFormat format;
  format.SetAlignment(0);
  format.SetLineAlignment(1);
  format.SetHotkeyPrefix(0);
  format.SetFormatFlags(3000);
  SolidBrush blackBrush(Color(255, 255, 255, 0));


  /*
  if (status == 0) 
      printf("Fail\n");
  else 
      printf("Success\n");
      */


  //graphics.RotateTransform(45);
  graphics.MeasureString(
  string,
  -1,
  &myFont,
  layoutRect,
  &format,
  &boundingBox,
  NULL,
  NULL);

  // Draw layoutRect.
  Pen mypen(Color::Black, 3);
  //graphics.DrawRectangle(&mypen, layoutRect);

  printf(" %f %f %f %f\n", boundingBox.X, boundingBox.Y, boundingBox.Width, boundingBox.Height);

  graphics.DrawString(string, -1, &myFont, boundingBox, &format, &blackBrush);
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
