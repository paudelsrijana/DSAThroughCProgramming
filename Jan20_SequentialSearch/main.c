#include <stdio.h>
// Sequential search function
int LinearSearch(int arr[], int n, int item)
{
    int i = 0;
    while (i < n && item != arr[i])
    {
        i++;
    }
    if (i < n)
        return i; // Return index if found
    else
        return -1;      // Return -1 if unsuccessful
}
int main()
{
    // Array initialized explicitly with values from source
    int arr[] = {25, 57, 48, 37, 12, 92, 86, 33};
    int n = 8;     // Size of the array
    int item = 22; // Search argument defined in the code
    int index = LinearSearch(arr, n, item);
    if (index == -1)
        printf("%d not found in array\n", item);
    else
        printf("%d found at position/index %d\n", item, index); // Output: 12 found at position 4
    return 0;
}
