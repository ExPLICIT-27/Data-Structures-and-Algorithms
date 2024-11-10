
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char prefix[100];
    printf("\nEnter the prefix expression: ");
    scanf(" %s", prefix);
    printf("Expression : %s", prefix);
    // reversing to evaluate using the same logic as postfix
    int n = strlen(prefix);
    for(int i = 0; i < n/2; i++){
        char temp = prefix[i];
        prefix[i] = prefix[n-i-1], prefix[n-i-1] = temp;
    }
    int stack[n];
    int top = -1;
    for(int i = 0; i < n; i++){
        if(prefix[i] >= '0' && prefix[i] <= '9'){
            stack[++top] = prefix[i]-'0';
        }
        else{
            char operator = prefix[i];
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