#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void insertbefore(struct Node *prev, int val){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = prev->next;
    prev->next = temp;
}
void delete(struct Node **head, struct Node **tail, int position){
    if(*head == NULL){
        return;
    }
    struct Node *temp = *head;
    if(position == 1){
        *head = temp->next;
        (*tail)->next = *head;
    }
    else{
        int i = 2;
        struct Node *prev = temp;
        temp = temp->next;
        while(i != position && temp != NULL){
            prev = temp;
            temp = temp->next;
            i++;
        }
        if(temp != NULL){
            prev->next = temp->next;
            free(temp);
        }
    }
}
struct Node *find(struct Node *head, int val){
    struct Node *temp = head;
    do{
        if(temp->data == val){
            return temp;
        }
        temp = temp->next;
    }while(temp != head);
    return NULL;
}
void insertion(struct Node **head, struct Node **tail, int val){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *head;
    if(*head == NULL){
        *head = temp;
        *tail = temp;
        (*tail)->next = *head;
    }
    else{
        (*tail)->next = temp;
        *tail = temp;
    }
}
void printList(struct Node *head){
    struct Node *temp = head;
    printf("\nCircular Linked List: ");
    do{
       printf("%d->", temp->data);
       temp = temp->next;
    }while(temp != head);
}
int main(){
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int n;
    printf("\nEnter number of elements: ");;
    scanf(" %d", &n);
    int val;
    while(n--){
        printf("\nEnter value to be inserted: ");
        scanf(" %d", &val);
        insertion(&head, &tail, val);
        printList(head);
    }
    insertbefore(find(head, 4), 5);
    printList(head);
    delete(&head, &tail, 1);
    printList(head);
    return 0;
}