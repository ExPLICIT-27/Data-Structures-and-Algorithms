#include <stdio.h>
void mergesort(int*, int);
void merge(int*, int*, int*, int);
int main(){
    int array[] = {5, 5, 4, 3, 2, 1};
    mergesort(array, 6);
    for(int i = 0; i < 6; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
void merge(int leftArray[], int rightArray[], int array[], int size){
    int leftSize = size/2;
    int rightSize = size-leftSize;
    int i = 0, l = 0, r = 0;
    while((l < leftSize) && (r < rightSize)){
        if((leftArray[l] < rightArray[r])){
            array[i] = leftArray[l];
            l++;
        }
        else{
            array[i] = rightArray[r];
            r++;
        }
        i++;
    }
    while(l < leftSize){
        array[i] = leftArray[l];
        i++, l++;
    }
    while(r < rightSize){
        array[i] = rightArray[r];
        i++, r++;
    }
}
void mergesort(int array[], int size){
    if(size <= 1){
        return;
    }
    int middle = size/2;
    int leftArray[middle];
    int rightArray[size-middle];
    int j = 0;
    for(int i = 0; i < size; i++){
        if(i < middle){
            leftArray[i] = array[i];
        }
        else{
            rightArray[j] = array[i];
            j++;
        }
    }
    mergesort(leftArray, middle);
    mergesort(rightArray, (size-middle));
    merge(leftArray, rightArray, array, size);
}