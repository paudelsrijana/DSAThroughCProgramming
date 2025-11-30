#include <stdio.h>
#include <stdlib.h>

// Structure Definition for a Circular Doubly Linked List Node
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

// Display Function
void display(struct node *start)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *tmp = start;

    printf("\nOur Circular Doubly Linked List is: ");
    do
    {
        printf("%d  ", tmp->info);
        tmp = tmp->next;
    }
    while(tmp != start);
    printf("\n");
}


/* ---------------- INSERT AT END ---------------- */
struct node* insert_end(struct node *start, struct node *end, int data)
{
    struct node *tmp = malloc(sizeof(struct node));
    if(!tmp)
    {
        printf("No space available\n");
        return end;
    }

    tmp->info = data;

    if(start == NULL)
    {
        tmp->next = tmp;
        tmp->prev = tmp;
        return tmp;
    }

    tmp->next = start;
    tmp->prev = end;

    end->next = tmp;
    start->prev = tmp;

    return tmp;  // new end
}

/* ---------------- DELETE AT BEGINNING ---------------- */
struct node* delete_begin(struct node *start, struct node *end)
{
    if(start == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    // Only one node
    if(start == end)
    {
        free(start);
        return NULL;
    }

    struct node *newstart = start->next;

    end->next = newstart;
    newstart->prev = end;

    free(start);
    return newstart;
}

/* ---------------- DELETE AT END ---------------- */
struct node* delete_end(struct node *start, struct node *end)
{
    if(start == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    // Only one node
    if(start == end)
    {
        free(start);
        return NULL;
    }

    struct node *newend = end->prev;

    newend->next = start;
    start->prev = newend;

    free(end);
    return newend;
}

/* ---------------- DELETE AT SPECIFIED POSITION ---------------- */
struct node* delete_pos(struct node *start, struct node *end, int pos)
{
    if(start == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if(pos == 1)
        return delete_begin(start, end);

    struct node *p = start;

    for(int i = 1; i < pos; i++)
    {
        p = p->next;
        if(p == start)
        {
            printf("Position out of range.\n");
            return start;
        }
    }

    if(p == end)
        return delete_end(start, end);

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
    return start;
}

/* ---------------- MAIN FUNCTION ---------------- */
int main()
{
    int i, n, data, choice, pos;
    struct node *start = NULL;
    struct node *end = NULL;
    struct node *tmp;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Nothing to process.\n");
        exit(1);
    }

    printf("Enter element 1: ");
    scanf("%d", &data);

    tmp = malloc(sizeof(struct node));
    tmp->info = data;

    start = end = tmp;
    tmp->next = tmp;
    tmp->prev = tmp;

    for (i = 2; i <= n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &data);

        end = insert_end(start, end, data);
    }

    display(start);

    while(1)
    {
        printf("\n--- MENU ---");
        printf("\n1. Delete at Beginning");
        printf("\n2. Delete at End");
        printf("\n3. Delete at Position");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            start = delete_begin(start, end);
            if(start == NULL) end = NULL;
            break;

        case 2:
            end = delete_end(start, end);
            if(end == NULL) start = NULL;
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            start = delete_pos(start, end, pos);
            if(start == NULL) end = NULL;
            break;

        case 4:
            display(start);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
