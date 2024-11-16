// O(N) searching for non sorted data
#include <stdio.h>
#include <stdlib.h>
int linearSearch(int *arr, int el, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == el){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    printf("\nEnter the number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    printf("\nEnter elements separated by space: ");
    for(int i = 0; i < n; i++){
        scanf(" %d", &arr[i]);
    }
    printf("\nEnter element to be searched: ");
    int key;
    scanf(" %d", &key);
    int idx = linearSearch(arr, key, n);
    if(idx != -1){
        printf("\nElement found at index %d", idx);
    }
    else{
        printf("\nElement not found.");
    }
    return 0;
}