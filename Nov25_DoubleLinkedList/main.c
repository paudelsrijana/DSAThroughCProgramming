#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

// Structure Definition for a Doubly Linked List Node
struct node {
    struct node *prev; // Pointer to the predecessor node
    int info;          // Data field
    struct node *next; // Pointer to the successor node
};

// Main function for testing
int main() {
    int i, n, data;
    struct node *start = NULL;
    struct node *tmp;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    if (n <= 0){
        printf("nothing to process.");
        exit(1);
    }

    printf("Enter element 1: ");//Insert the first node (special case handling for empty list)
    scanf("%d", &data);

    // Allocate memory using malloc()
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp==NULL){
        printf("NO Space available");
        exit(1);
    }
    tmp->info = data;
    tmp->prev = NULL; // First node's 'prev' is NULL
    tmp->next = NULL; // First node's 'next' is NULL if it's the only node
    start = tmp;      // Update the head pointer

    // Insert remaining nodes at the end (for simplicity, using basic allocation logic)
    for (i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);

        struct node *p = start;
        // Traverse to find the last node
        while (p->next != NULL) {
            p = p->next;
        }

        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->next = NULL; // New node is the last one
        tmp->prev = p;    // New node points back to the previous last node 'p'
        p->next = tmp;    // Old last node 'p' points forward to the new node 'tmp'
    }
    return 0;
}
