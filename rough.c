#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdint.h>
#include<math.h>

int main(int c, char ** args) {
    unsigned int a  = 1;
    //u_int16_t t = atoi(args[1]);
    int t = (int)(pow(2, 32) + 1) ;
    long unsigned int s = sizeof(int);
    printf("t is %lu\n", sizeof(short unsigned int));

    return 0;
}
