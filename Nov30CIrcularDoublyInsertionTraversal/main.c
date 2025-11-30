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

/* ---------------- INSERT AT BEGINNING ---------------- */
struct node* insert_begin(struct node *start, struct node *end, int data)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("No space available\n");
        return start;
    }

    tmp->info = data;

    // If list empty
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

    return tmp;  // new start
}

/* ---------------- INSERT AT END ---------------- */
struct node* insert_end(struct node *start, struct node *end, int data)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("No space available\n");
        return end;
    }

    tmp->info = data;

    // If empty list
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

/* ---------------- INSERT AT SPECIFIED POSITION ---------------- */
struct node* insert_pos(struct node *start, struct node *end, int data, int pos)
{
    if(pos == 1)
        return insert_begin(start, end, data);

    struct node *p = start;
    int i;

    for(i = 1; i < pos - 1; i++)
    {
        p = p->next;
        if(p == start)
        {
            printf("Position out of range.\n");
            return start;
        }
    }

    if(p == end)
        return insert_end(start, end, data);

    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;

    tmp->next = p->next;
    tmp->prev = p;
    p->next->prev = tmp;
    p->next = tmp;

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

    tmp = (struct node*)malloc(sizeof(struct node));
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
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            start = insert_begin(start, end, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            end = insert_end(start, end, data);
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter data: ");
            scanf("%d", &data);
            start = insert_pos(start, end, data, pos);
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
