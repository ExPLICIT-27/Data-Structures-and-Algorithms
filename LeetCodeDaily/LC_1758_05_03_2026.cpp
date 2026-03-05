#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int zo = 0, oz = 0;

        int n = s.size();
        for(int i = 0; i < n; i++){
            if(i & 1){
                if(s[i] == '1')
                    oz++;
                else
                    zo++;
            }
            else{
                if(s[i] == '1')
                    zo++;
                else
                    oz++;
            }
        }

        return min(oz, zo);
    }
};