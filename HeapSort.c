#include <stdio.h>
void MaxHeapify(int *arr, int size){
    for(int i = 0; i <= size; i++){
        int key = i-1;
        while(key > 0 && arr[key] > arr[(key-1)/2]){
            int temp = arr[key];
            arr[key] = arr[(key-1)/2];
            arr[(key-1)/2] = temp;
            key = (key-1)/2;
        }
    }
}
void Heapify(int *arr, int size){
    int root = 0;
    while(2*root + 1 < size){
        int child = 2*root + 1;
        if(child + 1 < size && arr[child + 1] > arr[child]){
            child++;
        }
        if(arr[child] < arr[root]){
            return;
        }
        int temp = arr[child];
        arr[child] = arr[root];
        arr[root] = temp;
        root = child;
    }
}
void HeapSort(int *arr, int size){
    int curr_len = size;
    for(int i = 0; i < size; i++){
        int temp = arr[0];
        arr[0] = arr[--curr_len];
        arr[curr_len] = temp;
        Heapify(arr, curr_len);
    }
}
void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
int main(){
    int arr[] = {10, 20, 15, 30, 40};
    MaxHeapify(arr, 5);
    HeapSort(arr, 5);
    print(arr, 5);
    return 0;
}