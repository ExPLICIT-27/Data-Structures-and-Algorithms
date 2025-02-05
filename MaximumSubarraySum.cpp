#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int Cross_Sum(vector <int> &arr, int low, int mid, int high, int &crossLow, int &crossHigh){
    int right_sum = INT_MIN, left_sum = INT_MIN, sum = 0;
    for(int i = mid; i >= low; i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum, crossLow = i;
        }
    }
    sum = 0;
    for(int i = mid + 1; i <= high; i++){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum, crossHigh = i;
        }
    }
    return left_sum + right_sum;
}
int Max_SubArray_Sum(vector <int> &arr, int low, int high, int &start, int &end){
    if(low == high){
        start = end = low;
        return arr[low];
    }
    int mid = (low + high)/2;
    int left_low, left_high, right_low, right_high, cross_low, cross_high;
    int left_sum = Max_SubArray_Sum(arr, low, mid, left_low, left_high);
    int right_sum = Max_SubArray_Sum(arr, mid + 1, high, right_low, right_high);
    int cross_sum = Cross_Sum(arr, low, mid, high, cross_low, cross_high);

    if(left_sum >= right_sum && left_sum >= cross_sum){
        start = left_low, end = left_high;
        return left_sum;
    }
    else if(right_sum >= left_sum && right_sum >= cross_sum){
        start = right_low, end = right_high;
        return right_sum;
    }
    else{
        start = cross_low, end = cross_high;
        return cross_sum;
    }
}
int main(){
    vector <int> arr{2, 3, -8, 7, -1, 2, 3};
    int start = 0, end = 0;

    cout << "Maximum Sum : " << Max_SubArray_Sum(arr, 0, arr.size()-1, start, end) << endl;
    for(int i = start ; i <= end; i++){
        cout << arr[i] << " ";
    }
    return 0;
}