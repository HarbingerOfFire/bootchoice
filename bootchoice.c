#include <stdio.h>
#include <stdlib.h>

int main(){
    char* explorer = "powershell -Command \"Import-Module NtObjectManager; Start-Service TrustedInstaller; $p = Get-NtProcess -Name TrustedInstaller.exe; $th = $p.GetFirstThread(); $current = Get-NtThread -Current -PseudoHandle; $imp = $current.ImpersonateThread($th); $imp_token = Get-NtToken -Impersonation; $imp_token.Groups | Where-Object {$_.Sid.Name -match 'TrustedInstaller'}; if (Test-Path variable:global:imp_token) { Invoke-Expression explorer.exe }; Stop-Service TrustedInstaller\"";
    printf("Choose boot option:\n0: cmd.exe\n1: explorer.exe\nEnter Choice: ");
    int buf;
    scanf("%d", &buf);
    switch (buf){
    case 0:
        system("cmd.exe");
        break;
    case 1:
        system(explorer);
        break;
    default:
        printf("Incorrect Choice");
        main();
    }
    return 0;
}