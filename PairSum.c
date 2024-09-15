#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
};
void insert(struct Node **, struct Node **, int);
void printPairs(struct Node*, struct Node*, int);
void print(struct Node*);
int main(){
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int n, target, val;
    printf("\nEnter number of elements: ");
    scanf(" %d", &n);
    while(n--){
        printf("\nEnter the element: ");
        scanf(" %d", &val);
        insert(&head, &tail, val);
    }
    printf("\nEnter target: ");
    scanf(" %d", &target);
    printf("\nLinked List: ");
    print(head);
    printPairs(head, tail, target);
    return 0;
}
void print(struct Node *head){
    struct Node *temp = head;
    printf("\nNULL<->");
    while(temp != NULL){
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void printPairs(struct Node *head, struct Node *tail, int target){
    struct Node *t1 = head;
    struct Node *t2 = tail;
    while((t1 != NULL) && (t2 != NULL) && ((t1 != t2) && (t1->prev != t2) && (t2->next != t1))){
        if((t1->data + t2->data) == target){
            printf("\n(%d, %d)", t1->data, t2->data);
            t1 = t1->next;
            t2 = t2->prev;
        }
        else if((t1->data + t2->data) < target){
            t1 = t1->next;
        }
        else{
            t2 = t2->prev;
        }
    }
}
void insert(struct Node **head, struct Node **tail, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    if(*head == NULL){
        temp->next = NULL, temp->prev = NULL;
        *head = temp, *tail = temp;
    }
    else{
        temp->prev = *tail;
        temp->next = NULL;
        (*tail)->next = temp;
        *tail = temp;
    }
}