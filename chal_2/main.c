/*
gcc -g -fno-stack-protector -no-pie main.c -o vuln
*/
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define FLAGSIZE 64

void win() {
    char buf[FLAGSIZE];
    FILE *f = fopen("flag.txt", "r");

    printf("---------------------------------------\n");
    printf("You did it! win function is called!\n");
    printf("---------------------------------------\n");

    fgets(buf, FLAGSIZE, f);
    printf(buf);

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
