/*
sort based on length and apply the conditions given in the question
*/

#include <bits/stdc++.h>

using namespace std;

// partially optimal, T.C = O(N^2*L), 
int longestStrChain(vector<string>& words) {
    int result = 1;
    int n = words.size();
    sort(words.begin(), words.end(), [](const string &a, const string &b){
        if(a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    });
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(words[i].length() - words[j].length() != 1)
                continue;
            else{
                int l = 0;
                for(int r = 0; r < words[i].length(); r++){
                    if(words[i][r] == words[j][l])
                        l++;
                }
                if(l == words[j].length())
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}
// making it O(N*L^2)
int longestStrChain(vector<string>& words) {
    int result = 1;
    int n = words.size();
    sort(words.begin(), words.end(), [](const string &a, const string &b){
        return a.length() < b.length();
    });
    unordered_map<string, int> dp;
    for(string w : words){
        for(int i = 0; i < w.length(); i++){
            string prev = w.substr(0, i) + w.substr(i + 1);// trying out all possible predecessors and chekcing if they exist in the dp table
            dp[w] = max(dp[w], dp.count(prev) ? dp[prev] + 1 : 1);
        }
        result = max(result, dp[w]);
    }
    return result;
}
int main(){
    return 0;
}