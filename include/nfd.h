#ifndef NFDLIB_H
#define NFDLIB_H

#include <windows.h>

// flags
#define NFD_DEEPSCAN            0x00000001
#define NFD_HEURISTICSCAN       0x00000002
#define NFD_ALLTYPESSCAN        0x00000004
#define NFD_RECURSIVESCAN       0x00000008
#define NFD_VERBOSE             0x00000010
#define NFD_RESULTASXML         0x00010000
#define NFD_RESULTASJSON        0x00020000
#define NFD_RESULTASTSV         0x00040000
#define NFD_RESULTASCSV         0x00080000

#ifdef __cplusplus
extern "C" {
#endif

char *NFD_ScanFileA(char *pszFileName, unsigned int nFlags, char *pszDatabase);
wchar_t *NFD_ScanFileW(wchar_t *pwszFileName, unsigned int nFlags, wchar_t *pwszDatabase);
void NFD_FreeMemoryA(char *pszString);
void NFD_FreeMemoryW(char *pwszString);
BSTR NFD_VB_ScanFile(wchar_t *pwszFileName, unsigned int nFlags, wchar_t *pwszDatabase);

#ifdef UNICODE
#define NFD_ScanFile NFD_ScanFileW
#define NFD_FreeMemory NFD_FreeMemoryW
#else
#define NFD_ScanFile NFD_ScanFileA
#define NFD_FreeMemory NFD_FreeMemoryA
#endif

#ifdef __cplusplus
}
#endif

#endif // NFDLIB_H
