#include <stdio.h>
#include <stdlib.h>
#define MAX 5 //define maximum capacity of array/storage
//initialization
int queue_arr[MAX];
int front = -1;
int rear = -1;

//check for overflow condition
int isFull(){
    return(rear==MAX-1);
}
//Enqueue Operation
void insert(int item){
    if(isFull()){
        printf("Memory Overflow");
        return;
    }
    if(front==-1)
        front=0;
    rear=rear+1;
    queue_arr[rear]=item;
    printf("Inserted %d\n", item);
}

//memory unuderflow
int isEmpty(){
    return(front==-1||front>rear);
}

//delete operation for dequeue
void delete(){
    if(isEmpty()){
        printf("Queue underflow");
        exit(1);
    }
    int item=queue_arr[front];
    front=front+1;
    printf("deleted item is %d", item);
}

int main()
{
    int item;
    printf("Enter item:");
    scanf("%d", &item);
    insert(item);
    delete();

    return 0;
}
