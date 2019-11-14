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
#include "nfd_lib.h"

#ifdef __cplusplus
extern "C" {
#endif

int LIB_SOURCE_EXPORT CreateScanHandle()
{  
    return NFD_lib().createHandle();
}

bool LIB_SOURCE_EXPORT CloseScanHandle(int nHandle)
{
    return NFD_lib().closeHandle(nHandle);
}

#ifdef __cplusplus
}
#endif

NFD_lib::NFD_lib()
{

}

QMap<int,char *> NFD_lib::mapHandles={};

int NFD_lib::createHandle()
{
    int nResult=0;

    for(int i=1;i<1000;i++)
    {
        if(!mapHandles.contains(i))
        {
            nResult=i;

            mapHandles.insert(i,0);

            break;
        }
    }

    return nResult;
}

char *NFD_lib::scanFileA(int nHandle, char *pszFileName, unsigned int nFlags)
{
    return 0;
}

wchar_t *NFD_lib::scanFileW(int nHandle, wchar_t *pwszFileName, unsigned int nFlags)
{
    return 0;
}

bool NFD_lib::closeHandle(int nHandle)
{
    bool bResult=false;

    if(mapHandles.contains(nHandle))
    {
        char *pMemory=mapHandles.value(nHandle);

        mapHandles.remove(nHandle);

        if(pMemory)
        {
            delete [] pMemory;
        }

        bResult=true;
    }

    return bResult;
}

QString NFD_lib::_scanFile(QString sFileName, quint32 nFlags)
{
    QString sResult;

    SpecAbstract::SCAN_OPTIONS options={};

    SpecAbstract::SCAN_RESULT scanResult=StaticScan::processFile(sFileName,&options);

    return sResult;
}
