//-----------------------------------------------------------------------
// This file is part of the Windows SDK Code Samples.
// 
// Copyright (C) Microsoft Corporation.  All rights reserved.
// 
// This source code is intended only as a supplement to Microsoft
// Development Tools and/or on-line documentation.  See these other
// materials for detailed information regarding Microsoft code samples.
// 
// THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

#include <initguid.h>
#include <xmllite.h>
//#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>


//DEFINE_GUID(IID_IXmlWriterOutput, 0xc1131708, 0x0f59, 0x477f, 0x93, 0x59, 0x7d, 0x33, 0x24, 0x51, 0xbc, 0x1a);

int main(int argc, char* argv[])
{
    HRESULT hr;
    IStream *pOutFileStream;
    IXmlWriter  *pWriter;

    if (argc != 2)
    {
        wprintf(L"Usage: XmlLiteWriter.exe name-of-output-file\n");
        return 0;
    }

    //Open writeable output stream
    if (FAILED(hr = SHCreateStreamOnFile(argv[1], STGM_CREATE | STGM_WRITE, &pOutFileStream)))
    {
        wprintf(L"Error creating file writer, error is %08.8lx", hr);
        return -1;
    }

    if (FAILED(hr = CreateXmlWriter(IID_IXmlWriter, (void**) &pWriter, NULL)))
    {
        wprintf(L"Error creating xml writer, error is %08.8lx", hr);
        return -1;
    }

    if (FAILED(hr = pWriter->SetOutput(pOutFileStream)))
    {
        wprintf(L"Error, Method: SetOutput, error is %08.8lx", hr);
        return -1;
    }

    if (FAILED(hr = pWriter->SetProperty(XmlWriterProperty_Indent, TRUE)))
    {
        wprintf(L"Error, Method: SetProperty XmlWriterProperty_Indent, error is %08.8lx", hr);
        return -1;
    }

    if (FAILED(hr = pWriter->WriteStartDocument(XmlStandalone_Omit)))
    {
        wprintf(L"Error, Method: WriteStartDocument, error is %08.8lx", hr);
        return -1;
    }

    if (FAILED(hr = pWriter->WriteStartElement(NULL, L"root", NULL)))
    {
        wprintf(L"Error, Method: WriteStartElement, error is %08.8lx", hr);
        return -1;
    }

    if (FAILED(hr = pWriter->WriteStartElement(NULL, L"containsChars", NULL)))
    {
        wprintf(L"Error, Method: WriteStartElement, error is %08.8lx", hr);
        return -1;
    }
    WCHAR write[] = {0xd800, 0xdc00, '\0'};
    if (FAILED(hr = pWriter->WriteString(write)))
    {
        wprintf(L"Error, Method: WriteChars, error is %08.8lx", hr);
        return -1;
    }
    if (FAILED(hr = pWriter->WriteFullEndElement()))
    {
        wprintf(L"Error, Method: WriteFullEndElement, error is %08.8lx", hr);
        return -1;
    }
    /*
    if (FAILED(hr = pWriter->WriteWhitespace(L"\n")))
    {
        wprintf(L"Error, Method: WriteWhitespace, error is %08.8lx", hr);
        return -1;
    }
    */
    if (FAILED(hr = pWriter->WriteStartElement(NULL, L"containsEntity", NULL)))
    {
        wprintf(L"Error, Method: WriteStartElement, error is %08.8lx", hr);
        return -1;
    }
    if (FAILED(hr = pWriter->WriteString(L"myEntity")))
    {
        wprintf(L"Error, Method: WriteEntityRef, error is %08.8lx", hr);
        return -1;
    }
    if (FAILED(hr = pWriter->WriteEndElement()))
    {
        wprintf(L"Error, Method: WriteEndElement, error is %08.8lx", hr);
        return -1;
    }
    /*
    if (FAILED(hr = pWriter->WriteWhitespace(L"\n")))
    {
        wprintf(L"Error, Method: WriteWhitespace, error is %08.8lx", hr);
        return -1;
    }
    */
    if (FAILED(hr = pWriter->WriteEndElement()))
    {
        wprintf(L"Error, Method: WriteEndElement, error is %08.8lx", hr);
        return -1;
    }
    
    if (FAILED(hr = pWriter->Flush()))
    {
        wprintf(L"Error, Method: Flush, error is %08.8lx", hr);
        return -1;
    }

    return 0;

}
