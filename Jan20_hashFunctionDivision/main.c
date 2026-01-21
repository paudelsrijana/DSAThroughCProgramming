#include <stdio.h>
#define SIZE 11 // Table size is 11
int main() {
    // Basic array for memory storage
    int hashTable[SIZE];
    int keys[] = {29, 46, 36, 43, 10};
    int i, index;
    // Initialize memory to -1 to show it is empty
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    // Process and insert each key
    for (i = 0; i < 5; i++) {
        // Compute hash value using division method
        index = keys[i] % SIZE;
        // Simple insertion: Place key at computed index
        // Note: For simplicity, this overwrites if a collision occurs
        hashTable[index] = keys[i];
        printf("Key %d hashed to index %d and inserted.\n", keys[i], index);
    }

    // Displaying the resulting memory
    printf("\nHash Table Memory Content:\n");
    for (i = 0; i < SIZE; i++) {
        printf("Index [%d]: %d\n", i, hashTable[i]);
    }
    return 0;
}
