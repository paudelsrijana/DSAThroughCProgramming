#include <stdio.h>
#include<stdlib.h>
#define MAX 5   // Maximum size of circular queues
int cqueue_arr[MAX];
int front = -1, rear = -1;

// Check if queue is full
int isFull()
{
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Insert element at the rear
void insert(int item)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    if (rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;

    cqueue_arr[rear] = item;
}

// Check if queue is empty
int isEmpty()
{
    return (front == -1);
}

// Delete element from the front
void delete()
{
    int item;
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item = cqueue_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }

    printf("Deleted item is %d ", item);
}

// Display queue elements
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    if (front <= rear)
    {
        while (i <= rear)
            printf("%d ", cqueue_arr[i++]);
    }
    else
    {
        while (i < MAX)
            printf("%d ", cqueue_arr[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", cqueue_arr[i++]);
    }
    printf("\n");
}

// Main function
int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    delete();
    display();
    insert(40);
    insert(50);
    insert(60);   // Tests circular behavior
    display();
    return 0;
}
