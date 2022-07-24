/*
gcc -g -fno-stack-protector -no-pie main.c -o vuln
*/
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define FLAGSIZE 64

void win(int argument1) {
    char buf[FLAGSIZE];
    FILE *f = fopen("flag.txt", "r");
    
    if (argument1 == 0xdeadbeef) {
        printf("---------------------------------------\n");
        printf("DEADBEEEEF!! great job, here is a flag!\n");
        printf("---------------------------------------\n");
        
        fgets(buf, FLAGSIZE, f);
        printf(buf);
    } else {
        printf("Try harder!😅");
    }
    fclose(f);
    exit(0);
}

int main() {
    printf("Enter: ");
    char buffer[10];
    scanf("%s", buffer);
    printf("Hello, %s \n", buffer);
    return 0;
}
