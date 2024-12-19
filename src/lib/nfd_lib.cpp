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
#include "nfd_lib.h"

#ifdef __cplusplus
extern "C" {
#endif

LIB_SOURCE_EXPORT char *NFD_ScanFileA(char *pszFileName, unsigned int nFlags)
{
    return NFD_lib().scanFileA(pszFileName, nFlags);
}

LIB_SOURCE_EXPORT wchar_t *NFD_ScanFileW(wchar_t *pwszFileName, unsigned int nFlags)
{
    return NFD_lib().scanFileW(pwszFileName, nFlags);
}

LIB_SOURCE_EXPORT char *NFD_ScanMemoryA(char *pMemory, int nMemorySize, unsigned int nFlags)
{
    return NFD_lib().scanMemoryA(pMemory, nMemorySize, nFlags);
}

LIB_SOURCE_EXPORT wchar_t *NFD_ScanMemoryW(char *pMemory, int nMemorySize, unsigned int nFlags)
{
    return NFD_lib().scanMemoryW(pMemory, nMemorySize, nFlags);
}

LIB_SOURCE_EXPORT void NFD_FreeMemoryA(char *pszString)
{
    NFD_lib().freeMemoryA(pszString);
}

LIB_SOURCE_EXPORT void NFD_FreeMemoryW(wchar_t *pwszString)
{
    NFD_lib().freeMemoryW(pwszString);
}
#ifdef Q_OS_WIN32
LIB_SOURCE_EXPORT int NFD_VB_ScanFile(wchar_t *pwszFileName, unsigned int nFlags, wchar_t *pwszBuffer, int nBufferSize)
{
    return NFD_lib().VB_ScanFile(pwszFileName, nFlags, pwszBuffer, nBufferSize);
}
#endif

#ifdef __cplusplus
}
#endif

NFD_lib::NFD_lib()
{
}

char *NFD_lib::scanFileA(char *pszFileName, unsigned int nFlags)
{
    QString sResult = _scanFile(pszFileName, nFlags);

    QByteArray baResult = sResult.toUtf8();

    char *pBuffer = new char[baResult.size() + 1];

    XBinary::_copyMemory(pBuffer, baResult.data(), baResult.size());
    pBuffer[baResult.size()] = 0;

    return pBuffer;
}

wchar_t *NFD_lib::scanFileW(wchar_t *pwszFileName, unsigned int nFlags)
{
    QString sResult = _scanFile(QString::fromWCharArray(pwszFileName, -1), nFlags);

    int nSize = (sResult.size() + 1) * 2;

    char *pBuffer = new char[nSize];

    sResult.toWCharArray((wchar_t *)pBuffer);

    return (wchar_t *)pBuffer;
}

char *NFD_lib::scanMemoryA(char *pMemory, int nMemorySize, unsigned int nFlags)
{
    QString sResult = _scanMemory(pMemory, nMemorySize, nFlags);

    QByteArray baResult = sResult.toUtf8();

    char *pBuffer = new char[baResult.size() + 1];

    XBinary::_copyMemory(pBuffer, baResult.data(), baResult.size());
    pBuffer[baResult.size()] = 0;

    return pBuffer;
}

wchar_t *NFD_lib::scanMemoryW(char *pMemory, int nMemorySize, unsigned int nFlags)
{
    QString sResult = _scanMemory(pMemory, nMemorySize, nFlags);

    int nSize = (sResult.size() + 1) * 2;

    char *pBuffer = new char[nSize];

    sResult.toWCharArray((wchar_t *)pBuffer);

    return (wchar_t *)pBuffer;
}

void NFD_lib::freeMemoryA(char *pszString)
{
    delete[] pszString;
}

void NFD_lib::freeMemoryW(wchar_t *pwszString)
{
    delete[] pwszString;
}

#ifdef Q_OS_WIN32
int NFD_lib::VB_ScanFile(wchar_t *pwszFileName, unsigned int nFlags, wchar_t *pwszBuffer, int nBufferSize)
{
    int nResult = 0;

    QString sResult = _scanFile(QString::fromWCharArray(pwszFileName, -1), nFlags);

    if (sResult.size() < nBufferSize) {
        sResult.toWCharArray(pwszBuffer);
        nResult = sResult.size();
    }

    return nResult;
}
#endif
QString NFD_lib::_scanFile(QString sFileName, quint32 nFlags)
{
    XScanEngine::SCAN_OPTIONS options = XScanEngine::getDefaultOptions(nFlags);
    XScanEngine::SCAN_RESULT scanResult = SpecAbstract().scanFile(sFileName, &options);

    ScanItemModel model(&options, &(scanResult.listRecords), 1);

    return model.toString();
}

QString NFD_lib::_scanMemory(char *pMemory, int nMemorySize, quint32 nFlags)
{
    XScanEngine::SCAN_OPTIONS options = XScanEngine::getDefaultOptions(nFlags);
    XScanEngine::SCAN_RESULT scanResult = SpecAbstract().scanMemory(pMemory, nMemorySize, &options);

    ScanItemModel model(&options, &(scanResult.listRecords), 1);

    return model.toString();
}
