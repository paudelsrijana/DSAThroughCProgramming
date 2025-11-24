#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};


//add at beginning
struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp, *p;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    if (start == NULL)
    {
        tmp->next = tmp;   // circular list, single node points to itself
        start = tmp;
        return start;
    }

    // find the last node
    p = start;
    while (p->next != start)
        p = p->next;

    tmp->next = start;  // new node points to old start
    p->next = tmp;      // last node points to new node
    start = tmp;        // update start

    return start;
}

// Search in Circular Linked List
void search(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }

    struct node *tmp = start;
    int pos = 1;

    do
    {
        if (tmp->info == item)
        {
            printf("Item %d found at position %d\n", item, pos);
            return;
        }
        tmp = tmp->next;
        pos++;
    }
    while (tmp != start);

    printf("Item %d is not found in the list.\n", item);
}

//delete first node
struct node *del(struct node *start)
{
    struct node *tmp, *p;

    if (start == NULL)
    {
        printf("\n empty list, nothing to delete");
        exit(1);
    }

    // case: only one node in the list
    if (start->next == start)
    {
        free(start);
        return NULL;
    }

    // find last node
    p = start;
    while (p->next != start)
        p = p->next;

    tmp = start;          // first node to delete
    start = start->next;  // move start to next node
    p->next = start;      // last node links to new start

    free(tmp);            // free deleted node

    return start;
}

// Display Circular Linked List
void display(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }

    struct node *ptr = start;
    printf("\nOur list elements are:\n");

    do
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    while (ptr != start);
}

// Main function
int main()
{
    struct node *start = NULL; //external pointer
    struct node *tmp, *end; //temporary pointers for new node creation and last node
    int i, n, data;

    printf("Enter number of values you want to store: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("No value to process.");
        exit(1);
    }
    end = NULL; //initialize end pointer to null
    for (i = 1; i <= n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        //dynamic memory allocation
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data; //use input data to new nodes info
        tmp->next = NULL;

        if (start == NULL)
        {
            start = tmp;
        }
        else
        {
            end->next = tmp; //previous last node to new node
        }
        end = tmp; //new node is current pointer
    }

    // Make the list circular
    end->next = start;

    //Traversal of single linked list
    display(start);
    //searching in single linked list
    search(start, 5);
    //adding element at the beginning of the linked list
    start = addatbeg(start, 89);
    display(start);
    //deleting element at beginning of the linked list
    start = del(start);
    display(start);

    return 0;
}
