```
########   #######   #######  ########  ######  ##     ##  #######  ####  ######  ######## 
##     ## ##     ## ##     ##    ##    ##    ## ##     ## ##     ##  ##  ##    ## ##       
##     ## ##     ## ##     ##    ##    ##       ##     ## ##     ##  ##  ##       ##       
########  ##     ## ##     ##    ##    ##       ######### ##     ##  ##  ##       ######   
##     ## ##     ## ##     ##    ##    ##       ##     ## ##     ##  ##  ##       ##       
##     ## ##     ## ##     ##    ##    ##    ## ##     ## ##     ##  ##  ##    ## ##       
########   #######   #######     ##     ######  ##     ##  #######  ####  ######  ######## 
```
# Intro
Bootchoice is a basic program that can run on startup that intercepts the starting of the windows gui, and gives you the option to continue with the GUI, command prompt, or some other program. 

# How it works
Bootchoice edits the windows registry below, which configures what shell opens for the current user in place of explorer.exe. 
```batch
HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System
```
The code then launches on reboot to prompt for what program the user wants to launch. The current options are:
1. CLI mode (launch command prompt)
2. GUI mode (launch explorer.exe)
3. Other (launch windows run dialog to run another command)

# Install
Prereqs for this are just GCC and make. To install just simply clone the repo. Then in a admistrator command prompt in the bootchoice directory, just run `install` and it will set up everything.

NOTE: For Windows 24H2 (build 26100+), using `sudo install` in a user level prompt does work as well. You can also use `sudo make install`

# Uninstall
If you don't like this, you can revert to original system running `uninstall` in the bootchoice directory as administrator.

NOTE: `sudo uninstall` also works for 24H2 systems

# Install for all Users
While not recommended (due to unidentified bugs) however it is possible. To install comment line 9 and uncomment line 12 in `install.bat` before running, and it will change the registry key (below) that stores the name of the default shell, effectively changing the shell for everyone. This is an important key, so if you want to uninstall please use `uninstall.bat` (comment line 6, uncomment line 12) and do not delete the key, or else your system could possibly break.
```batch
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon
```

# Running Explorer.exe
When viewing the source code, you may notice some refrences to run explorer.exe as trusted installed. This is due to some errors early in the development process that prevented explorer.exe from loading the proper GUI, and just launch file explorer. However, we noticed that by taking control of TrustedInstaller, we could launch explorer.exe with the proper GUI. With some help from [@bigbeek](https://github.com/bigbeek), this no longer seems to be an error, but we're leaving the code there for an easy patch if needed.
