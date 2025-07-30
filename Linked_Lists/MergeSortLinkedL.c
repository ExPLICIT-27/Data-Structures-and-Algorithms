#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void printList(struct Node*);
void insert(struct Node **, struct Node **, int);
struct Node *createnode(int);
void mergesort(struct Node *, struct Node *, struct Node **, struct Node **);
int main(){
    struct Node *heads[3] = {NULL, NULL, NULL};
    struct Node *tails[3] = {NULL, NULL, NULL};
    int n;
    printf("\nEnter number of elements in first list: ");
    scanf(" %d", &n);
    int val;
    while(n--){
        printf("\nEnter the elements: ");
        scanf(" %d", &val);
        insert(&heads[0], &tails[0], val);        ;
    }
    printf("\nEnter number of elements in second list: ");
    scanf(" %d", &n);
    while(n--){
        printf("\nEnter elements: ");
        scanf(" %d", &val);
        insert(&heads[1], &tails[1], val);
    }
    printList(heads[0]);
    printList(heads[1]);
    mergesort(heads[0], heads[1], &heads[2], &tails[2]);
    printList(heads[2]);
    return 0;
}
void printList(struct Node *head){
    struct Node *temp = head;
    printf("\nLinked List: ");
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void mergesort(struct Node *head1, struct Node *head2, struct Node **rHead, struct Node **rTail){
    struct Node *t1 = head1;
    struct Node *t2 = head2;
    while(t1  != NULL && t2 != NULL){
        if(t1->data < t2->data){
            insert(rHead, rTail, t1->data);
            t1 = t1->next;
        }
        else if(t1->data > t2->data){
            insert(rHead, rTail, t2->data);
            t2 = t2->next;
        }
        else{
            insert(rHead, rTail, t1->data);
            insert(rHead, rTail, t2->data);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while(t1 != NULL){
        insert(rHead, rTail, t1->data);
        t1 = t1->next;
    }
    while(t2 != NULL){
        insert(rHead, rTail, t2->data);
        t2 = t2->next;
    }
}
struct Node *createnode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void insert(struct Node **head, struct Node **tail, int val){
    struct Node *temp = createnode(val);
    if(*head == NULL){
        *head = temp, *tail = temp;
    }
    else{
        (*tail)->next = temp;
        *tail = temp;
    }
}