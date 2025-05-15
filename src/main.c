#include <stdio.h>


void swap(int *x, int *y)
{
    int tmp = *x; // value from x into tmp
    *x = *y;
    *y = tmp;
}

int main (void)
{
    int x = 4;
    int y = 10;
    swap(&x, &y);
    printf("x: %d y: %d\n", x, y);
    return 0;
}
