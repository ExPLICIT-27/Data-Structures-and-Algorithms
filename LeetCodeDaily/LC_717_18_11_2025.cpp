#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        bool ans = true;
        while(i < n){
            if(bits[i]){
                i += 2;
                ans = false;
            }
            else{
                i++;
                ans = true;
            }
        }
        return ans;
    }
};