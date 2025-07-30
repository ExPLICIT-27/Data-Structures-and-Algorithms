#include <stdio.h>
#include <stdlib.h>
#define max 10
int queue[max];
int front = -1, rear = -1;
int isEmpty(){
    return front == -1;
}
int isFull(){
    return ((rear+1)%max == front);
}
void Enqueue(int data){
    if(!isFull()){
        rear = (rear+1)%max;
        queue[rear] = data;
        printf("\n%d enqueued", data);
        if(front == -1){
            front = 0;
        }
    }
    else{
        printf("\nQueue is full.");
    }
}
void Dequeue(){
    if(!isEmpty()){
        printf("\n%d dequeued.", queue[front]);
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1)%max;
        }
    }
    else{
        printf("\nQueue is empty.");
    }
}
void Display(){
    if(!isEmpty()){
        printf("\nQueue status: ");
        int i = front;
        while(i != rear){
            printf("%d ",queue[i]);
            i = (i+1)%max;
        }
        printf("%d ", queue[i]);
    }
    else{
        printf("\nEmpty queue.");
    }
}
int main(){
    printf("\nChoices:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");;
    int choice = -1, temp;
    do{
        printf("\nEnter choice: ");
        scanf(" %d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter value: ");
                scanf(" %d", &temp);
                Enqueue(temp);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("\nExiting....");
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }while(choice != 4);
    return 0;
}