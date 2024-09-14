#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
void insert(struct Node **, struct Node **, int);
void rotate(struct Node **, struct Node **, int, int);
void print(struct Node*);
int main(){
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int n, val, k;
    printf("\nEnter n: ");
    scanf(" %d", &n);
    int count = n;
    while(n--){
        printf("\nEnter element: ");
        scanf(" %d", &val);
        insert(&head, &tail, val);
    }
    printf("\nEnter rotation coefficient: ");
    scanf(" %d", &k);
    rotate(&head, &tail, k, count);
    print(head);
    return 0;
}
void print(struct Node *head){
    struct Node *temp = head;
    printf("\nLinked List: ");
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("NULL");
}
void rotate(struct Node **head, struct Node **tail, int k, int n){
    struct Node *curr = *head;
    int count = 1;
    while(count < (n-k) && curr != NULL){ // to make it rotate left instead of right use count < k instead of count < (n-k)
        curr = curr->next;
        count++;
    }
    if(curr == NULL){
        return;
    }
    struct Node *newHead = curr->next;
    (*tail)->next = *head; // forming circular nature
    (*head)->prev = *tail;
    if(newHead == NULL){
        return; // case where n=k
    }
    *tail = curr;
    *head = newHead;
}
void insert(struct Node **head, struct Node **tail, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->prev = *tail;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp, *tail = temp;
    }
    else{
        (*tail)->next = temp;
        *tail = temp;
    }
}