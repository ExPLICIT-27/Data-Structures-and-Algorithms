// time complexity - O(n^2), Space complexity - O(1)
#include <stdio.h>
void bubblesort(int*, int);
int main(){
    int array[] = {5, 4, 3, 2, 1};
    bubblesort(array, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
void bubblesort(int array[], int size){
    int temp;
    for(int i = 0; i < size; i++){              // i = size; i > 0; i-- along with
        for(int j = 0; j < (size-i-1); j++){    // j = 0; j < i-1; j++ would also work
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}