#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

// Structure Definition for a Circular Doubly Linked List Node
struct node
{
    struct node *prev; // Pointer to the predecessor node
    int info;          // Data field
    struct node *next; // Pointer to the successor node
};

// Traversal for Circular Doubly Linked List
void display(struct node *start)
{
    struct node *tmp;
    if(start == NULL)
    {
        printf("List is empty");
        exit(1);
    }

    tmp = start;
    printf("\nOur Circular Doubly Linked List is: ");

    do
    {
        printf("%d  ", tmp->info);
        tmp = tmp->next;
    }
    while(tmp != start);    // Stop when back at start node
}

// Main function for testing
int main()
{
    int i, n, data;
    struct node *start = NULL;
    struct node *tmp; // temporary node for new allocated node
    struct node *end = NULL; // to track current last node

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("nothing to process.");
        exit(1);
    }

    printf("Enter element 1: "); // Insert the first node (special case handling)
    scanf("%d", &data);

    // Allocate memory using malloc()
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("NO Space available");
        exit(1);
    }

    tmp->info = data;
    start = end = tmp;

    // For a circular list: first node points to itself
    tmp->prev = tmp;
    tmp->next = tmp;

    // Insert remaining nodes at the end
    for (i = 2; i <= n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &data);

        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;

        // Link the new node in circular manner
        tmp->next = start;    // New node points to first node
        tmp->prev = end;      // New node's prev is old last node

        end->next = tmp;      // Old last node now points to new node
        start->prev = tmp;    // First node's prev updated to new last node

        end = tmp; // New node becomes the last node
    }

    display(start);
    return 0;
}
