#include "windows.h"
#include "stdio.h"
#include "gdiplus.h"

GpStatus WINGDIPAPI GdipMeasureCharacterRanges(GpGraphics*, GDIPCONST WCHAR*,
    INT, GDIPCONST GpFont*, GDIPCONST RectF*, GDIPCONST GpStringFormat*, INT,
    GpRegion**); // work-around for mingw headers not including this declaration, building with mingw also requires linking against libgdiplus.a from a Wine source tree

int width;
int height;

static void draw_text(GpGraphics *graphics)
{
    static const WCHAR test_string[] = L"test string test string";
    RectF rc = {20,20,width-40,height-40};
    GpStringFormat *format;
    CharacterRange ranges[10] = {{0,1},{1,1}, {2,1},{3,1},{5,1},{10,1}, {12, 1}, {15, 1}, {17, 1}, {22, 1}};
    RectF bounds;
    GpRegion *regions[10];
    GpFontFamily *family;
    GpFont *font;
    GpBrush *brush;
    GpPen *pen;
    int i;

    GdipGetGenericFontFamilySansSerif(&family);

    GdipCreateFont(family, 390, FontStyleRegular, UnitPixel, &font);

    GdipDeleteFontFamily(family);

    GdipCreateStringFormat(StringFormatFlagsLineLimit, LANG_NEUTRAL, &format);

    GdipSetStringFormatMeasurableCharacterRanges(format, 10, ranges);

    for (i=0; i<10; i++)
    {
        GdipCreateRegion(&regions[i]);

        GdipSetEmpty(regions[i]);
    }

    GdipMeasureCharacterRanges(graphics, test_string, -1, font, &rc, format, 10, regions);

    GdipCreateSolidFill(0x80ff0000, (GpSolidFill**)&brush);

    for (i=0; i<10; i++)
    {
        GdipFillRegion(graphics, brush, regions[i]);

        GdipDeleteRegion(regions[i]);
    }

    GdipDeleteBrush(brush);

    GdipMeasureString(graphics, test_string, -1, font, &rc, format, &bounds, NULL, NULL);

    GdipCreatePen1(0xffffff00, 1, UnitPixel, &pen);

    GdipDrawRectangles(graphics, pen, &bounds, 1);

    GdipDeletePen(pen);

    GdipCreateSolidFill(0xff000000, (GpSolidFill**)&brush);

    GdipDrawString(graphics, test_string, -1, font, &rc, format, brush);

    GdipDeleteBrush(brush);

    GdipDeleteStringFormat(format);

    GdipDeleteFont(font);
}

static LRESULT CALLBACK testwindow_wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch(msg)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            GpGraphics *graphics;
            int save;

            BeginPaint(hwnd, &ps);

            save = SaveDC(ps.hdc);

            GdipCreateFromHDC(ps.hdc, &graphics);

            draw_text(graphics);

            RestoreDC(ps.hdc, save);

            GdipDeleteGraphics(graphics);
            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_SIZE:
            width = LOWORD(lparam);
            height = HIWORD(lparam);
            InvalidateRect(hwnd, NULL, TRUE); /* may not be necessary */
            break;
        case WM_LBUTTONDOWN:
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hwnd, msg, wparam, lparam);
}

static void loop(void)
{
    MSG msg;

    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

static void register_testwindow_class(void)
{
    WNDCLASSEXA cls;

    ZeroMemory(&cls, sizeof(cls));
    cls.cbSize = sizeof(cls);
    cls.style = 0;
    cls.lpfnWndProc = testwindow_wndproc;
    cls.hInstance = NULL;
    cls.hCursor = LoadCursor(0, IDC_ARROW);
    cls.hbrBackground = (HBRUSH) COLOR_WINDOW;
    cls.lpszClassName = "testwindow";

    RegisterClassExA(&cls);
}

static HWND create_window(LPSTR title)
{
   register_testwindow_class();
   
   return CreateWindowExA(0, "testwindow", title, WS_OVERLAPPEDWINDOW|WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, NULL);
}
 
int main(int argc, char* argv[])
{
    struct GdiplusStartupInput input;
    ULONG_PTR token;

    input.GdiplusVersion = 1;
    input.DebugEventCallback = NULL;
    input.SuppressBackgroundThread = FALSE;
    input.SuppressExternalCodecs = TRUE;
    GdiplusStartup(&token, &input, NULL);

    create_window(argv[1]);
    
    loop();

    GdiplusShutdown(token);

    return 0;
}
