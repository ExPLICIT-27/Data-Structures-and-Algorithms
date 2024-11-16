#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int validateVal(int*, int, int, int);
int binarySearch(int*, int, int);
int main(){
    int n;
    printf("\nEnter the number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    printf("\nEnter the elements separated by space: ");
    for(int i = 0; i < n; i++){
        scanf(" %d", &arr[i]);
    }
    int k;
    printf("\nEnter the number of hours: ");
    scanf(" %d", &k);
    printf("\nMinimum pastries: %d", binarySearch(arr, n, k));
    return 0;
}
int validateVal(int *arr, int n, int test, int k){
    int curr_count = 0;
    int i = 0;
    while(i < n && curr_count <= k){
        curr_count += (int)ceil((float)arr[i++]/test);
    }
    if(i == n && curr_count <= k){
        return 1;
    }
    return 0;
}
int binarySearch(int *arr, int n, int k){
    int left  = 0;
    int right = 0;
    for(int i = 0;i < n; i++){
        right += arr[i];
    }
    int mid = (left + right)/2;
    while(left <= right){
        mid = (left + right)/2;
        if(validateVal(arr, n, mid, k)){
             right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(validateVal(arr, n, mid, k)){
        return mid;
    }
    return mid+1;
    // return mid;
}