#include <stdio.h>
#include "nfd.h"

int main(int argc, char* argv[])
{
    char *pszFileName="C:\\Windows\\notepad.exe";
    char *pszResult=0;
    
    pszResult=NFD_ScanFileA(pszFileName, NFD_DEEPSCAN | NFD_HEURISTICSCAN | NFD_RECURSIVESCAN, pszDatabase);
    printf("%s",pszResult);
    
    NFD_FreeMemoryA(pszResult);

    return 0;
}



