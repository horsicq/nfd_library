call %X_SOURCE_PATH%\build_tools\windows.cmd make_init

IF NOT [%X_ERROR%] == [] goto exit

call %X_SOURCE_PATH%\build_tools\windows.cmd make_build %X_SOURCE_PATH%\nfd_library.pro

call %X_SOURCE_PATH%\build_tools\windows.cmd check_file %X_SOURCE_PATH%\build\release\nfd.dll

IF NOT [%X_ERROR%] == [] goto exit

copy %X_SOURCE_PATH%\build\release\nfd.dll %X_SOURCE_PATH%\release\%X_BUILD_NAME%\
copy %X_SOURCE_PATH%\build\release\nfd.exp %X_SOURCE_PATH%\release\%X_BUILD_NAME%\
copy %X_SOURCE_PATH%\build\release\nfd.lib %X_SOURCE_PATH%\release\%X_BUILD_NAME%\

xcopy %X_SOURCE_PATH%\include %X_SOURCE_PATH%\release\%X_BUILD_NAME%/E /I

call %X_SOURCE_PATH%\build_tools\windows.cmd deploy_qt_library Qt5Core

call %X_SOURCE_PATH%\build_tools\windows.cmd make_release

:exit
call %X_SOURCE_PATH%\build_tools\windows.cmd make_clear
