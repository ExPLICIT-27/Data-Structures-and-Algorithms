#include <bits/stdc++.h>

using namespace std;

// SO DAMN COMPLICATED
struct Node{
    int mn, mx, sm;
    Node(){}
    Node(int a, int b){
        mn = a;
        mx = b;
    }
};
class SGT{
    public:
    
    vector<Node> S;
    vector<int> L;
    vector<int> A;

    SGT(vector<int> &a, int n){
        A = a;
        S.resize(4*n + 1, {INT_MAX, INT_MIN});
        L.resize(4*n + 1, 0);
    }

    void build(int i, int l, int r){
        if(l == r){
            S[i].mn = S[i].mx = A[l];
            return;
        }

        int m = (l + r)/2;
        build(2*i + 1, l, m);
        build(2*i + 2, m + 1, r);

        S[i].mn = min(S[2*i + 1].mn, S[2*i + 2].mn);
        S[i].mx = max(S[2*i + 1].mx, S[2*i + 2].mx);
    }

    int queryZero(int i, int l, int r){
        // cant find 0, like values between S[l] and S[r] must pass thru 0, [-x, +y]
        // for it to even have a chance of containing a 0
        if(L[i]){
            S[i].mn += L[i];
            S[i].mx += L[i];
            if(l != r){
                L[2*i + 1] += L[i];
                L[2*i + 2] += L[i];
            }
            L[i] = 0;
        }
        if(S[i].mn > 0 || S[i].mx < 0)
            return -1;

        
        if(l == r)
            return l;

        int m = (l + r)/2;
        int right = queryZero(2*i + 2, m + 1, r);

        // we need rightmost so if we found it in the right jsut stop then
        if(right != -1)
            return right;

        int left = queryZero(2*i + 1, l, m);

        return left;
    }
    void rangeUpdate(int i, int l, int r, int ql, int qr, int v){
        if(L[i]){
            S[i].mn += L[i];
            S[i].mx += L[i];
            if(l != r){
                L[2*i + 1] += L[i];
                L[2*i + 2] += L[i];
            }
            L[i] = 0;
        }
        if(l > r || l > qr || r < ql)
            return;

        
        if(l >= ql && r <= qr){
            S[i].mn += v;
            S[i].mx += v;
            if(l != r){
                L[2*i + 1] += v;
                L[2*i + 2] += v;
            }
            return;
        }

        int m = (l + r)/2;

        rangeUpdate(2*i + 1, l, m, ql, qr, v);
        rangeUpdate(2*i + 2, m + 1, r, ql, qr, v);


        S[i].mn = min(S[2*i + 1].mn, S[2*i + 2].mn);
        S[i].mx = max(S[2*i + 1].mx, S[2*i + 2].mx);
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int, vector<int>> occurence;
        int n = nums.size();
        vector<int> bal(n, 0);
        occurence[nums[0]].push_back(0);
        if(nums[0] & 1)
            bal[0] = 1;
        else
            bal[0] = -1;
        for(int i = 1; i < n; i++){
            if(occurence.count(nums[i]))
                bal[i] = bal[i - 1];
            else{
                if(nums[i] & 1)
                    bal[i] = bal[i - 1] + 1;
                else 
                    bal[i] = bal[i - 1] - 1;
            }
            occurence[nums[i]].push_back(i);
        }

        
        SGT S(bal, n);
        S.build(0, 0, n - 1);
        int ans = max(0, S.queryZero(0, 0, n - 1) + 1);

        for(int ql = 1; ql < n; ql++){
            auto it = upper_bound(occurence[nums[ql - 1]].begin(), occurence[nums[ql - 1]].end(), ql - 1);
            int qr = (it == occurence[nums[ql - 1]].end())? n - 1 : (*it) - 1;

            if(nums[ql - 1] & 1)
                S.rangeUpdate(0, 0, n - 1, ql, qr, -1);
            else
                S.rangeUpdate(0, 0, n - 1, ql, qr, 1);
            ans = max(ans, S.queryZero(0, 0, n - 1) - ql + 1);
        }

        return ans;

    }
};