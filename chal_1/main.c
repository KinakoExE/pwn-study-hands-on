/*
gcc -g -fno-stack-protector main.c -o vuln
*/
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define FLAGSIZE 64

void handler(int sig) {
    char buf[FLAGSIZE];
    FILE *f = fopen("flag.txt", "r");
    
    printf("---------------------------------------\n");
	printf("Detecting SIGSEGV signal! BOF!\n");
    printf("---------------------------------------\n");

    fgets(buf, FLAGSIZE, f);
    printf(buf);

    fclose(f);
	exit(0);
}

int main() {
    signal(SIGSEGV, handler);

    printf("Enter: ");
    char buffer[10];
    scanf("%s", buffer);
    printf("Hello, %s \n", buffer);
    return 0;
}
