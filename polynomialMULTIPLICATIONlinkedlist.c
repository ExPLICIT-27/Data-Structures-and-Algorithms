#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coeff, power;
    struct Node *next;
};
struct Node *createnode(int, int);
void print(struct Node*);
void removeDupes(struct Node*);
void multiply(struct Node*, struct Node*, struct Node**, struct Node**);
void insert(struct Node**, struct Node**, int, int);
int main(){
    struct Node *heads[3] = {NULL, NULL, NULL};
    struct Node *tails[3] = {NULL, NULL, NULL};
    int n, m, coeff, power;
    printf("\nEnter number of elements in poly1: ");
    scanf(" %d", &n);
    while(n--){
        printf("\nEnter coeff and power: ");
        scanf(" %d %d", &coeff, &power);
        insert(&heads[0], &tails[0], coeff, power);
    }
    printf("\nEnter number of elements in poly2: ");
    scanf(" %d", &m);
    while(m--){
        printf("\nEnter coeff and power: ");
        scanf(" %d %d", &coeff, &power);
        insert(&heads[1], &tails[1], coeff, power);
    }
    print(heads[0]);
    print(heads[1]);
    multiply(heads[0], heads[1], &heads[2], &tails[2]);
    removeDupes(heads[2]);
    print(heads[2]);
    return 0;
}
void print(struct Node *head){
    struct Node *temp = head;
    int first = 1;
    printf("\nPolynomial: ");
    while(temp != NULL){
        if(temp->coeff != 0){
            if(!first){
                if(temp->coeff > 0){
                    printf(" + ");
                }
                else{
                    printf(" - ");
                }
            }
            if(temp->power > 1){
                printf("%dx^%d", abs(temp->coeff), temp->power);
            }
            else if(temp->power == 1){
                printf("%dx", abs(temp->coeff));
            }
            else{
                printf("%d", abs(temp->coeff));
            }
        }
        first = 0;
        temp = temp->next;
    }
}
void removeDupes(struct Node *head){
    struct Node *t1 = head;
    struct Node *t2, *dup;
    while(t1 != NULL && t1->next != NULL){
        t2 = t1;
        while(t2->next != NULL){
            if(t1->power == t2->next->power){
                t1->coeff += t2->next->coeff;
                dup = t2->next;
                t2->next = t2->next->next;
                free(dup);
            }
            else{
                t2 = t2->next;
            }
        }
        t1 = t1->next;
    }
}
void multiply(struct Node *poly1, struct Node *poly2, struct Node **rHead, struct Node **rTail){
    struct Node *t1 = poly1;
    struct Node *t2 = poly2;
    while(t1 != NULL){
        t2 = poly2;
        while(t2 != NULL){
            insert(rHead, rTail, t1->coeff*t2->coeff, t1->power+t2->power);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}
void insert(struct Node **head, struct Node **tail, int coeff, int power){
    struct Node *temp = createnode(coeff, power);
    if(*head == NULL){
        *head = *tail = temp;
    }
    else{
        (*tail)->next = temp;
        *tail = temp;
    }
}
struct Node *createnode(int coeff, int power){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    return newnode;
}