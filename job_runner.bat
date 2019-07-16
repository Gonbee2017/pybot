@echo off
rem �����i�[�W���u by GonBee

cd /d %~dp0
call job_config.bat
del *.run>nul 2>&1
del *.stop>nul 2>&1

:run
if exist map-server.run (
	call :check login %login_server_port%
	call :check char %char_server_port%
	call :check map %map_server_port%
	timeout /t %check_interval% /nobreak>nul 2>&1
	goto run
)
call :stop_server char
call :stop_server login
call :backup
call :start
timeout /t %check_interval% /nobreak>nul 2>&1
goto run

:check
ss-checker %bind_address% %2>nul 2>&1
if errorlevel 1 (
	echo %date% %time:~0,8% - %1�T�[�o�[���t���[�Y�������ߍċN�����܂��B
	taskkill /f /im %1-server.exe>nul 2>&1
	timeout /t %recovery_seconds% /nobreak>nul 2>&1
)
exit /b

:backup
set backup_today=%date:~0,4%%date:~5,2%%date:~8,2%
set backup_sql_file=%db_name%_%backup_today%.sql
set backup_zip_file=%db_name%_%backup_today%.zip
if not exist %dump_dir%%backup_zip_file% (
	if not %dump_days%==0 (
		echo %date% %time:~0,8% - %backup_zip_file%���쐬���܂��B
		mysqldump -u%db_user% -p%db_password% -r %backup_sql_file% %db_name%>nul 2>&1
		powershell compress-archive %backup_sql_file% %dump_dir%%backup_zip_file%
		del %backup_sql_file%
		echo %date% %time:~0,8% - �ۊǓ������߂���MySQL�_���v�t�@�C�����폜���܂��B
		forfiles /p %dump_dir% /m %db_name%_*.zip /d -%dump_days% /c "cmd /c del @file && echo @file���폜���܂����B" 2>nul
	)
	echo %date% %time:~0,8% - ���O�e�[�u�����N���A���܂��B
	mysql -u%db_user% -p%db_password% %db_name%<sql-files\clear_logs.sql>nul 2>&1
)
echo %date% %time:~0,8% - �ۊǓ������߂���Apache���O�t�@�C�����폜���܂��B
forfiles /p %web_logs_dir% /m access_*.log /d -%web_logs_days% /c "cmd /c del @file && echo @file���폜���܂����B" 2>nul
forfiles /p %web_logs_dir% /m error_*.log /d -%web_logs_days% /c "cmd /c del @file && echo @file���폜���܂����B" 2>nul
exit /b

:start
del *.run>nul 2>&1
del *.stop>nul 2>&1
echo %date% %time:~0,8% - login�T�[�o�[�W���u���N�����܂��B
call :start_server login
echo %date% %time:~0,8% - char�T�[�o�[�W���u���N�����܂��B
call :start_server char
echo %date% %time:~0,8% - map�T�[�o�[�W���u���N�����܂��B
call :start_server map
exit /b

:start_server
start "%1-server" cmd /c job_server.bat %1
call :wait_start_server %1
exit /b

:stop_server
echo>%1-server.stop
taskkill /f /im %1-server.exe>nul 2>&1
call :wait_stop_server %1
exit /b

:wait_start_server
:wait_start_server_wait
if not exist %1-server.run (
	timeout /t 1 /nobreak>nul 2>&1
	goto wait_start_server_wait
)
exit /b

:wait_stop_server
:wait_stop_server_wait
if exist %1-server.run (
	timeout /t 1 /nobreak>nul 2>&1
	goto wait_stop_server_wait
)
exit /b
