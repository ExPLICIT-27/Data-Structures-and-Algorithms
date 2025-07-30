#include <iostream>
#include <vector>

using namespace std;
int countInversions(vector <int> &arr);
int merge(vector <int> &arr, vector <int> &left, vector <int> &right);
int main(){
    vector <int> arr{5, 4, 3, 2, 1};
    cout << countInversions(arr) << endl;
    return 0;
}
int countInversions(vector <int> &arr){
    if(arr.size() <= 1){
        return 0;
    }
    int total_inversions = 0;
    vector <int> left(arr.begin(), arr.begin() + arr.size()/2);
    vector <int> right(arr.begin() + arr.size()/2, arr.end());
    total_inversions += countInversions(left) + countInversions(right);
    total_inversions += merge(arr, left, right);
    return total_inversions;
}
int merge(vector <int> &arr, vector <int> &left, vector <int> &right){
    int i = 0, l = 0, r = 0;
    int inversions = 0;
    while(l < left.size() && r < right.size()){
        if(left[l] <= right[r]){
            arr[i++] = left[l++];
        }
        else{
            inversions += left.size() - l;
            arr[i++] = right[r++];
        }
    }
    while(l < left.size()){
        arr[i++] = left[l++];
    }
    while(r < right.size()){
        arr[i++] = right[r++];
    }
    return inversions;
}