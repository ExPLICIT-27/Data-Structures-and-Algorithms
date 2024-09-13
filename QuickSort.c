#include <stdio.h>
int partition(int*, int, int);
void quicksort(int*, int, int);
int main(){
    int arr[] = {6, 7, 5, 3, 1, 2};
    quicksort(arr, 0, 5);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
void quicksort(int array[], int low, int high){
    if(low >= high){
        return;
    }
    int pivot = partition(array, low, high);
    quicksort(array, low, pivot-1);
    quicksort(array, pivot+1, high);
}
int partition(int array[], int low, int high){
    int pivot = array[low];
    int i = low;
    int j = high;
    int temp;
    while(i < j){
        while(array[i] <= pivot && i < high){
            i++;
        }
        while(array[j] > pivot && j > low){
            j--;
        }
        if(i < j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    array[low] = array[j];
    array[j] = pivot;
    return j;
}