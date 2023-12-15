#include <windows.h>
#include <wingdi.h>
#include <gdiplus.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    GLYPHMETRICS gm;
    static const MAT2 identity = { {0,1}, {0,0},{0,0},{0,1} };
    string teststring = "This is a test string";
    LOGFONTW lfw;
    Gdiplus::Font font(L"Arial", 100, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel,  NULL);
    HDC hdc = CreateCompatibleDC(0);
    Gdiplus::Graphics graphics(hdc);
    HFONT gdifont;

    font.GetLogFontW(&graphics, &lfw);
    gdifont = CreateFontIndirectW(&lfw);
    SelectObject(hdc, gdifont);
    //
    if (gdifont) printf("Font installed \n");

    for (int i = 0; i < teststring.length(); i++)
    {
        GetGlyphOutline(hdc, teststring.at(i), GGO_BEZIER, &gm, 0, NULL, &identity );
        printf("Character : %c,  Origin, X : %ld, Y : %ld, gm.gmBlackBoxY : %d, gm.gmBlackBoxX : %d \n", teststring.at(i), gm.gmptGlyphOrigin.x, gm.gmptGlyphOrigin.y, gm.gmBlackBoxY, gm.gmBlackBoxX);
    }

    //printf("DONE");

    return 0;
}
