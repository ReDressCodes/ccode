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
    WCHAR string[] = L"Kontakt";
    Font myFont(L"Arial", 50);
    RectF layoutRect(100.0f, 100.0f, 200.0f, 400.0f);
    RectF boundingBox;
    int linesfilled = 0;
    StringFormat format;
    struct GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;

    gdiplusStartupInput.GdiplusVersion = 1;
    gdiplusStartupInput.DebugEventCallback = NULL;
    gdiplusStartupInput.SuppressBackgroundThread = 0;
    gdiplusStartupInput.SuppressExternalCodecs = 0;

    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HDC hdc = GetDC(hwnd);

    SetMapMode( hdc, MM_ISOTROPIC);
    SetWindowExtEx(hdc, 800, 600, NULL);
    SetViewportExtEx(hdc, 400, 300, NULL);

    Graphics graphics(hdc);
    //format.SetAlignment(0);
    //format.SetLineAlignment(1);
    //format.SetHotkeyPrefix(0);
    //format.SetFormatFlags(0x3000);
    SolidBrush yellowBrush(Color(255, 255, 255, 0));

    graphics.MeasureString(string, -1, &myFont, layoutRect, &format,
                           &boundingBox, NULL, &linesfilled);

    Pen mypen(Color::Black, 3);
    printf(" %f %f %f %f, linesfilled : %d \n", boundingBox.X, boundingBox.Y,
           boundingBox.Width, boundingBox.Height, linesfilled);

    LOGFONTW lfw;
    myFont.GetLogFontW(&graphics, &lfw);
    printf("lf.lfHeight : %ld \n", lfw.lfHeight);

    graphics.DrawString(string, -1, &myFont, boundingBox, &format, &yellowBrush);
    ReleaseDC(hwnd, hdc);
    return 0;
  }
  default:
    printf("Other message\n");
    break;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
