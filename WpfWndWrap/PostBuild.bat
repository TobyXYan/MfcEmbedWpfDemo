REM ------------------------------------ COMMON ENVIRONMENT VARIABLES ------------------------------------------
set TargetName=%1
set Platform=%2
set ConfigName=%3
set ProjectDir= %4 

echo %ProjectDir%

xcopy /f /y  \%Platform%\%ConfigNam%\%TargetName%.dll 	"\..\bin\"
xcopy /f /y  \%Platform%\%ConfigNam%\%TargetName%.pdb 	"\..\bin\"
xcopy /f /y  \%Platform%\%ConfigNam%\%TargetName%.lib 	"\..\bin\"
