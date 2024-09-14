#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void insert(struct Node **, int);
void print(struct Node *);
void removeDupes(struct Node*);
int main(){
    struct Node *head = NULL;
    int n, val;
    printf("\nEnter the number of elements: ");
    scanf(" %d", &n);
    while(n--){
        printf("\nEnter the element: ");
        scanf(" %d", &val);
        insert(&head, val);
    }
    printf("\nBefore removing duplicates: ");
    print(head);
    removeDupes(head);
    printf("\nAfter removing duplicates: ");
    print(head);
    return 0;
}
void removeDupes(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL && temp->next != NULL){
        struct Node *prev = temp;
        struct Node *curr = temp->next;
        while(curr != NULL){
            if(curr->data == temp->data){
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
}
void print(struct Node *head){
    struct Node *temp = head;
    printf("\nLinked List: ");
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void insert(struct Node **head, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}