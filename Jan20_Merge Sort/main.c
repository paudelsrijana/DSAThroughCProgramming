#include <stdio.h>
void merge(int arr[], int low, int mid, int up)   // Function to merge two sorted sublists
{
    int i = low, j = mid + 1, k = 0, temp[up-low+1]; // Initialize indices for sublists and temp array
    while (i <= mid && j <= up) // Compare elements from both sorted halves
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++]; // Pick the smaller item
    while (i <= mid) temp[k++] = arr[i++]; // Copy remaining items from left half
    while (j <= up) temp[k++] = arr[j++]; // Copy remaining items from right half
    for (i = 0; i < k; i++) arr[low + i] = temp[i]; // Copy sorted result back to original array
}
void m_sort(int arr[], int low, int up)   // Recursive merge sort function
{
    if (low < up)   // Proceed if there is more than one element
    {
        int mid = (low + up) / 2; // Calculate the middle index
        m_sort(arr, low, mid); // Sort the left half recursively
        m_sort(arr, mid + 1, up); // Sort the right half recursively
        merge(arr, low, mid, up); // Merge the two sorted halves
    }
}
int main()
{
    int arr[] = {8, 5, 89, 30, 42};
    m_sort(arr, 0, 4); // Call merge sort on the array
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    return 0; //
}
