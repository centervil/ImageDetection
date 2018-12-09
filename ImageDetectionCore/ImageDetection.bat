@echo off
cd /d %~dp0
setlocal enabledelayedexpansion

rem 検査画像（各文言の前後に検出記号あり）
set SOURCE_PATH=Source

rem 正解情報画像（各文言の箇所に検出記号×2）
set REF_PATH=Ref

rem テンプレート画像（検出記号）
set TEMPLATE_PATH=Template

rem 検査画像の解析結果
set RESULT_PATH=Result

call Release\ImageDetectionCore.exe %REF_PATH% %TEMPLATE_PATH% %RESULT_PATH% -> result_ref.txt
call Release\ImageDetectionCore.exe %SOURCE_PATH% %TEMPLATE_PATH% %RESULT_PATH% -w -s -> result.txt
pause
exit /b 0