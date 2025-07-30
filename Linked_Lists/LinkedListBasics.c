#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node *next;
};
void DeleteBefore(struct Node *);
void Delete(struct Node *, int);
void insertFront(struct Node**, int);
void printNodes(struct Node*);
struct Node *findNode(struct Node*, int);
void insertBefore(struct Node*, int);
int main(){
    struct Node *head = NULL;
    int n;
    printf("\nEnter number of nodes to be inserted : ");
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        printf("\nEnter the element : ");
        int val;
        scanf(" %d", &val);
        insertFront(&head, val);
        printNodes(head);
    }
    struct Node *found = findNode(head, 4);
    insertBefore(found, 5);
    printNodes(head);
    Delete(head, 3);
    printNodes(head);
    DeleteBefore(findNode(head, 2));
    printNodes(head);
    return 0;
}
void DeleteBefore(struct Node *before){
    struct Node *temp = before;
    temp = temp->next;
    before->next = temp->next;
}
void Delete(struct Node *head, int val){
    struct Node *temp = head;
    struct Node *prev = temp;
    temp = temp->next;
    while(temp != NULL){
        if(temp->val == val){
            prev->next = temp->next;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void insertBefore(struct Node *prev_node, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = prev_node->next;
    prev_node->next = temp;
}
struct Node *findNode(struct Node* head, int val){
    struct Node *temp = head;
    while(temp != NULL){
        if(temp->val == val){
            return temp;
        }
        temp = temp->next;
    }
}
void printNodes(struct Node *head){
    struct Node *temp = head;
    printf("\nList Node: ");
    while(temp != NULL){
        printf("%d-", temp->val);
        temp = temp->next;
    }
}
void insertFront(struct Node **head, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = *head;
    *head = temp;
}