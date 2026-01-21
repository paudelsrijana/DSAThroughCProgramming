#include <stdio.h>
void quick(int arr[], int low, int up)   // Recursive quick sort function
{
    if (low >= up)
        return; // Base case: if list has 0 or 1 element, it's sorted
    int i = low + 1, j = up, pivot = arr[low], temp; // Choose first element as pivot
    while (i <= j)   // Loop until indices cross each other
    {
        while (i < up && arr[i] < pivot)
            i++; // Move i right to find element >= pivot
        while (arr[j] > pivot)
            j--; // Move j left to find element <= pivot
        if (i < j)   // If pointers haven't crossed, swap elements
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; // Perform swap
            i++;
            j--; // Increment i and decrement j
        }
        else i++;   // Otherwise just move i forward to terminate
    }
    arr[low] = arr[j];
    arr[j] = pivot; // Place pivot in its final sorted position
    quick(arr, low, j - 1); // Recursively sort the left sublist
    quick(arr, j + 1, up); // Recursively sort the right sublist
}
int main()   // Start of main function
{
    int arr[] = {48, 44, 19, 59, 72}; // Initialize an unsorted array
    quick(arr, 0, 4); // Call quick sort on the full array range
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]); // Print the sorted array
    return 0;
}
