#include <stdio.h>
#include <unistd.h>

#define ARR_LEN(xs) sizeof(xs)/sizeof(xs[0])

void print_data(int* my_array, size_t left, size_t right) {
  for (size_t i = left; i <= right; ++i) {
      printf("%d,", my_array[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int tmp = *x; // value from x into tmp
    *x = *y;
    *y = tmp;
}

void quicksort_recursiv(int *data, int left, int right, int level)
{
    int pivot_idx = left + (right - left)/2;
    int pivot = data[pivot_idx];
    int i, j;
    i = left;
    j = right;

    if (j <= i) {
        return;
    }
    do {
        while (data[i] < pivot) {
            ++i;
        }
        while (data[j] > pivot) {
            --j;
        }
        if (i < j) {
            swap(&data[i], &data[j]);
        }
    }
    while (i < j);
    if (left < j) quicksort_recursiv(data, left, j - 1, level++);
    if (i < right) quicksort_recursiv(data, j + 1, right, level++);
}

int main (void)
{
    int x = 4;
    int y = 10;
    swap(&x, &y);
    printf("x: %d y: %d\n", x, y);

    int my_array[7] = {3, 7, 4, 8, 23, 45, 2};

    quicksort_recursiv(my_array, 0, ARR_LEN(my_array)-1, 0);
    print_data(my_array, 0, ARR_LEN(my_array) - 1);
    return 0;
}
