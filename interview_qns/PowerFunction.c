#include <stdio.h>
#include <stdlib.h>

float myPow(int x, int n){
    if(n == 0){
        return 1.00;
    }
    else if(n < 0){
        return (float)1/myPow(x, -n);
    }
    else{
        float half = myPow(x, n/2);
        if(n%2 == 0){
            return half*half;
        }
        else{
            return x*half*half;
        }
    }
}
int main(){
    printf("%f", myPow(2, -2));
    return 0;
}