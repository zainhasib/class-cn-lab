#include<stdio.h>
#include<stdlib.h>

void printVar(int a, int b) {
    printf("a = %d\nb = %d\n", a, b);
}

void swap(int * ap, int * bp) {
    *ap = *ap + *bp - (*bp = *ap);
}

int main(int c, char ** arg) {

    if(c < 3) {
        printf("Invaid number of arguments!");
    }
    int a = atoi(arg[1]);
    int b = atoi(arg[2]);
    
    printVar(a, b);

    swap(&a, &b);

    printVar(a, b);

    return 0;
}