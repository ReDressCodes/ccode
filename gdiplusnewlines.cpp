#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <math.h>
#pragma comment (lib,"Gdiplus.lib")

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num = 0;
	UINT size = 0;

	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;

	Gdiplus::GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;

	pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;

	GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;
		}
	}

	free(pImageCodecInfo);
	return -1;
}

int wmain(int argc, wchar_t **argv)
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	const std::wstring teststring = L"Hello\r\nWorld";
	const std::wstring filename = argc >= 2 ? std::wstring(argv[1]) : L"gdiplus-test-string.png";

	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	CLSID encoder;
	GetEncoderClsid(L"image/png", &encoder);

	Gdiplus::Font font(Gdiplus::FontFamily::GenericSansSerif(), 12.0);
	Gdiplus::SolidBrush brush(Gdiplus::Color::Black);
	Gdiplus::RectF size;
        Gdiplus::Status hr;

	Gdiplus::Image *bmp = new Gdiplus::Bitmap(1, 1, PixelFormat32bppARGB);
	Gdiplus::Graphics *gfx = Gdiplus::Graphics::FromImage(bmp);
	
	gfx->MeasureString(teststring.c_str(), static_cast<INT>(teststring.length()), &font, Gdiplus::PointF(5, 5), &size);
	
	delete gfx;
	delete bmp;

	bmp = new Gdiplus::Bitmap((int)ceilf(size.Width) + 10, (int)ceilf(size.Height) + 10, PixelFormat32bppARGB);
	gfx = Gdiplus::Graphics::FromImage(bmp);
	
	gfx->Clear(Gdiplus::Color::White);
	hr = gfx->DrawString(teststring.c_str(), static_cast<INT>(teststring.length()), &font, Gdiplus::PointF(5, 5), &brush);

	LOGFONTW logfont;
	auto fontstatus = font.GetLogFontW(gfx, &logfont);
	HFONT hfont = CreateFontIndirectW(&logfont);

	auto hdc = gfx->GetHDC();
	INT fit;
	INT dx[256];
	SIZE txtsize;
	SelectObject(hdc, hfont);
	GetTextExtentExPointW(hdc, teststring.c_str(), static_cast<INT>(teststring.length()), 1000, &fit, dx, &txtsize);

	std::cout << "Max Fit: " << fit << std::endl;
	std::cout << "Size: " << txtsize.cx << " x " << txtsize.cy << std::endl;
	std::cout << "Character offsets: ";

	for (int i = 0; i < fit; i++) {
		if (teststring[i] == L'"' || teststring[i] == L'\\'){
			std::cout << "\"\\" << static_cast<char>(teststring[i]) << "\"";
		}
		else if (teststring[i] >= 32 && teststring[i] < 127) {
			std::cout << "\"" << static_cast<char>(teststring[i]) << "\"";
		}
		else {
			std::cout << "\"\\u" << std::setfill('0') << std::setw(4) << std::right << std::hex << teststring[i] << "\"";
		}

		std::cout << " (" << std::dec << dx[i] << ") ";
	}

	std::cout << std::endl;

	bmp->Save(filename.c_str(), &encoder, NULL);
	
	delete gfx;
	delete bmp;

	return 0;
}
