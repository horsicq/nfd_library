/* Copyright (c) 2019-2023 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef NFD_LIB_H
#define NFD_LIB_H

#include "specabstract.h"
#include "scanitemmodel.h"
#ifdef Q_OS_WIN32
#include <windows.h>
#include <comutil.h>
#endif

#if defined(LIB_SOURCE_LIBRARY)
#define LIB_SOURCE_EXPORT Q_DECL_EXPORT
#else
#define LIB_SOURCE_EXPORT Q_DECL_IMPORT
#endif

class NFD_lib {
public:
    NFD_lib();
    char *scanFileA(char *pszFileName, unsigned int nFlags);
    wchar_t *scanFileW(wchar_t *pwszFileName, unsigned int nFlags);
    char *scanMemoryA(char *pMemory, int nMemorySize, unsigned int nFlags);
    wchar_t *scanMemoryW(char *pMemory, int nMemorySize, unsigned int nFlags);
    void freeMemoryA(char *pszString);
    void freeMemoryW(wchar_t *pwszString);
#ifdef Q_OS_WIN32
    int VB_ScanFile(wchar_t *pwszFileName, unsigned int nFlags, wchar_t *pwszBuffer, int nBufferSize);
#endif

private:
    QString _scanFile(QString sFileName, quint32 nFlags);
    QString _scanMemory(char *pMemory, int nMemorySize, quint32 nFlags);
};

#endif  // NFD_LIB_H
