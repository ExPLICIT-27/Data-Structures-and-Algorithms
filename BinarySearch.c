// O(log(N)) searching algorithm to be applied on sorted elements

#include <stdio.h>
#include <stdlib.h>
int binarySearch(int *arr, int size, int el){
    int left = 0;
    int right = size-1;
    while(left <= right){
        int key = (left+right)/2;
        if(arr[key] == el){
            return key;
        }
        else if(arr[key] < el){
            left = key+1;
        }
        else{
            right = key-1;
        }
    }
    return -1;
}
int main(){
    int n;
    printf("\nEnter the number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    printf("\nEnter the elements separated by space: ");
    for(int i = 0; i < n; i++){
        scanf(" %d", &arr[i]);
    }
    printf("\nEnter element to be searched: ");
    int key;
    scanf(" %d", &key);
    int idx = binarySearch(arr, n, key);
    if(idx != -1){
        printf("\nElement found at index %d.", idx);
    }
    else{
        printf("\nElement not found.");
    }
    return 0;
}