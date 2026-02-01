#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target)
            return letters[0];
        
        int l = 0, r = letters.size() - 1;

        while(l <= r){
            int m = (l + r)/2;

            if(letters[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }

        return letters[l];
    }
};