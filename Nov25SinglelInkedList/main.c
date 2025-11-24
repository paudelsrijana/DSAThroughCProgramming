#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
//Inserting node at beginning of the list
struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;
    tmp= (struct node *)malloc(sizeof(struct node)); //allocate space for new node
    tmp->info = data;
    tmp->next = start; //pointing start to next of new node
    start = tmp; //new added node becomes start
    return start;
};

//Deleting node at beginning of the list
struct node *del(struct node *start){
    struct node *tmp;//temporary node that holds node to be deleted
    if(start==NULL){
        printf("\n empty list, nothing to delete");
        exit(1);
    }
    tmp = start;//store address of first node in tmp
    start = start->next; //updates head pointer to address of next node
    free(tmp);//returns memory used by deleted node
    return start;
};

//Searching in Single Linked List
void search(struct node *start, int item)
{
    struct node *tmp; // tmp for temporary node
    tmp = start; //starts at head
    int pos = 1; //to track position of search item
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    while(tmp!=NULL)
    {
        if(tmp->info==item)
        {
            printf("\n Item %d is found in position %d of linked list", item, pos);
            return;
        }
        tmp=tmp->next;
        pos++;
    }
    printf("\n Item %d is not found in our linked list. ", item);
}


// Traversal in Single Linked List
void display(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("List is empty ");
        return;
    }
    ptr = start;
    printf("\n our list elements are: \n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *start = NULL;
    struct node *tmp, *end;
    int i, n, data;
    printf("Enter number of values you want to store :");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("No value to process.");
        exit(1);
    }
    end = NULL;
    for (i = 1; i <= n; i++)
    {
        printf("Enter element %d:", i);
        scanf("%d", &data);
        // Allocate and initialize new node
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->next = NULL; // new node is always last node
        if (start == NULL)
        {
            start = tmp;
        }
        else
        {
            end->next = tmp;
        }
        end = tmp;
    }
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

