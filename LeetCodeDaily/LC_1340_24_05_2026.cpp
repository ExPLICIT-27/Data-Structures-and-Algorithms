#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        /*
        O(n^2)/O(n*d) is possible
        can start at any index
        - can move to any index within distance d such that
            - if im moving from i to j then
            - arr[i] > (arr[i...j]) // can move to any element before its next greater element

            - and abs(j - i) <= d

        is it always optimal to move to the largest element which is within the movable range?
        seems like it

        dp doesnt seem suitable(at least for the entirety, maybe partially), its a no of visit checks qn

        a graph like approach seems better

        - preprocessings
        - PSE, NSE, (SEG trees?)
        - i can use intermediate results for the newer start points so, its kinda like dp 
        */

        int n = arr.size();

        vector<int> dp(n, 1);

        vector<int> pge(n), nge(n);

        vector<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.back()] <= arr[i])
                st.pop_back();
            
            pge[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.back()] <= arr[i])
                st.pop_back();
            
            nge[i] = st.empty() ? n : st.back();

            st.push_back(i);
        }

       
        /*
        can i avoid seg trees?
        sorting and building it in the opposite dirn?
        */

        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);

        sort(ind.begin(), ind.end(), [&](int a, int b){
            return arr[a] < arr[b];
        });

        // LIS only it seems like
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(abs(ind[i] - ind[j]) > d || arr[ind[i]] == arr[ind[j]])
                    continue;
                if((ind[i] > ind[j]) && (pge[ind[i]] > ind[j] || nge[ind[j]] < ind[i]))
                    continue;
                
                if((ind[i] < ind[j]) && (pge[ind[j]] > ind[i] || nge[ind[i]] < ind[j]))
                    continue;
                dp[ind[i]] = max(dp[ind[i]], 1 + dp[ind[j]]);
            }
        }
        
        
        return *max_element(dp.begin(), dp.end());
    }
};