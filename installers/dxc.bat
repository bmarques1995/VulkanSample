IF %~1 EQU Debug ( GOTO:passed )
IF %~1 EQU Release ( GOTO:passed )
goto:eof

:passed
IF STR(%~2) NEQ STR() ( GOTO:passed_install )
goto:eof

:passed_install

set exec_dir=%cd%

cd ./modules/dxc

call ./utils/hct/hctstart %exec_dir%\modules\dxc %exec_dir%\dependencies\dxc
call ./utils/hct/hctbuild -%~1 -no-parallel -installdir "%~2" -spirv -ninja

cd %exec_dir%

cmake --build ./dependencies/dxc --config %~1 --target install-distribution
cmake --build ./dependencies/dxc --config %~1 --target install-dxc
cmake --build ./dependencies/dxc --config %~1 --target install-dxcompiler
copy %cd%\dependencies\dxc\lib\dxcompiler.lib %~2\lib