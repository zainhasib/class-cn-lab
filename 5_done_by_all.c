// Done by all

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {

    unsigned int a;
    unsigned int b;
    unsigned int c;
    c = b = a = 0xAB20AB;
    printf("Enter the number : ");
    scanf("%d", &a);
    c = b = a;
    unsigned char * ap;
    ap = (unsigned char *) &a;

    printf("The variable is %x\n", a);

    a = (a & 0x0000FF);
    b = (b & 0x00FF00)>>8;
    c = (c & 0xFF0000)>>16;

    if(a == c) {
        printf("Equal first byte and last byte\n");
        printf("\nEnter the number : ");
        scanf("%d", &a);
        c = b = a;
        
        a = (a & 0x0000FF);
        b = (b & 0x00FF00)>>8;
        c = (c & 0xFF0000)>>16;
        ap = (unsigned char *) &a;
    }

    if(*ap == a) {
        printf("Little Endian\n");
    }else {
        printf("Big Endian\n");
    }

    printf("%x\n", a);
    printf("%x\n", b);
    printf("%x\n", c);
    printf("%x\n", ap);

    return 0;
}