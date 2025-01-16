#include <stdio.h>
#include <stdlib.h>

static int global_var = 10;
void demo_static_global(void)
{
    printf("static global_var = %d\n",global_var);
}
void demo_static_local(void)
{
    static int static_var = 0;
    static_var = static_var+1;
    printf("Static var = %d\n",static_var);
}
void demo_2(void)
{
    global_var = 12;
    printf("global_var = %d\n",global_var);
}
int main(void)
{
    demo_static_local();
    demo_static_local();
    demo_static_local();
    demo_static_global();
    demo_2();
    return(0);
}

