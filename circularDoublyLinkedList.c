#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
};
void insert(struct Node**, struct Node**, int);
void forwardTraversal(struct Node*);
void backwardTraversal(struct Node*);
int main(){
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int n, val;
    printf("\nEnter number of elements: ");
    scanf(" %d", &n);
    while(n--){
        printf("\nEnter the element: ");
        scanf(" %d", &val);
        insert(&head, &tail, val);
    }
    forwardTraversal(head);
    backwardTraversal(tail);
    return 0;
}
void backwardTraversal(struct Node *tail){
    struct Node *temp = tail;
    printf("\nBackward Traversal: ");
    do{
        printf("%d->", temp->data);
        temp = temp->prev;
    }while(temp != tail);
    printf("Tail");
}
void forwardTraversal(struct Node *head){
    struct Node *temp = head;
    printf("\nForward Traversal: ");
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("Head");
}
void insert(struct Node **head, struct Node **tail, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    if(*head == NULL){
        temp->next = temp;
        temp->prev = temp;
        *head = temp, *tail = temp;
    }
    else{
        temp->next = *head;
        temp->prev = *tail;
        (*tail)->next = temp;
        *tail = temp;
        (*head)->prev = *tail;
    }
}