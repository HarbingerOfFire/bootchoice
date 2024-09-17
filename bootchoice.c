#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Choose boot option:\n0: cmd.exe\n1: explorer.exe\nEnter Choice: ");
    int buf;
    scanf("%d", &buf);
    switch (buf){
    case 0:
        system("cmd.exe");
        break;
    case 1:
        system("explorer.exe");
        break;
    default:
        printf("Incorrect Choice");
        main();
    }
    return 0;
}