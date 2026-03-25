#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {

        /*
        the question boils down to finding the longest palindrome which starts from the first index
        
        string matching techniques like kmp helps me find the longest prefix which is also a suffix, but here the condition for a palindrome is longest prefix which is also a reversed suffix
        is there any advantage of reversing the string

        dcba
        0 0 0 0

        yep the advantage is that if you add the string with its reverse, youll be able to apply kmp and the length of the longest palindrome starting from the first
        index will be the last value of the lps array

        aaceaa#aaacecaa
        */

        string srev = s;
        reverse(srev.begin(), srev.end());

        string S = s + "#" + srev;

        int n = S.size();

        vector<int> lps(n, 0);

        int j = 0, i = 1;

        while(i < n){
            if(S[i] == S[j])
                lps[i++] = ++j;
            else{
                if(j == 0)
                    lps[i++] = 0;
                else
                    j = lps[j - 1];
            }
        }

        if(lps[n - 1] == n - 1)
            return s;

            
        return srev.substr(0, s.size() - lps[n - 1]) + s;
        
    }
};