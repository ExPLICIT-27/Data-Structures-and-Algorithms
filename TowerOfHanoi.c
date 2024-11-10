#include <stdio.h>
#include <stdlib.h>
#define max 100
// normal tower of hanoi, without using stack
void towerOfHanoi(int n, char from, char to, char aux){
    if(n == 1){
        printf("\nMove %d from %c to %c", n, from, to);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    printf("\nMove %d from %c to %c", n, from, to);
    towerOfHanoi(n-1, aux, to, from);
}
// tower of hanoi using stack
typedef struct Stack{
    int top;
    int stack[100];
}Stack;
int isEmpty(Stack *st){
    return st->top == -1;
}
void initializeStack(Stack *st){
    st->top = -1;
}
void push(Stack *st, char val){
    if(st->top < max - 1){
        st->stack[++st->top] = val;
    }
    else{
        printf("\nStack Overflow");
    }
}
char pop(Stack *st){
    if(!isEmpty(st)){
        return st->stack[st->top--];
    }
    else{
        printf("\nStack Underflow");
    }
}
void TowerOfHanoiUsingStack(int n, char from, char aux, char to){
    Stack stack;
    initializeStack(&stack);
    while(1){
        while(n > 0){
            push(&stack, to);
            push(&stack, aux);
            push(&stack, from);
            push(&stack, n);
            n--;
            char temp = to;
            to = aux, aux = temp;
        }
        if(isEmpty(&stack)){
            break;
        }
        n = pop(&stack);
        from = pop(&stack);
        aux = pop(&stack);
        to = pop(&stack);
        printf("\nMove disc %d from %c to %c", n, from, to);
        n--;
        char temp = from;
        from = aux, aux = from;
    }
}
int main(){
    towerOfHanoi(2, 'a', 'c', 'b');
    TowerOfHanoiUsingStack(2, 'a', 'b', 'c');
    return 0;
}