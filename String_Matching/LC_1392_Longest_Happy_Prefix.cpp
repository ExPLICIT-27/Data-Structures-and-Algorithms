#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        /*
        KMP helps in identifying, for every index i in the string, what is the longest
        prefix which is also a suffix in it

        since this question requires us to find the exact same thing, except with the subtle change of the fact that the that index i must always equal the last index s, the problem can be solved by the value of the lps array at the last index
        */
        int n = s.size();
        vector<int> lps(n, 0);

        /*
        KMP is all about finding the prefix which is also a suffix in the range 0..i
        where i is the current index
        the lps array gives the position of where you should move to continue matching after a mismatch at any index i
        */

        /*
        j is at 0, i starts from one initially

        if s[i] == s[j]
            set lps[i] = j + 1
            inc both i and j
        else
            while j > 0 and s[i] != s[j]
                j = lps[j - 1]
            if s[i] == s[j]
                lps[i] = lps[j] + 1
                i++, j++
            else
                lps[i] = 0
                i++
        */
        int j = 0, i = 1;

        while(i < n){
            if(s[i] == s[j])
                lps[i++] = ++j;
            else{
                if(j == 0)
                    lps[i++] = 0;
                else
                    j = lps[j - 1];
            }
        }

        
        return s.substr(0, lps[n - 1]);
    }
};