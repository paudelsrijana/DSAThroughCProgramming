#include <stdio.h>
int main()
{
    int arr[] = {42, 49, 8, 25, 52};
    int n = 5; // Define the number of elements
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i; // Assume the first unsorted item is the smallest
        for (j = i + 1; j < n; j++)   // Search through the remaining unsorted part
        {
            if (arr[j] < arr[min_idx]) // If a smaller item is found
                min_idx = j; // Update the index of the smallest item
        }
        if (min_idx != i)   // If the smallest item is not already in place
        {
            temp = arr[i]; // Perform swap: store current item in temp
            arr[i] = arr[min_idx]; // Place smallest item in current position
            arr[min_idx] = temp; // Move current item to where the smallest was
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]); // Print the sorted array
    return 0;
}
