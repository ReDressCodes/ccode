#include <windows.h>
#include <gdiplus.h>
#include <strsafe.h>

#define MAX_STYLE_SIZE 20
#define MAX_FACEANDSTYLE_SIZE (LF_FACESIZE + MAX_STYLE_SIZE + 2)

using namespace Gdiplus;

int main(int argc, char *argv[]) {
  HWND hwnd;
  struct GdiplusStartupInput gdiplusStartupInput;
  ULONG_PTR gdiplusToken;

  WNDCLASSA properties;
  memset(&properties, 0, sizeof(properties));
  properties.lpszClassName = "FontFromFile";
  properties.lpfnWndProc = DefWindowProc;
  properties.hInstance = GetModuleHandleA(0);
  properties.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
  RegisterClassA(&properties);

  hwnd = CreateWindowA("FontFromFile", "FontFromFile",
                       WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                       CW_USEDEFAULT, 800, 600, 0, 0, GetModuleHandleA(0), 0);

  gdiplusStartupInput.GdiplusVersion = 1;
  gdiplusStartupInput.DebugEventCallback = NULL;
  gdiplusStartupInput.SuppressBackgroundThread = 0;
  gdiplusStartupInput.SuppressExternalCodecs = 0;

  GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

  HDC hdc = GetDC(hwnd);

  Graphics graphics(hdc);
  PointF pointF(10.0f, 0.0f);
  SolidBrush solidBrush(Color(255, 0, 0, 0));
  INT count = 0;
  INT found = 0;
  WCHAR familyName[LF_FACESIZE];
  WCHAR familyNameAndStyle[MAX_FACEANDSTYLE_SIZE];
  FontFamily *pFontFamily;
  PrivateFontCollection privateFontCollection;

  // Add three font files to the private collection.
  privateFontCollection.AddFontFile(L"c:\\Fonts\\coders_crux.ttf");
  privateFontCollection.AddFontFile(L"c:\\Fonts\\VL-Gothic-Regular.ttf");
  privateFontCollection.AddFontFile(L"c:\\Fonts\\VL-PGothic-Regular.ttf");

  // How many font families are in the private collection?
  count = privateFontCollection.GetFamilyCount();

  // Allocate a buffer to hold the array of FontFamily
  // objects returned by GetFamilies.
  pFontFamily = new FontFamily[count];

  // Get the array of FontFamily objects.
  privateFontCollection.GetFamilies(count, pFontFamily, &found);

  // Display the name of each font family in the private collection
  // along with the available styles for that font family.
  for (INT j = 0; j < count; ++j) {
    // Get the font family name.
    pFontFamily[j].GetFamilyName(familyName);

    // Is the regular style available?
    if (pFontFamily[j].IsStyleAvailable(FontStyleRegular)) {
      StringCchCopyW(familyNameAndStyle, LF_FACESIZE, familyName);
      StringCchCatW(familyNameAndStyle, MAX_FACEANDSTYLE_SIZE, L" Regular");

      Font *pFont = new Font(familyName, 16, FontStyleRegular, UnitPixel,
                             &privateFontCollection);

      graphics.DrawString(familyNameAndStyle, -1, pFont, pointF, &solidBrush);

      pointF.Y += pFont->GetHeight(0.0f);
      delete (pFont);
    }

    // Is the bold style available?
    if (pFontFamily[j].IsStyleAvailable(FontStyleBold)) {
      StringCchCopyW(familyNameAndStyle, LF_FACESIZE, familyName);
      StringCchCatW(familyNameAndStyle, MAX_FACEANDSTYLE_SIZE, L" Bold");

      Font *pFont = new Font(familyName, 16, FontStyleBold, UnitPixel,
                             &privateFontCollection);

      graphics.DrawString(familyNameAndStyle, -1, pFont, pointF, &solidBrush);

      pointF.Y += pFont->GetHeight(0.0f);
      delete (pFont);
    }

    // Is the italic style available?
    if (pFontFamily[j].IsStyleAvailable(FontStyleItalic)) {
      StringCchCopyW(familyNameAndStyle, LF_FACESIZE, familyName);
      StringCchCatW(familyNameAndStyle, MAX_FACEANDSTYLE_SIZE, L" Italic");

      Font *pFont = new Font(familyName, 16, FontStyleItalic, UnitPixel,
                             &privateFontCollection);

      graphics.DrawString(familyNameAndStyle, -1, pFont, pointF, &solidBrush);

      pointF.Y += pFont->GetHeight(0.0f);
      delete (pFont);
    }

    // Is the bold italic style available?
    if (pFontFamily[j].IsStyleAvailable(FontStyleBoldItalic)) {
      StringCchCopyW(familyNameAndStyle, LF_FACESIZE, familyName);
      StringCchCatW(familyNameAndStyle, MAX_FACEANDSTYLE_SIZE, L" BoldItalic");

      Font *pFont = new Font(familyName, 16, FontStyleBoldItalic, UnitPixel,
                             &privateFontCollection);

      graphics.DrawString(familyNameAndStyle, -1, pFont, pointF, &solidBrush);

      pointF.Y += pFont->GetHeight(0.0f);
      delete (pFont);
    }

    // Is the underline style available?
    if (pFontFamily[j].IsStyleAvailable(FontStyleUnderline)) {
      StringCchCopyW(familyNameAndStyle, LF_FACESIZE, familyName);
      StringCchCatW(familyNameAndStyle, MAX_FACEANDSTYLE_SIZE, L" Underline");

      Font *pFont = new Font(familyName, 16, FontStyleUnderline, UnitPixel,
                             &privateFontCollection);

      graphics.DrawString(familyNameAndStyle, -1, pFont, pointF, &solidBrush);

      pointF.Y += pFont->GetHeight(0.0);
      delete (pFont);
    }

    // Is the strikeout style available?
    if (pFontFamily[j].IsStyleAvailable(FontStyleStrikeout)) {
      StringCchCopyW(familyNameAndStyle, LF_FACESIZE, familyName);
      StringCchCatW(familyNameAndStyle, MAX_FACEANDSTYLE_SIZE, L" Strikeout");

      Font *pFont = new Font(familyName, 16, FontStyleStrikeout, UnitPixel,
                             &privateFontCollection);

      graphics.DrawString(familyNameAndStyle, -1, pFont, pointF, &solidBrush);

      pointF.Y += pFont->GetHeight(0.0f);
      delete (pFont);
    }

    // Separate the families with white space.
    pointF.Y += 10.0f;

  } // for

  MSG Msg;
  while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  delete pFontFamily;
  return 0;
}
