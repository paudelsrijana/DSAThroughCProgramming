#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

// Search in Circular Linked List
void search(struct node *start, int item) {
    if (start == NULL) {
        printf("List is empty");
        return;
    }

    struct node *tmp = start;
    int pos = 1;

    do {
        if (tmp->info == item) {
            printf("Item %d found at position %d\n", item, pos);
            return;
        }
        tmp = tmp->next;
        pos++;
    } while (tmp != start);

    printf("Item %d is not found in the list.\n", item);
}

// Display Circular Linked List
void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty");
        return;
    }

    struct node *ptr = start;
    printf("\nOur list elements are:\n");

    do {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    } while (ptr != start);
}

// Main function
int main() {
    struct node *start = NULL; //external pointer
    struct node *tmp, *end; //temporary pointers for new node creation and last node
    int i, n, data;

    printf("Enter number of values you want to store: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No value to process.");
        exit(1);
    }
    end = NULL; //initialize end pointer to null
    for (i = 1; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
    //dynamic memory allocation
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data; //use input data to new nodes info
        tmp->next = NULL;

        if (start == NULL) {
            start = tmp;
        } else {
            end->next = tmp; //previous last node to new node
        }
        end = tmp; //new node is current pointer
    }

    // Make the list circular
    end->next = start;

    display(start);

    // Demo search for 5
    search(start, 5);

    return 0;
}
