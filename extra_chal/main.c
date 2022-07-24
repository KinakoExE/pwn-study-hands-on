/*
gcc -g -fno-stack-protector -no-pie main.c -o vuln
*/
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define FLAGSIZE 64

int flag = 0;

void win(int argument1) {
    char buf[FLAGSIZE];
    FILE *f = fopen("flag.txt", "r");

    if (argument1 == 0xdeadbeef) {
        printf("Hmm deadbeef check is ok...\n");
        if (flag == 1) {
            printf("---------------------------------------\n");
            printf("Finally you mastered today's topic👍!!!\n");
            printf("---------------------------------------\n");
            
            fgets(buf, FLAGSIZE, f);
            printf(buf);
        } else {
            printf("The goal is clooooooose!!!\n");
            printf("Try much, much harderrrrrrr!!!\n");
        }
    } else {
        printf("Try much harder!😅\n");
    }
    fclose(f);
    exit(0);
}

void jump(int a, int b) {
    if (a == 0xcafebabe && b == 0xbadcab1e) {
        flag = 1;
    } else {
        printf("Try much harderrrrr!😁\n");
    }
}

int main() {
    printf("Enter: ");
    char buffer[10];
    scanf("%s", buffer);
    printf("Hello, %s \n", buffer);
    return 0;
}
