#include <stdio.h>
void selectionsort(int*, int);
int main(){
    int array[] = {5, 4, 5, 3, 2, 1};
    selectionsort(array, 6);
    for(int i = 0; i < 6; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
void selectionsort(int array[], int size){
    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}