#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int stack[MAX_SIZE];//Global stack declaration
int top=-1; //Global top index declaration and initialization
//function to push an element to our stack
void push(){
    int item;
    printf("Enter an item to push: ");
    scanf("%d", &item);
    if(top == MAX_SIZE-1){
        printf("Stack Overflow");
        exit(1);
    }
    stack[++top] = item;
    printf("Pushed %d Successfully. New top index is %d \n", item, top);
}
//Function to delete (POP) element from stack
void pop(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        int item = stack[top];
        top = top-1;
        printf("Deleted item is: %d\n", item);
    }
}
//Function to display stack elements
void display(){
    if(top==-1){
        printf("Stack is empty \n");
        exit(1);
    }
    printf("Current elements from top to bottom in stack are:  ");
    for(int i=top; i>=0;i--){
        printf("%d\t", stack[i]);
    }
}
int main()
{
    printf("There is no error!\n");
    push();
    push();
    push();
    pop();
    display();
    printf("current stack size is: %d \n", top+1);//size of stack
    printf("Top Element is : %d \n", stack[top]);//peek top element of stack
    return 0;
}
