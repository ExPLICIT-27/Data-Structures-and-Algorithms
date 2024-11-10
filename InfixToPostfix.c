#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int priority(char operator){
    if(operator == '+' || operator == '-'){
        return 1;
    }
    if(operator == '*' || operator == '/'){
        return 2;
    }
    if(operator == '^'){
        return 3;
    }
    return -1;
}
int main(){
    char infix[100];
    printf("\nEnter infix expression: ");
    scanf(" %s", infix);
    int n = strlen(infix);
    char stack[n];
    int top = -1;
    printf("\nPostfix expression: ");
    for(int i = 0; i < n; i++){
        if(infix[i] >= '0' && infix[i] <= '9'){
            printf("%c", infix[i]);
        }
        else{
            if(infix[i] == '('){
                stack[++top] = '(';
            }
            else if(infix[i] == ')'){
                while(top != -1 && stack[top] != '('){
                    printf("%c", stack[top--]);
                }
                top--;
            }
            else{
                while((top != -1) && (priority(infix[i]) <= priority(stack[top]))){
                    printf("%c", stack[top--]);
                }
                stack[++top] = infix[i];
            }
        }
    }
    while(top != -1){
        if(stack[top] != '('){
            printf("%c", stack[top--]);
        }
    }
    return 0;
}