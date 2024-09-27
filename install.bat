@echo off
::install prereqs
powershell -Command "Import-Module NtObjectManager; if (!$?) { Install-Module -Name NtObjectManager -RequiredVersion 1.1.32 -Force; Import-Module NtObjectManager };"
::make script
make
::edit key so it runs on boot instead of explorer
reg add "Computer\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System" /v Shell /d "bootchoice.exe" /f