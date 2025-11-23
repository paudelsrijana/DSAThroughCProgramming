#include <stdio.h>
#include <stdlib.h>
struct node
{
  int info;
  struct node *next;
};
//Searching in Single Linked List
void search(struct node *start, int item){
    struct node *tmp; // tmp for temporary node
    tmp = start; //starts at head
    int pos = 1; //to track position of search item
    while(tmp!=NULL){
        if(tmp->info==item){
            printf("Item %d is found in position %d of linked list", item, pos);
            return;
        }
        tmp=tmp->next;
        pos++;
    }
    printf("Item %d is not found in our linked list. ", item);
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
  display(start);
  search(start, 5);
  return 0;
}

