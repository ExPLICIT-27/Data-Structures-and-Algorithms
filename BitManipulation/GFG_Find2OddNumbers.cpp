#include <bits/stdc++.h>

using namespace std;

/*
if the two odd occuring values are a and b, 
the effective xor of the array gives us a^b
find any set bit in this xor and then find two different xors of elements with this particular bit set and not set
these xors will be a and b
*/
class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int xr = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            xr ^= arr[i];
        }
        
        int stbit = 0;
        int tmp = xr;
        int i = 0;
        while(tmp){
            if(tmp & 1)    
                stbit = i;
            tmp >>= 1;
            i++;
        }
        int fi = 0, se = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] & (1 << stbit))
                fi ^= arr[i];
            else
                se ^= arr[i];
        }
        
        return {max(fi, se), min(se, fi)};
        
    }
};