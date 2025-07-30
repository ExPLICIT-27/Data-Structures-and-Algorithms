/*
given a square matrix, find all square submatrices that add upto 
a given sum value
*/
#include <stdio.h>
#include <stdlib.h>
int SumCombos(int**, int, int);
int main(){
    int n;
    printf("\nEnter matrix size: ");
    scanf(" %d", &n);
    int **arr = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        arr[i] = (int*)malloc(n*sizeof(int));
        printf("\nEnter the row elements: ");
        for(int j = 0;j < n; j++){
            scanf(" %d", &arr[i][j]);
        }
    }
    int target;
    printf("\nEnter the target: ");
    scanf(" %d", &target);
    printf("combinations: %d", SumCombos(arr, n, target));
    return 0;
}
int SumCombos(int **arr, int n, int target){
    int count = 0;
    for(int subarrsize = n;subarrsize >= 0; subarrsize--){
        int offset = n-subarrsize+1;
        for(int ioff = 0; ioff < offset; ioff++){
            for(int joff = 0; joff < offset; joff++){
                int sum = 0;
                for(int i = 0; i < subarrsize; i++){
                    for(int j = 0; j < subarrsize; j++){
                        sum += arr[i+ioff][j+joff];
                    }
                }
                if(sum == target){
                    count++;
                }
            }
        }
    }
    return count;
}