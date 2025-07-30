#include <stdio.h>
void insertionsort(int*, int);
int main(){
    int array[] = {5, 4, 3, 2, 1};
    insertionsort(array, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
void insertionsort(int array[], int size){
    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i-1;
        while((j >= 0) && (array[j] > key)){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}