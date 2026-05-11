#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        int curr;
        bool ok = false;

        while(n){
            curr = n%10;
            if(curr == x)
                ok = true;
            n /= 10;
        }

        return curr != x && ok;
    }
};