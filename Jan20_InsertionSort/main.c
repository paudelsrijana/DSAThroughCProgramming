#include <stdio.h>
int main()
{
    int arr[] = {82, 42, 49, 8, 25}; // Initialize an unsorted array
    int n = 5; // Define array size
    int i, k, key; // Declare variables for indices and current item
    for (k = 1; k < n; k++)   // Start from the second element (index 1)
    {
        key = arr[k]; // Pick the current element to be inserted
        for (i = k - 1; i >= 0 && key < arr[i]; i--)   // Shift larger items to the right
        {
            arr[i + 1] = arr[i]; // Move item one position to the right
        }
        arr[i + 1] = key; // Insert the key at its correct sorted position
    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
