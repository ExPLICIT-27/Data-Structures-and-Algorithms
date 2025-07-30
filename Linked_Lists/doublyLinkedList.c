#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
// note : in a doubly LL, whilst insertion at the front, you insert the element before head and make
// it the new head by pointing current heads prev to the newly inserted one and making the new
// ones prev point to NULL
void insertFront(struct Node **head, int val);
void insertBack(struct Node **head, int val);
void forwardTraversal(struct Node *head);
struct Node *findTail(struct Node *head);
void backwardTraversal(struct Node *head);
int main(){
    struct Node *head = NULL;
    int n;
    printf("\nEnter number of elements to be inserted(front): ");
    scanf(" %d", &n);
    int val;
    while(n--){
        printf("\nEnter the element: ");
        scanf(" %d", &val);
        insertFront(&head, val);
        forwardTraversal(head);
    }
    printf("\nEnter number of elements to be inserted(back): ");
    scanf(" %d", &n);
    while(n--){
        printf("\nEnter element: ");
        scanf(" %d", &val);
        insertBack(&head, val);
        backwardTraversal(head);
    }
    return 0;
}
void insertFront(struct Node **head, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *head;
    temp->prev = NULL;
    if(*head != NULL){
        (*head)->prev = temp;
    }
    *head = temp;
}
void insertBack(struct Node **head, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL; // we will change this later on, if the linked list is not empty
    if(*head == NULL){
        *head = temp;
    }
    else{
        struct Node *curr = findTail(*head);
        curr->next = temp;
        temp->prev = curr;
    }
}
void forwardTraversal(struct Node *head){
    struct Node *temp = head;
    printf("\nForward Traversal: ");
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
}
struct Node *findTail(struct Node *head){
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}
void backwardTraversal(struct Node *head){
    struct Node *temp = findTail(head);
    printf("\nBackward Traversal: ");
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->prev;
    }
}