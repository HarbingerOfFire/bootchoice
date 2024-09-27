#include <stdio.h>
#include <stdlib.h>

int main() {
    // PowerShell script to start explorer.exe as TrustedInstaller
    char* explorer = "powershell -Command \"Import-Module NtObjectManager; Start-Service TrustedInstaller; "
                     "$p = Get-NtProcess -Name TrustedInstaller.exe; $th = $p.GetFirstThread(); "
                     "$current = Get-NtThread -Current -PseudoHandle; $imp = $current.ImpersonateThread($th); "
                     "$imp_token = Get-NtToken -Impersonation; $imp_token.Groups | Where-Object {$_.Sid.Name -match 'TrustedInstaller'}; "
                     "if (Test-Path variable:global:imp_token) { Invoke-Expression explorer.exe }; Stop-Service TrustedInstaller\"";

    int buf;

    while (1) {
        // User prompt to select between CMD, Explorer, or Exit
        printf("Choose boot option:\n0: cmd.exe (CLI Mode)\n1: Full Windows GUI (explorer.exe as TrustedInstaller)\n2: Exit Shell\nEnter Choice: ");
        scanf("%d", &buf);

        switch (buf) {
        case 0:
            // Launch Command Prompt (CLI Mode)
            system("cmd.exe");
            break;
        case 1:
            // Kill any existing explorer processes
            system("taskkill /F /IM explorer.exe");

            // Execute PowerShell command to start explorer.exe as TrustedInstaller
            system(explorer);
            break;
        case 2:
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
