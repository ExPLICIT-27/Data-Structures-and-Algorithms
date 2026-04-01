#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        //expected TC O(n^2)/O(n^log(N))

        /*
        from the lcp definition
        the matrix should be symmetric across the diagonal, i.e mat[i][j] = mat[j][i]
        for every i, j

        also another imp condition
        the diagonals must be prefix sums if set 

        missing one more case

        ok this is pre checks, just always build the lcp array from whatever ans you made and compare it with their lcp array
        */

        int n = lcp.size();

        vector<vector<int>> same(n);

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(lcp[i][j])
                    same[i].push_back(j);
            }
        }

        vector<char> V(n, '$');

        for(int j : same[0])
            V[j] = 'a';

        for(int i = 1; i < n; i++){

            char prev = V[i - 1];
            char curr = '$';
            for(char choice = 'a'; choice <= 'z'; choice++){
                // how do i validate a choice
                // i am about to put the character 'choice' in position i
                // will it satisfy lps array constraints
                bool ok = true;
                for(int j = 0; j < i; j++){
                    if((choice == V[j] && !lcp[i][j])){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    curr = choice;
                    break;
                }
            }
            if(curr == '$')
                return "";
            for(int j : same[i])
                V[j] = curr;
        }

        string ans = "";
        for(char c : V)
            ans += c;
    
        // build the lcp mat and check for final verification



        
        vector<vector<int>> chck(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ans[i] == ans[j])
                    chck[i][j] = 1;
            }
        }

        for(int j = n - 1; j >= 0; j--){
            for(int i = j; i >= 0; i--){
                if(chck[i][j] && (i + 1 < n && j + 1 < n))
                    chck[i][j] += chck[i + 1][j + 1];
                chck[j][i] = chck[i][j];
            }
        }
        if(chck == lcp)
            return ans;
        return "";
    }
};