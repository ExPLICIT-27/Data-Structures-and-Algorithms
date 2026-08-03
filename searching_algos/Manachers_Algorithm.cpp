#include <bits/stdc++.h>

using namespace std;


/*
Core:

- The goal is to reduce the worst case time complexity from O(N^2) to O(N)

- Let S be the string/array whose largest palindromic substring/subarray is to be found

- Let P[i] represent the value of the longest palindromic substring with center i.

- We generalize both odd and even case by inserting a '#' between every character and at the beginning and the end.

- Also to prevent out of bound errors, use sentinel values at the start and end [say '^' at front and '?' at end]

Intuition:
- suppose after doing the naive expansion for a particular center, we found some L, R of the palindrome
- If the index i is at some place < R, its mirror position is L + (R - i) [By reflection]
- Since we have already found L + R - i, [say P[L + R - i] is 3], we can copy the same value to i(by reflection) AS LONG AS it DOES NOT
exceed R [i.e i + P[L + R - i] should be <= R], if it does then just put P[i] = R - i since this we can safely guarantee
- Then for the uncertain part, do the manual expansion from center
- after the manual expansion is complete, set l to i - p[i] and r to i + p[i]


code referred from : CP Algorithms
*/

vector<int> manacher_odd(string S){
    int N = S.size();

    S = "$" + S + "^"; // add the sentinels

    vector<int> P(N + 2, 0); // P[i] -> largest palindrome centred at i

    int L = 0, R = 1;
    for(int i = 1; i <= N; i++){
        if(i <= R)
            P[i] = min(R - i, P[L + R - i]);
        
        // manual exp from centre
        while(S[i - P[i]] == S[i + P[i]])
            P[i]++;
        
        if(i + P[i] > R){
            L = i - P[i], R = i + P[i];
        }
    }

    return vector<int>(begin(P) + 1, end(P) - 1);

}

vector<int> preprocess(string S){
    string _S = "";

    for(char c : S)
        _S += string("#") + c;
    _S += "#";

    auto ans = manacher_odd(_S);

    return vector<int>(begin(ans) + 1, end(ans) - 1);
}

int main(){
    return 0;
}