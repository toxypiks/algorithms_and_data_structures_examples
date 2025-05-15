#include <stdio.h>

#define ARR_LEN(xs) sizeof(xs)/sizeof(xs[0])

void swap(int *x, int *y)
{
    int tmp = *x; // value from x into tmp
    *x = *y;
    *y = tmp;
}

void quicksort(float **data, size_t *left, size_t *right)
{
    if (*right <= *left) {
        return;
    }
    // WIP
}

int main (void)
{
    int x = 4;
    int y = 10;
    swap(&x, &y);
    printf("x: %d y: %d\n", x, y);

    float my_array[7] = {3, 7, 4, 8, 23, 45, 2};
    printf("%d\n", ARR_LEN(my_array));
    return 0;
}
