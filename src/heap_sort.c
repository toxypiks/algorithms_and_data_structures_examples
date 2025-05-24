#include <stdio.h>

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

int main(void)
{
    return 0;
}
