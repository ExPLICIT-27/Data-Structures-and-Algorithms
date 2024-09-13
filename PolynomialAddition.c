#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coeff, power;
    struct Node *next;
};
void insert(struct Node **head, int c, int p){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coeff = c, temp->power = p;
    temp->next = *head;
    *head = temp;
}
void print(struct Node *head){
    struct Node *temp = head;
    printf("\nADDED POLYNOMIAL: ");
    while(temp != NULL){
        if(temp->next != NULL){
            printf("%dx^%d + ", temp->coeff, temp->power);
        }
        else{
            printf("%dx^%d", temp->coeff, temp->power);
        }
        temp = temp->next;
    }
}
void addAndinsert(struct Node *head1, struct Node *head2, struct Node **mainhead){
    struct Node *t1 = head1;
    struct Node *t2 = head2;
    while(t1 != NULL && t2 != NULL){
        if(t1->power == t2->power){
            int coeff = t1->coeff + t2->coeff;
            insert(mainhead, coeff, t1->power);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->power < t2->power){
            insert(mainhead, t1->coeff, t1->power);
            t1 = t1->next;
        }
        else{
            insert(mainhead, t2->coeff, t2->power);
            t2 = t2->next;
        }
    }
    while(t1 != NULL){
            insert(mainhead, t1->coeff, t1->power);
            t1 = t1->next;
    }
    while(t2 != NULL){
            insert(mainhead, t2->coeff, t2->power);
            t2 = t2->next;
    }
}
int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *result = NULL;
    int n, m;
    int coeff, power;
    printf("\nNo. of terms in poly 1: ");
    scanf(" %d", &n);
    while(n--){
        printf("\nEnter coeff and power: ");
        scanf(" %d %d", &coeff, &power);
        insert(&head1, coeff, power);
    }
    print(head1);
    printf("\nEnter no. of terms in poly 2: ");
    scanf(" %d", &m);
    while(m--){
        printf("\nEnter coeff and power: ");
        scanf(" %d %d", &coeff, &power);
        insert(&head2, coeff, power);
    }
    print(head2);
    addAndinsert(head1, head2, &result);
    print(result);
    return 0;
}