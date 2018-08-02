#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int c, char ** args) {
    unsigned int a;
    unsigned int b;
    a = atoi(args[1]);
    b = atoi(args[1]);
    printf("%x\n", a);
    printf("%x\n", b);
    a = (a & 0x000000000F);
    b = (b & 0x00000000F0)>>4;

    printf("%x\n", a);
    printf("%x\n", b);

    return 0;
}