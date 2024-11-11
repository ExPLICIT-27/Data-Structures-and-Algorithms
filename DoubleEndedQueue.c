#include <stdio.h>
#include <stdlib.h>
#define max 10
int queue[max];
int front = -1, rear = -1;
int isFull(){
    return ((front == 0 && rear == max-1) || (front == rear+1));
}
int isEmpty(){
    return (front == -1);
}
void EnqueueFront(int data){
    if(!isFull()){
        if(front == -1){
            front = 0, rear = 0;
        }
        else if(front == 0){
            front = max-1;
        }
        else{
            front--;
        }
        queue[front] = data;
        printf("\n%d enqueued front.", data);
    }
    else{
        printf("\nQueue is full.");
    }
}
void EnqueueBack(int data){
    if(!isFull()){
        if(rear == -1){
            front = 0, rear = 0;
        }
        else if(rear == max-1){
            rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = data;
        printf("\n%d enqueued behind.", data);
    }
    else{
        printf("\nQueue is full.");
    }
}
void DequeueFront(){
    if(!isEmpty()){
        printf("\n%d dequeued front.", queue[front]);
        if(front == rear){
            front = -1, rear = -1;
        }
        else if(front == max-1){
            front = 0;
        }
        else{
            front++;
        }
    }
    else{
        printf("\nQueue is empty.");
    }
}
void DequeueBack(){
    if(!isEmpty()){
        printf("\n%d dequeued back.", queue[rear]);
        if(front == rear){
            front = -1, rear = -1;
        }
        else if(rear == 0){
            rear = max-1;
        }
        else{
            rear--;
        }
    }
    else{
        printf("\nQueue is empty.");
    }
}
void display(){
    if(!isEmpty()){
        printf("\nQueue status: ");
        int i = front;
        while(i != rear){
            printf("%d ", queue[i]);
            i = (i+1)%max;
        }
    }
    else{
        printf("\nQueue is empty.");
    }
}
int main(){
    printf("\nChoices:\n1. EnqueueFront\n2. EnqueueBack\n3. DequeueFront\n4. DequeueBack\n5. Display\n6. Exit");
    int choice = -1, temp;
    do{
        printf("\nEnter choice: ");
        scanf(" %d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter value: ");
                scanf(" %d", &temp);
                EnqueueFront(temp);
                break;
            case 2:
                printf("\nEnter value: ");
                scanf(" %d", &temp);
                EnqueueBack(temp);
                break;
            case 3:
                DequeueFront();
                break;
            case 4:
                DequeueBack();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }while(choice != 6);
    return 0;
}