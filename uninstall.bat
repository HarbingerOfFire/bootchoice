@echo off
::If prereq installed, you can uncomment this to uninstall them. Else, then leave this commented
::powershell -Command "Import-Module NtObjectManager; if ($?) { Uninstall-Module -Name NtObjectManager -RequiredVersion 1.1.32 -Force;};"

::Remove bootchoice from shell user shell launch (undo reg add)
reg DELETE HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System /v Shell /f

::delete the executable for clean uninstall (undo make)
del /F C:\windows\system32\bootchoice.exe

::if you installed for all users, run this to reset key to explorer.exe
::reg add HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon /v Shell /d "explorer.exe" /f