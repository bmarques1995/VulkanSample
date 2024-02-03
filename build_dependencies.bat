@echo off

set build_mode=""

IF %~1 EQU Debug ( GOTO:passed )
IF %~1 EQU Release ( GOTO:passed )

echo Build mode not set or invalid , the default is the debug mode
set build_mode=Debug
goto proceed

:passed

echo Build mode is %~1
set build_mode=%~1
goto proceed

:proceed

set install_prefix=%cd%\Windows\%build_mode%

call build_deps.bat %build_mode% %install_prefix%
