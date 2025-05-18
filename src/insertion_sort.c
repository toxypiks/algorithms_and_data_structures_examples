#include <stdio.h>

#define ARRAY_LEN(xs) sizeof(xs)/sizeof(xs[0])

void insertion_sort(int *data, size_t data_size)
{
    for (int i = 1; i < data_size; ++i) {
        int j = i - 1;
        int key = data[i];

        while (key < data[j]) {
            data[j + 1] = data [j];
            j = j - 1;
        }
        data[j + 1] = key;
    }

}

int main(void)
{
    int my_data[] = {5, 8, 3, 2, 1};
    insertion_sort(my_data, ARRAY_LEN(my_data));
    for (size_t i = 0; i < ARRAY_LEN(my_data); ++i) {
        printf("%d", my_data[i]);
    }
    printf("\n");
    return 0;
}
