#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int n = s.size();

        int i = 0;

        while(i < n && s[i] == '1')
            i++;
        while(i < n && s[i] == '0')
            i++;
        
        return i == n;
    }
};