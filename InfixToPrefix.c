#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int priority(char operator){
    if(operator == '^'){
        return 3;
    }
    else if(operator == '*' || operator == '/'){
        return 2;
    }
    else if(operator == '+' || operator == '-'){
        return 1;
    }
    return -1;
}
int main(){
    char infix[100];
    printf("\nEnter the infix expression: ");
    scanf(" %s", infix);
    int n = strlen(infix);
    // reversing to apply the same logic as postfix
    for(int i = 0; i < n/2; i++){
        char temp = infix[i];
        infix[i] = infix[n-i-1], infix[n-i-1] = temp;
    }
    char stack[n];
    char result[n+1];
    int top = -1, r = -1;
    for(int i = 0; i < n; i++){
        if(infix[i] >= '0' && infix[i] <= '9'){
            result[++r] = infix[i];
        }
        else{
            if(infix[i] == ')'){
                stack[++top] = ')';
            }
            else if(infix[i] == '('){
                while(top != -1 && stack[top] != ')'){
                    result[++r] = stack[top--];
                }
                top--;
            }
            else{
                if(infix[i] == '^'){
                    while(top != -1 && priority(infix[i]) <= priority(stack[top])){
                        result[++r] = stack[top--];
                    }
                }
                else{
                    while(top != -1 && priority(infix[i]) < priority(stack[top])){
                        result[++r] = stack[top--];
                    }
                }
                stack[++top] = infix[i];
            }
        }
    }
    while(top != -1){
        if(stack[top] != ')'){
            result[++r] = stack[top--];
        }
    }
    result[++r] = '\0';
    for(int i = 0; i < r/2; i++){
        char temp = result[i];
        result[i] = result[r-i-1], result[r-i-1] = temp;
    }
    printf("Prefix expression: %s", result);
    return 0;
}