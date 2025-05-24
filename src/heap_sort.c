#include <stdio.h>

#define ARRAY_LEN(xs) sizeof(xs)/sizeof(xs[0])

void heapify(int *data, int n, int i)
{
    // n = array_len, i = index array
    int largest = i;

    // left child node index
    int l = 2 * i + 1;

    // right child node index
    int r = 2 * i + 2;

    // if left child node is larger than root
    if (l < n && data[l] > data[largest]) {
        largest = l;
    }

    // if right child node is larger than root
    if (r < n && data[r] > data[largest]) {
        largest = r;
    }

    // if largest is not at same index as root swap value of corresponding child node with value of root in array
    if (largest != i) {
        int tmp = data[i];
        data[i] = data[largest];
        data[largest] = tmp;

        // recursively heapify the affected sub-trees
        heapify(data, n, largest);
    }

}

void heap_sort(int *data, int n)
{
    // rearrange initial array into max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(data, n , i);
    }

    // put biggest elements to the left one by one
    for (int i = n - 1; i > 0; i--) {

        // move current root to end of array
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;

        // call max heapify on remaining unordered array
        heapify(data, i, 0);
    }
}

void print_data(int *data, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main(void)
{
    int data[] = {9, 4, 3, 8, 10, 2, 5};

    heap_sort(data, ARRAY_LEN(data));
    print_data(data, ARRAY_LEN(data));
    return 0;
}
