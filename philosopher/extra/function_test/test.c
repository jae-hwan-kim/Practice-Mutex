#include <stdio.h>

void    test2(int *b)
{
    *b = 5;
}

void    test(int **a)
{
    test2(a);
    // test2(*a);
}

int main(void)
{
    int *a;
    int b = 3;

    a = &b;
    test(&a);
    printf("%d\n", *a);
}