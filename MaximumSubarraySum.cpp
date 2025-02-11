#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>


using namespace std;

typedef struct Result{
    int leftidx, rightidx, maxsum;
}Result;
Result MaxCrossSum(vector <int> &, int, int, int);
Result MaxSubarraySum(vector<int> &, int, int);
int main(){
    vector <int> arr{1, 2, 3, -10, 3, 3};
    Result result = MaxSubarraySum(arr, 0, arr.size()-1);
    cout << "Max sum: " << result.maxsum << endl;
    cout << "Max subarray: ";
    for(int i = result.leftidx; i <= result.rightidx; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
Result MaxCrossSum(vector <int> &arr, int low, int mid, int high){
    int leftsum = INT_MIN, rightsum = INT_MIN;
    int leftidx = mid, rightidx = mid+1;
    int sum = 0;
    for(int i = mid; i >= 0; i--){
        sum += arr[i];
        if(sum > leftsum){
            leftsum = sum, leftidx = i;
        }
    }
    sum = 0;
    for(int i = mid+1; i <= high; i++){
        sum += arr[i];
        if(sum > rightsum){
            rightsum = sum, rightidx = i;
        }
    }
    return {leftidx, rightidx, leftsum + rightsum};
}
Result MaxSubarraySum(vector<int> &arr, int low, int high){
    if(low == high){
        return {low, low, arr[low]};
    }
    int mid = (low + high)/2;
    Result leftmax = MaxSubarraySum(arr, low, mid);
    Result rightmax = MaxSubarraySum(arr, mid + 1, high);
    Result crossmax = MaxCrossSum(arr, low, mid, high);

    int maxsum = max({leftmax.maxsum, rightmax.maxsum, crossmax.maxsum});
    vector<Result> candidates;
    if(leftmax.maxsum == maxsum){
        candidates.push_back(leftmax);
    }
    if(rightmax.maxsum == maxsum){
        candidates.push_back(rightmax);
    }
    if(crossmax.maxsum == maxsum){
        candidates.push_back(crossmax);
    }
    Result returnVal;
    int minlength = INT_MAX;
    for(int i = 0; i < candidates.size(); i++){
        if(candidates[i].rightidx - candidates[i].leftidx < minlength){
            minlength = candidates[i].rightidx - candidates[i].leftidx;
            returnVal = candidates[i];
        }
    }
    return returnVal;
}