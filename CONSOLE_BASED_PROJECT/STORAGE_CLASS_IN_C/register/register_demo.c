#include <stdio.h>

void demo_Register(void)
 {
    register int i; 
    int sum = 0;
    for (i = 0; i < 10; i++)
    {
        sum = sum + i;
    }

    printf("Sum of first 10 integers = %d\n", sum);
}

int main() {
    demo_Register();
    return 0;
}
