@echo off
cd /d %~dp0
setlocal enabledelayedexpansion

rem �����摜�i�e�����̑O��Ɍ��o�L������j
set SOURCE_PATH=Source

rem �������摜�i�e�����̉ӏ��Ɍ��o�L���~2�j
set REF_PATH=Ref

rem �e���v���[�g�摜�i���o�L���j
set TEMPLATE_PATH=Template

rem �����摜�̉�͌���
set RESULT_PATH=Result

call Release\ImageDetectionCore.exe %REF_PATH% %TEMPLATE_PATH% %RESULT_PATH% -> result_ref.txt
call Release\ImageDetectionCore.exe %SOURCE_PATH% %TEMPLATE_PATH% %RESULT_PATH% -w -s -> result.txt
pause
exit /b 0