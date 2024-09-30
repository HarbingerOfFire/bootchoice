#include <stdio.h>
#include <stdlib.h>

int main() {
    // PowerShell script to start explorer.exe as TrustedInstaller. Not needed but kept for future
    /*char* explorer = "powershell -Command \"Import-Module NtObjectManager; Start-Service TrustedInstaller; "
                     "$p = Get-NtProcess -Name TrustedInstaller.exe; $th = $p.GetFirstThread(); "
                     "$current = Get-NtThread -Current -PseudoHandle; $imp = $current.ImpersonateThread($th); "
                     "$imp_token = Get-NtToken -Impersonation; $imp_token.Groups | Where-Object {$_.Sid.Name -match 'TrustedInstaller'}; "
                     "if (Test-Path variable:global:imp_token) { Invoke-Expression explorer.exe }; Stop-Service TrustedInstaller\"";
    */

    int buf;
    printf("\
########   #######   #######  ########  ######  ##     ##  #######  ####  ######  ######## \n\
##     ## ##     ## ##     ##    ##    ##    ## ##     ## ##     ##  ##  ##    ## ##       \n\
##     ## ##     ## ##     ##    ##    ##       ##     ## ##     ##  ##  ##       ##       \n\
########  ##     ## ##     ##    ##    ##       ######### ##     ##  ##  ##       ######   \n\
##     ## ##     ## ##     ##    ##    ##       ##     ## ##     ##  ##  ##       ##       \n\
##     ## ##     ## ##     ##    ##    ##    ## ##     ## ##     ##  ##  ##    ## ##       \n\
########   #######   #######     ##     ######  ##     ##  #######  ####  ######  ######## \n\
\n");
    while (1) {
        // User prompt to select between CMD, Explorer, or Exit
        printf("Choose boot option:\n0: cmd.exe (CLI Mode)\n1: Full Windows GUI (explorer.exe)\n2: Run some other program (via windows run dialog)\n3: Exit Shell\nEnter Choice: ");
        scanf("%d", &buf);

        switch (buf) {
        case 0:
            // Launch Command Prompt (CLI Mode)
            system("conhost.exe"); //old graphics terminal, automatically opens to cmd.exe
            break;
        case 1:
            // Kill any existing explorer processes
            system("taskkill /F /IM explorer.exe 2> C:/NUL"); //kill lingering proccess of explorer.exe (output stored in null if errors)

            // Execute PowerShell command to start explorer.exe as TrustedInstaller
            system("explorer.exe");
            break;
        case 2:
            //run something else via windows run dialog (use shell32 so you don't have to launch full gui)
            system("rundll32 shell32.dll,#61");
        case 3:
            // Exit the program
            printf("Exiting shell...\n");
            return 0;
        default:
            // Handle invalid input
            printf("Incorrect Choice. Please try again.\n");
            continue; // Go back to the start of the loop
        }

        break; // Exit the loop if a valid option was chosen
    }

    return 0;
}
