#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *top = NULL; // Global top pointer

// Push element to stack
void push(int item)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    tmp->info = item;  // Set data
    tmp->link = top;   // Point to previous top
    top = tmp;         // Update top
}

// Pop element from stack
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct node *tmp = top;
    int item = tmp->info;

    top = top->link;   // Move top to next node
    free(tmp);         // Free removed node

    return item;
}

// Peek top element
int peek()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->info;
}

// Display all elements
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    struct node *ptr = top;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->info);
        ptr = ptr->link;
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display item at the top\n");
        printf("4. Display all items of the stack\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            item = pop();
            printf("Popped item: %d\n", item);
            break;

        case 3:
            printf("Item at the top: %d\n", peek());
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Wrong choice. Please try again.\n");
        }
    }
}
