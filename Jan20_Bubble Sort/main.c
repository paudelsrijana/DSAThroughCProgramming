#include <stdio.h>
int main()
{
    int arr[] = {40, 20, 50, 60, 30, 10};
    int n = 6;
    int i, j, temp, swapped; //
    for (i = 0; i < n - 1; i++)   // Outer loop for number of passes
    {
        swapped = 0; // Initialize swapped flag to 0 for each pass
        for (j = 0; j < n - 1 - i; j++)   // Inner loop for comparing adjacent items
        {
            if (arr[j] > arr[j + 1])   // If current item is greater than next
            {
                temp = arr[j]; // Store current item in temporary variable
                arr[j] = arr[j + 1]; // Move smaller item to the left
                arr[j + 1] = temp; // Move larger item to the right
                swapped = 1; // Mark that a swap occurred
            }
        }
        if (swapped == 0)
            break; // If no swaps happened, the list is sorted
    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]); // Print the sorted array
    return 0;
}
