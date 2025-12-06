#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int stack[MAX_SIZE]; // Global stack
int top = -1;        // Global top index

// Function to push an element
void push()
{
    int item;
    printf("Enter the integer item to push: ");
    scanf("%d", &item);
    if (top == MAX_SIZE - 1)
    {
        printf("*** Stack Overflow Detected ***\n");
        return;
    }
    top=top+1;
    stack[top] = item;
    printf("Pushed %d successfully. New top index is %d.\n", item, top);
}

// Function to pop an element
void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int item = stack[top];
        top = top -1;
        printf("Deleted item is: %d\n", item);
    }
}

// Function to display stack elements
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Current elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

// Function to calculate stack size
void size()
{
    printf("Current stack size: %d\n", top + 1);
}

// Function to peek top element
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty, nothing to peek.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Size\n");
        printf("5. Peek\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            size();
            break;
        case 5:
            peek();
            break;
        case 0:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
