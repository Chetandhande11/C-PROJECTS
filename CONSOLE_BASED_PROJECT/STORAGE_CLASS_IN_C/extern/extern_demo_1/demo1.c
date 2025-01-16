#include <stdio.h>

extern int num;

int main() {
    printf("Value of num from another file: %d\n", num);
    return 0;
}

