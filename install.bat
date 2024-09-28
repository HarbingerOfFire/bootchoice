@echo off
::install prereqs Needed for trusted installed mode (old version)
::powershell -Command "Import-Module NtObjectManager; if (!$?) { Install-Module -Name NtObjectManager -RequiredVersion 1.1.32 -Force; Import-Module NtObjectManager };"
::make script
make
::edit key so it runs on boot instead of explorer
::This version runs it for single user.
reg add HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System /v Shell /d "conhost.exe bootchoice.exe" /f

::if you want to change for all users you can try this key, but it has been known to cause errors.
::reg add HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon /v Shell /d "conhost.exe bootchoice.exe" /f
