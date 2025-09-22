#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
                PROBLEM DESCRIPTION
    Let 1 represent ‘A’, 2 represent ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.  When decoding multiple interpretations can arise due to overlapping possibilities for how digits can be grouped into valid letter mappings. Each mapping corresponds to a letter based on its numeric value (e.g., “1” maps to ‘A’, “2” to ‘B’, …, “26” to ‘Z’).

    Consider the input string “123”. There are three valid ways to decode it:

    “ABC”: The grouping is (1, 2, 3) → ‘A’, ‘B’, ‘C’
    “AW”: The grouping is (1, 23) → ‘A’, ‘W’
    “LC”: The grouping is (12, 3) → ‘L’, ‘C’
*/
/*
    Naive Brute Force O(2^n)
    possible choices on encountering a digit:
    1. increment count and move on to the next digit
    2. include current digit as part of the sequence and dont increment the count
    Recurrence relation -> 
    decode(string, idx) = decode(string, idx + 1) + decode(string, idx + 2)
*/

int NaiveBruteForce(string &sequence, int idx){
    // base case, if you've reached the string end, a valid decoding has been performed
    int n = sequence.length();
    if(idx >= n){
        return 1;
    }

    int ways = 0;
    // single digit decoding
    if(sequence[idx] != '0'){
        ways = NaiveBruteForce(sequence, idx + 1); // it can either be 0 or 1(single digit encoding means there is only one possible output towards the end)
    }

    if((idx + 1 < n) && ((sequence[idx] == '1' && sequence[idx + 1] <= '9') || (sequence[idx] == '2' && sequence[idx + 1] <= '6'))){
        ways += NaiveBruteForce(sequence, idx + 2);
    }
    return ways;
}
/*

 Memoized Approach O(n) time and space
 keep a memo to keep track of the number of ways for a specific index

*/
int MemoizedApproach(string &sequence, int idx, vector<int> &memo){
    int n = sequence.length();
    if(idx >= n) return 1;
    if(memo[idx] != -1) return memo[idx];

    int ways = 0;
    if(sequence[idx] != '0'){
        ways = MemoizedApproach(sequence, idx + 1, memo);
    }
    if((idx + 1 < n) && ((sequence[idx] == '1' && sequence[idx] <= '9') || (sequence[idx] == '2' && sequence[idx] <= '6'))){
        ways += MemoizedApproach(sequence, idx + 2, memo);
    }
    memo[idx] = ways;
    return ways;
}
/*
 Tabulated DP approach
 Create a DP array of size n + 1 (n = length(sequence))
 initialize dp[n] = 1 (minimum 1, empty string has one decoding possible)
 Traverse from n to 0,
 if sequence[i] != '0', make dp[i] = dp[i + 1]
 if sequence[i]sequence[i + 1] is within 26, dp[i] += dp[i + 2]
 finally return dp[0]
*/
int TabulatedDP(string &sequence){
    int n = sequence.length();

    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        if(sequence[i] != '0'){
            dp[i] = dp[i + 1];
        }
        if((i < n - 1) && ((sequence[i] == '1' && sequence[i + 1] <= '9') || (sequence[i] == '2' && sequence[i] <= '6'))){
            dp[i] += dp[i + 2];
        }
    }
    return dp[0];
}
int main(){
    string s = "121";
    cout << NaiveBruteForce(s, 0) << endl;
    
    vector<int> memo(s.length(), -1);
    cout << MemoizedApproach(s, 0, memo) << endl;
    cout << TabulatedDP(s);
    return 0;
}