// There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

// On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

// When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

// The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

// Return the maximum number of customers that can be satisfied throughout the day.

 

// Example 1:

// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
// Output: 16
// Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
// The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
// Example 2:

// Input: customers = [1], grumpy = [0], minutes = 1
// Output: 1
#include <iostream>
#include <vector>
using namespace std;
int sum(vector <int> &arr, int start, int stop){
    int output = 0;
    for(int i = start; i < stop; i++){
        output += arr[i];
    }
    return output;
}
int others(vector <int> &customers, vector <int> &grumpy, int start, int minutes){
    int remnants = 0;
    int i = 0;
    while(i < grumpy.size()){
        if(i == start){
            i += minutes;
        }
        else{
            if(!(grumpy[i])){
                remnants += customers[i];
            }
            i++;
        }
    }
    return remnants;
}
int maxSatisfied(vector <int> &customers, vector <int> &grumpy, int minutes){
    int result = 0;
    int start = 0;
    int max_cus = 0;
    if(minutes >= grumpy.size()){
        return sum(customers, 0, customers.size());
    }
    for(int i = 0; i < minutes; i++){
        max_cus += (grumpy[i]*customers[i]);
    }
    int t_cus = max_cus;
    for(int i = start; i < grumpy.size(); i++){
        t_cus += ((customers[i]*grumpy[i])-(customers[i-minutes]*grumpy[i-minutes]));
        if(t_cus > max_cus){
            start = i-minutes+1;
            max_cus = t_cus;
        }
    }
    max_cus = sum(customers, start, start+minutes);
    max_cus += others(customers, grumpy, start, minutes);
    return max_cus;
}
int main(){
    vector <int> c = {1, 0, 1, 2, 1, 1, 7, 5};
    vector <int> g = {0, 1, 0, 1, 0, 1, 0, 1};
    cout << maxSatisfied(c, g, 3);
    return 0;
}