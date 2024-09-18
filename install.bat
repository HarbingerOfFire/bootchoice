@echo off
::install prereqs
powershell -Command "Import-Module NtObjectManager; if (!$?) { Install-Module -Name NtObjectManager -RequiredVersion 1.1.32 -Force; Import-Module NtObjectManager };"
::make script
make
::edit key so it runs on boot instead of explorer
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon" /v Shell /d "bootchoice.exe" /f