#include <stdio.h>
void heapify(int arr[], int n, int i) { // Function to heapify a subtree rooted at index i
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index
    // If left child exists and is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child exists and is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not root, swap and continue heapify
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
// Main function to perform heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main() {
    int arr[] = {25, 57, 48, 37, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
