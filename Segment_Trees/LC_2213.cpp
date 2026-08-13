#include <bits/stdc++.h>

using namespace std;

class LazySGT{

    public:
    vector<pair<int, int>> S, Lazy;
    
    LazySGT(int n, vector<int> &left, vector<int> &right){
        S.assign(4*n + 1, make_pair(0, 0));
        Lazy.assign(4*n + 1, make_pair(0, 0));

        build(left, right, 0, 0, n - 1);
    }
    void update(pair<int, int> &tar, pair<int, int> &c1, pair<int, int> &c2){
        tar.first = max(c1.first, c2.first);
        tar.second = max(c1.second, c2.second);
    }

    void build(vector<int> &L, vector<int> &R, int i, int l, int r){
        if(l == r){
            S[i].first = L[l], S[i].second = R[l];
            return;
        }

        int m = l + (r - l)/2;

        build(L, R, 2*i + 1, l, m);
        build(L, R, 2*i + 2, m + 1, r);

        update(S[i], S[2*i + 1], S[2*i + 2]);
    }

    // push im making left, right agnostic, ill have to push both either way
    void push(int i, int l, int r){
        if(Lazy[i].first){
            S[i].first += Lazy[i].first;
            if(l < r){
                Lazy[2*i + 1].first += Lazy[i].first;
                Lazy[2*i + 2].first += Lazy[i].first;
            }

            Lazy[i].first = 0;
        }


        if(Lazy[i].second){
            S[i].second += Lazy[i].second;
            if(l < r){
                Lazy[2*i + 1].second += Lazy[i].second;
                Lazy[2*i + 2].second += Lazy[i].second;
            }

            Lazy[i].second = 0;
        }
    }
    void RU(int val, int i, int l, int r, int L, int R, bool isLeft){

        push(i, l, r);
        if(l > r || l > R || r < L)
            return;

        if(l >= L && r <= R){
            if(isLeft)
                Lazy[i].first += val;
            else
                Lazy[i].second += val;

            push(i, l, r);
            return;
        }

        int m = l + (r - l)/2;
        RU(val, 2*i + 1, l, m, L, R, isLeft);
        RU(val, 2*i + 2, m + 1, r, L, R, isLeft);

        update(S[i], S[2*i + 1], S[2*i + 2]);
    }

    // range query im designing only for left, itll be the same for right anyway
    int RQ(int i, int l, int r, int L, int R, bool isLeft){
        push(i, l, r);

        if(l > r || l > R || r < L)
            return 0;
        
        if(l >= L && r <= R)
            return isLeft? S[i].first : S[i].second;
        

        int m = l + (r - l)/2;
        int left = RQ(2*i + 1, l, m, L, R, isLeft);
        int right = RQ(2*i + 2, m + 1, r, L, R, isLeft);

        return max(left, right);
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryChars, vector<int>& queryInds) {
        /*
        how about DSU with respect to size on s
        unionize if adjacent characters are same
        then to obtain the global maximum, segment tree on
        the size array?

        implement to find any caveats
        after i finish fr bro
        cant undo unions :/

        if the update breaks a long chain, how do i even undo that

        remove DSU from the equation

        "bbbacc"
        3, 3, 3, 1, 2, 2

        how to undo with only seg trees
        if each index also had the information of how many equal characters extend to their left/right
        that would help
        
        [len, left, right] -> this is what my seg tree should contain

        [3, 0, 2], [3, 1, 1]

        when it gets disconnected, I have to range update the left and right values
        lazy SGT is what i need here

        the model of the seg tree should be maximum segment tree?
        but i need the left, right values as well
        the left, right values also need range updates

        [length, left, right]
        max sgt on the length parameter, 
        i dont care about the model for (left, right) but they are subject to range updates

        do i even need length?
        the answer will be the maximum value in the tree + 1 
        
        so structure as of now:
        - [left, right] values in the seg tree
        - they are subject to range updates and range queries
        - the update is decided by the neighbours of s when it is being updated in the query:
            - left & right neighbour not equal before update:
                - left = current after update
                    call range update on right values in the range [value[left], left] with +1
                    call point update on current with the value [value[left]] + 1
                - right = current : same algo but replace left with right
                - not equal after as well : no change
                - equal to both:
                    increment right of left values by 1 + value[right]
                    increment left of right values by 1 + value[left]
            - equals left neigh only before update
                - now equals right : same algo for current = right, also decrement the right values of left by 1
                - still equals left : no change
                - equals neither : decrement rigth values of left by 1
            - equals right only b4 update : same as upper, replace left with right
            - was equal to both before:
                still equal : no change
                not equal : decrement right of left by 1 + value[current]
                            decrement left of right by 1 + value[current]
        

        i can reduce the no of branches, lets play safe for now
        answer at any point of time is maximum value in the tree + 1

        brick by bloody brick
        */

        int N = s.size();

        vector<int> left(N, 0), right(N, 0);

        int L = 0;

        while(L < N){
            int R = L;

            while(R + 1 < N && s[R] == s[R + 1])
                R++;
            
            int consec = R - L + 1;

            for(int i = L; i <= R; i++){
                left[i] = i - L;
                right[i] = consec - (i - L + 1);
            }

            L = R + 1;
        }


        
        LazySGT seg(N, left, right);
       

        // cout << seg.RQ(0, 0, N - 1, 0, N - 1, true);
        // ok seg tree modelling and the left, right array builds seem correct
        // proceeding with the conditional handling of the queries

        auto prev = [&](int i) -> char {
            return i - 1 >= 0 ? s[i - 1] : '$';
        };

        auto next = [&](int i) -> char {

            return i + 1 < N ? s[i + 1] : '$';
        };
        
        int M = queryChars.size();

        vector<int> ans(M);

        for(int i = 0; i < M; i++){
            int idx = queryInds[i];
            char ch = queryChars[i];
            if(s[idx] != prev(idx) && s[idx] != next(idx)){
                if(ch != prev(idx) && ch != next(idx)){
                    ans[i] = (i - 1 < 0 ? seg.RQ(0, 0, N - 1, 0, N - 1, true) + 1 : ans[i - 1]);
                    s[idx] = ch;
                    continue;
                }
                else if(ch == prev(idx) && ch == next(idx)){
                    int ron = seg.RQ(0, 0, N - 1, idx + 1, idx + 1, false); // get the right of next idx
                    int lop = seg.RQ(0, 0, N - 1, idx - 1, idx - 1, true);
                    // get the left of prev idx


                    // left updates
                    seg.RU(ron + 2, 0, 0, N - 1, idx - lop - 1, idx - 1, false);
                    seg.RU(ron + 1, 0, 0, N - 1, idx, idx, false);
                    

                    // right updates
                    seg.RU(lop + 2, 0, 0, N - 1, idx + 1, idx + ron + 1, true);
                    seg.RU(lop + 1, 0, 0, N - 1, idx, idx, true);

                }
                else if(ch == prev(idx)){
                    int lop = seg.RQ(0, 0, N - 1, idx - 1, idx - 1, true);
                    // right
                    seg.RU(1, 0, 0, N - 1, idx - lop - 1, idx - 1, false);
                    // left
                    seg.RU(lop + 1, 0, 0, N - 1, idx, idx, true);
                }
                else{
                    int ron = seg.RQ(0, 0, N - 1, idx + 1, idx + 1, false);
                    // left
                    seg.RU(1, 0, 0, N - 1, idx + 1, idx + 1 + ron, true);
                    // right
                    seg.RU(ron + 1, 0, 0, N - 1, idx, idx, false);
                }

            }
            else if(s[idx] == prev(idx) && s[idx] == next(idx)){
                if(ch == s[idx]){
                    ans[i] = (i - 1 < 0 ? seg.RQ(0, 0, N - 1, 0, N - 1, true) + 1 : ans[i - 1]);
                    continue;
                }
                else{
                    int cl = seg.RQ(0, 0, N - 1, idx, idx, true);
                    int cr = seg.RQ(0, 0, N - 1, idx, idx, false);

                    seg.RU(-cr - 1, 0, 0, N - 1, idx - cl, idx - 1, false);
                    seg.RU(-cl - 1, 0, 0, N - 1, idx + 1, idx + cr, true);
                    seg.RU(-cl, 0, 0, N - 1, idx, idx, true);
                    seg.RU(-cr, 0, 0, N - 1, idx, idx, false);
                }
            }
            else if(s[idx] == prev(idx)){
                if(ch == s[idx]){
                    ans[i] = (i - 1 < 0 ? seg.RQ(0, 0, N - 1, 0, N - 1, true) + 1 : ans[i - 1]);
                    continue;
                }
                else{
                    int cl = seg.RQ(0, 0, N - 1, idx, idx, true);
                    seg.RU(-1, 0, 0, N - 1, idx - cl, idx - 1, false);
                    seg.RU(-cl, 0, 0, N - 1, idx, idx, true);

                    //it changes to something equal to whats there in the right
                    if(ch == next(idx)){
                        int ron = seg.RQ(0, 0, N - 1, idx + 1, idx + 1, false);
                        seg.RU(1, 0, 0, N - 1, idx + 1, idx + ron + 1, true);
                        seg.RU(ron + 1, 0, 0, N - 1, idx, idx, false);
                    }
                }
            }
            else{
               
                if(ch == s[idx]){
                    ans[i] = (i - 1 < 0 ? seg.RQ(0, 0, N - 1, 0, N - 1, true) + 1 : ans[i - 1]);
                    continue;
                }
                else{
                    int cr = seg.RQ(0, 0, N - 1, idx, idx, false);
                    seg.RU(-1, 0, 0, N - 1, idx + 1, idx + cr, true);
                    seg.RU(-cr, 0, 0, N - 1, idx, idx, false);

                    if(ch == prev(idx)){
                        int lop = seg.RQ(0, 0, N - 1, idx - 1, idx - 1, true);
                        seg.RU(1, 0, 0, N - 1, idx - lop - 1, idx - 1, false);
                        seg.RU(lop + 1, 0, 0, N - 1, idx, idx, true);
                    }
                }
            }

            s[idx] = ch;
            ans[i] = max(seg.RQ(0, 0, N - 1, 0, N - 1, false), seg.RQ(0, 0, N - 1, 0, N - 1, true)) + 1;
        }
        
        // for(int i = 0; i < N; i++)
        //    cout << seg.RQ(0, 0, N - 1, i, i, true) << " " <<  seg.RQ(0, 0, N - 1, i, i, false) << endl;
        return ans;
    }
};