#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;   // Lower value = Higher priority
    int info;
    struct node *link;
} *front = NULL; // front always points to highest-priority element

// Insert based on priority (sorted insertion)
void insert(int item, int item_priority)
{
    struct node *tmp, *p;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    tmp->priority = item_priority;

  /*
       Case 1:
       Queue is empty OR New node has higher priority than the front node
       (smaller priority value means higher priority)
    */
    if (front == NULL || item_priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }
    else
    {
        /*
           Case 2:
           Find the correct position so that the list remains sorted by priority.
           Traverse until next node has higher priority than new node
        */
        p = front;
        while (p->link != NULL && p->link->priority <= item_priority)
            p = p->link;

        tmp->link = p->link;
        p->link = tmp;
    }
}

// Delete highest priority element
int del()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct node *tmp = front;
    int item = tmp->info;

    front = front->link;
    free(tmp);

    return item;
}

// Display queue
void display()
{
    struct node *ptr = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue (Priority : Item): ");
    while (ptr != NULL)
    {
        printf("[%d : %d] ", ptr->priority, ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}

// Main function
int main()
{
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);
    insert(40, 0);

    display();

    printf("Deleted item: %d\n", del());
    display();

    printf("Deleted item: %d\n", del());
    display();

    return 0;
}
