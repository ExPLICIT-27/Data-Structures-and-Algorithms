#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int findCrossOver(int *, int, int, int);
void printKClosest(int *, int, int, int);
int main(){
    int n;
    printf("\nEnter the number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    printf("\nEnter the elements separated by space: ");
    for(int i = 0; i < n; i++){
        scanf(" %d", &arr[i]);
    }
    int x, k;
    printf("\nEnter the target and number of closest elements required: ");
    scanf(" %d %d", &x, &k);
    printKClosest(arr, n, x, k);
    return 0;
}
int findCrossOver(int *arr, int low, int high, int x){
    if(arr[high] <= x){
        return high;
    }
    if(arr[low] > x){
        return low;
    }
    int mid = (low + high)/2;
    if(arr[mid] <= x && arr[mid+1] > x){
        return mid;
    }
    if(arr[mid] < x){
        return findCrossOver(arr, mid+1, high, x);
    }
    return findCrossOver(arr, low, mid-1, x);
}
void printKClosest(int *arr, int n, int x, int k){
    int left = findCrossOver(arr, 0, n-1, x);
    int right = left + 1;
    if(arr[left] == x){
        left--;
    }
    int count = 0;
    while(left >= 0 && right < n && count < k){
        if(x - arr[left] < arr[right] - x){
            printf("%d ", arr[left--]);
        }
        else{
            printf("%d ", arr[right++]);
        }
        count++;
    }
    while(count < k && left >= 0){
        printf("%d ", arr[left--]);
        count++;
    }
    while(count < k && right < n){
        printf("%d ", arr[right++]);
        count++;
    }
}