set VS_PATH="C:\Program Files (x86)\Microsoft Visual Studio 12.0"
set SEVENZIP_PATH="C:\Program Files\7-Zip"
set QT_PATH="C:\Qt\5.6.3\msvc2013_static_64"

set BUILD_NAME=nfd_lib_win64
set SOURCE_PATH=%~dp0
mkdir %SOURCE_PATH%\release
set /p RELEASE_VERSION=<%SOURCE_PATH%\release_version.txt

set QT_PATH=%QT_PATH%
set QT_SPEC=win32-msvc2013
call %VS_PATH%\VC\bin\amd64\vcvars64.bat
set ZIP_NAME=%BUILD_NAME%_%RELEASE_VERSION%

cd lib_source
%QT_PATH%\bin\qmake.exe lib_source.pro -r -spec %QT_SPEC% "CONFIG+=release"

nmake Makefile.Release clean
nmake
del Makefile
del Makefile.Release
del Makefile.Debug

cd ..

mkdir %SOURCE_PATH%\release\%BUILD_NAME%

copy %SOURCE_PATH%\build\release\nfd.lib %SOURCE_PATH%\release\%BUILD_NAME%\
copy %SOURCE_PATH%\build\release\nfd.dll %SOURCE_PATH%\release\%BUILD_NAME%\

xcopy %SOURCE_PATH%\include %SOURCE_PATH%\release\%BUILD_NAME%\include /E /I
xcopy %SOURCE_PATH%\examples %SOURCE_PATH%\release\%BUILD_NAME%\examples /E /I

cd %SOURCE_PATH%\release
if exist %ZIP_NAME%.zip del %ZIP_NAME%.zip
%SEVENZIP_PATH%\7z.exe a %ZIP_NAME%.zip %BUILD_NAME%\*
rmdir /s /q %SOURCE_PATH%\release\%BUILD_NAME%
cd ..