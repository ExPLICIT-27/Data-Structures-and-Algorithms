#include <stdio.h>
#include <stdlib.h>
#define max 50
int main(){
    int queue[max];
    int front = -1, rear = -1;
    printf("\nChoices:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");;
    int choice = -1, temp;
    do{
        printf("\nEnter choice: ");
        scanf(" %d", &choice);
        switch(choice){
            case 1:
                if(rear < 50){
                    printf("\nEnter element to be enqueued: ");
                    scanf(" %d", &temp);
                    queue[++rear] = temp;
                }
                else{
                    printf("\nQueue Full");
                }
                break;
            case 2:
                if(front < rear){
                    printf("\nDequeued element: %d", queue[++front]);
                }
                else{
                    printf("\nQueue is empty");
                }
                break;
            case 3:
                if(front < rear){
                    printf("\nQueue status: ");
                    for(int i = front+1; i <= rear; i++){
                        printf("%d ", queue[i]);
                    }
                }
                else{
                    printf("\nEmpty queue");
                }
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