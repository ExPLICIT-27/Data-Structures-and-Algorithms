#include <stdio.h>
#include <stdlib.h>
int* countingsort(int*, int);
int main(){
    int array[] = {5, 4, 5, 3, 2, 1};
    int *result = countingsort(array, 6);
    for(int i = 0; i < 6; i++){
        printf("%d ", result[i]);
    }
    return 0;
}
int* countingsort(int array[], int size){
    int max = array[0];
    for(int i = 1; i < size; i++){
        max = (array[i] > max)? array[i] : max;
    }
    int *counts = (int *)calloc((max+1), sizeof(int));
    for(int i = 0; i < size; i++){
        counts[array[i]]++;
    }
    int *result = (int *)malloc(size*sizeof(int));
    int i = 0;
    for(int j = 0; j <= max; j++){
        if(counts[j]){
            for(int k = 0; k < counts[j]; k++){
                result[i] = j;
                i++;
            }
        }
    }
    return result;
}