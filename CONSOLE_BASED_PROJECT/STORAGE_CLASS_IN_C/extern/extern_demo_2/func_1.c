#include <stdio.h>
#include <stdlib.h>

extern void print(void);
int main(void)
{
    printf("in func_1.c\n");
    print();
    return(0);
}