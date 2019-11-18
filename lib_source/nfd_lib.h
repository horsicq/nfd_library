// copyright (c) 2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef NFD_LIB_H
#define NFD_LIB_H

#include "staticscan.h"
#include "staticscanitemmodel.h"

#if defined(LIB_SOURCE_LIBRARY)
#  define LIB_SOURCE_EXPORT Q_DECL_EXPORT
#else
#  define LIB_SOURCE_EXPORT Q_DECL_IMPORT
#endif

class NFD_lib
{
public:
    enum SF
    {
        SF_RECURSIVE    =0x00000001,
        SF_DEEPSCAN     =0x00000002,
        SF_RESULTASXML  =0x00000004,
        SF_RESULTASJSON =0x00000008,
    };

    NFD_lib();
    int createHandle();
    char *scanFileA(int nHandle,char *pszFileName,unsigned int nFlags);
    wchar_t *scanFileW(int nHandle, wchar_t *pwszFileName,unsigned int nFlags);
    bool closeHandle(int nHandle);

private:
    QString _scanFile(QString sFileName,quint32 nFlags);

private:
    static QMap<int,char *> mapHandles;
};

#endif // NFD_LIB_H
