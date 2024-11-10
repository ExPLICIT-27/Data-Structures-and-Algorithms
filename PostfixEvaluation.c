#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    char postfix[100];
    printf("\nEnter the postfix expression: ");
    scanf(" %s", postfix);
    printf("Expression : %s", postfix);
    int n = strlen(postfix);
    int stack[n];
    int top = -1;
    for(int i = 0; i < n; i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            stack[++top] = postfix[i]-'0';
        }
        else{
            char operator = postfix[i];
            int op1 = stack[top--];
            int op2 = stack[top--];
            if(operator == '+'){
                stack[++top] = op1 + op2;
            }
            else if(operator == '-'){
                stack[++top] = op2 - op1;
            }
            else if(operator == '/'){
                stack[++top] = op2/op1;
            }
            else if(operator == '*'){
                stack[++top] = op2*op1;
            }
            else{
                stack[++top] = (int)pow(op2, op1);
            }
        }
    }
    printf("\nEvaluated value: %d", stack[top]);
    return 0;
}