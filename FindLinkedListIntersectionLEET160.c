#include <stdio.h>
#include <stdlib.h>
// assuming input is two linked lists
// providing code just for the output, no input taking
struct Node{
    int val;
    struct Node *next;
};
struct Node *FindIntersection(struct Node *,struct Node *);
int main(){
    return 0;
}
struct Node *FindIntersection(struct Node *head1, struct Node *head2){
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    while(temp1 != temp2){
        if(temp1 != NULL){
            temp1 = temp1->next;
        }
        else{
            temp1 = head2;
        }
        if(temp2 != NULL){
            temp2 = temp2->next;
        }
        else{
            temp2 = head1;
        }
    }
    return temp1; // this would return null if there is no intersection
}