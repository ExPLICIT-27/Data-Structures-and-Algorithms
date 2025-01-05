#include <iostream>
#include <vector>
#include <algorithm>
// difference array helps process each query in O(1) time
// that is if a 2d array of queries is given where each query is of
// length 3, 
// -> first and second index represent the ranges
// -> third index element represent the value to be added to the
// elements in the range
// naive solution, -> for every element in range(start, stop
// add the third element
//optimised one:
// create an array and fill it with zeroes
// for each query, update array[start] += third
// array[stop + 1] -= third
// then find prefix sum
// modify original array as, og_arr[i] += array[i]
using namespace std;
void processQueries(vector<int> &og, vector<vector<int>> &queries){
    vector<int> diff_arr(og.size(), 0);
    for(auto & i : queries){
        diff_arr[i[0]] += i[2];
        if(i[1] + 1 < og.size()){
            diff_arr[i[1] + 1] -= i[2];
        }
    }
    for(int i = 1; i < diff_arr.size(); i++){
        diff_arr[i] += diff_arr[i-1];
    }
    for(int i = 0; i < og.size(); i++){
        og[i] += diff_arr[i];
    }
}
int main(){
    vector<int> og = {4, 7, 1, 3, 9};  // Original array
    vector<vector<int>> queries = {
        {0, 2, 2},  // Add 2 to indices 0 through 2
        {1, 4, -3}, // Subtract 3 from indices 1 through 4
        {3, 4, 4}   // Add 4 to indices 3 through 4
    };

    processQueries(og, queries);

    // Output the modified array
    for (int i : og) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}