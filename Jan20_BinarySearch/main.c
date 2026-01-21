#include <stdio.h>

// Binary search
int BinarySearch(int arr[], int size, int item) {
    int low = 0, up = size - 1, mid;
    while (low <= up) {
        mid = (low + up) / 2;
        if (item > arr[mid])
            low = mid + 1; // Search right half
        else if (item < arr[mid])
            up = mid - 1;  // Search left half
        else
            return mid;    // Item found
    }
    return -1;
}

int main() {
    // Sorted array initialized explicitly using example from
    int arr[] = {1, 3, 4, 5, 17, 18, 31, 33};
    int size = 8;
    int item = 1;
    int index = BinarySearch(arr, size, item);

    if (index == -1)
        printf("%d not found in array\n", item);
    else
        printf("%d found at position %d\n", item, index);

    return 0;
}
