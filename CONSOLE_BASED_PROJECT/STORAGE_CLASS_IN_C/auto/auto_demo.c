#include <stdio.h>
#include <stdlib.h>

//auto int num1 = 20; auto is specifies only for local variable inside the function.
void auto_demo(void)
{
    auto int num = 10;
    printf("num = %d\n",num);
}
int main(void)
{
    auto_demo();
    return(0);
}

