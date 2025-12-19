#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front= NULL;
struct node *rear = NULL;
//insert data into dynamic queue
void insert(int item){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory overflow");
        exit(1);
    }
    temp->data=item;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next= temp;
    }
    rear=temp;
    printf("item %d inserted successfully \n", item);
}
//check if queue is empty
int isEmpty(){ //return(front==NULL);
    if(front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//delete function
void delete(){
    struct node *temp;
    int item;
    if(isEmpty()){
        printf("queue is empty \n");
        exit(1);
    }
    temp = front;
    item = temp->data;
    front = front->next;
    if(front==NULL){
        rear=NULL;
    }
    free(temp);
    printf("\n Deleted item is %d", item);
}
//display queue items
void display(){
    struct node *temp;
    if(isEmpty()){
        printf("Queue is empty.");
        exit(1);
    }
    printf("\n Item from Front to Rear: \n");
    temp=front;
    while(temp!=NULL){
        printf("%d \t", temp->data);
        temp=temp->next;
    }
}
int main()
{
    insert(5);
    insert(10);
    insert(15);
    display();
    delete();
    display();
    return 0;
}
