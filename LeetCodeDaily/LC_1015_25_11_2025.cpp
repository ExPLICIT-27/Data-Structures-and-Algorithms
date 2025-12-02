#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0)
            return -1;
        int cnt = 1;
        int num = 0;
        for(int i = 0; i < k; i++){
            num = (num*10 + 1)%k;
            if(!num)
                return cnt;
            cnt++;
        }
        return -1;
    }
};