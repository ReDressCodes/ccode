#include <windows.h>
#include <gdiplus.h>
#include <cstdio>

using namespace Gdiplus;

const int UnixPixel = 2;

int main(int argc, char *argv[])
{
    HWND hwnd;
    struct GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Status stat;

    WNDCLASSA properties;
    memset(&properties, 0, sizeof(properties));
    properties.lpszClassName = "AddString";
    properties.style = CS_HREDRAW | CS_VREDRAW;
    properties.lpfnWndProc = DefWindowProcA;
    properties.hInstance = GetModuleHandleA(0);
    properties.hIcon = LoadIconA(0, (LPCSTR)IDI_APPLICATION);
    properties.hCursor = LoadCursorA(0, (LPCSTR)IDC_ARROW);
    properties.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
    RegisterClassA( &properties );

    hwnd = CreateWindowA( "AddString", "AddString test", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                          CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, 0, 0, GetModuleHandleA(0), 0 );

    HDC hdc = GetDC(hwnd);

    Graphics graphics(hdc);

    Pen pen(Color(255, 0, 0, 255), 8);
    stat = pen.SetStartCap(LineCapArrowAnchor);
    stat = pen.SetEndCap(LineCapRoundAnchor);
    stat = graphics.DrawLine(&pen, 20, 175, 300,175);

    MSG Msg;

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
          TranslateMessage(&Msg);
          DispatchMessage(&Msg);
    }

    return 0;
}
