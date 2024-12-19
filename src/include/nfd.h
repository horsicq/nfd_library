#ifndef NFDLIB_H
#define NFDLIB_H

#ifdef _WIN32
#include <windows.h>
#endif

// flags
#define NFD_DEEPSCAN 0x00000001
#define NFD_HEURISTICSCAN 0x00000002
#define NFD_ALLTYPESSCAN 0x00000004
#define NFD_RECURSIVESCAN 0x00000008
#define NFD_VERBOSE 0x00000010
#define NFD_RESULTASXML 0x00010000
#define NFD_RESULTASJSON 0x00020000
#define NFD_RESULTASTSV 0x00040000
#define NFD_RESULTASCSV 0x00080000

#ifdef __cplusplus
extern "C" {
#endif

char *NFD_ScanFileA(char *pszFileName, unsigned int nFlags);
wchar_t *NFD_ScanFileW(wchar_t *pwszFileName, unsigned int nFlags);
char *NFD_ScanMemoryA(char *pMemory, int nMemorySize, unsigned int nFlags);
wchar_t *NFD_ScanMemoryW(char *pMemory, int nMemorySize, unsigned int nFlags);
void NFD_FreeMemoryA(char *pszString);
void NFD_FreeMemoryW(wchar_t *pwszString);

#ifdef _WIN32
int NFD_VB_ScanFile(wchar_t *pwszFileName, unsigned int nFlags, wchar_t *pwszBuffer, int nBufferSize);
#endif

#ifdef UNICODE
#define NFD_ScanFile NFD_ScanFileW
#define NFD_ScanMemory NFD_ScanMemoryW
#define NFD_FreeMemory NFD_FreeMemoryW
#else
#define NFD_ScanFile NFD_ScanFileA
#define NFD_ScanMemory NFD_ScanMemoryA
#define NFD_FreeMemory NFD_FreeMemoryA
#endif

#ifdef __cplusplus
}
#endif

#endif  // NFDLIB_H
