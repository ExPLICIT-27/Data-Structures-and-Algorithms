// stack approach + optimal approach
#include <bits/stdc++.h>

using namespace std;
/*
collision conditions
RL => 2 collisions changes to S
SL => 1 collision changes to S
RS => 1 collision changes to S
*/

// stack approach
class StackSol {
public:
    bool willCollide(char c, char t){
        return (c == 'L' && t == 'R') || (c == 'L' && t == 'S') || (c == 'S' && t== 'R');
    }
    int countCollisions(string directions) {
        string stk = "";
        int ans = 0;
        
        for(char c : directions){
            stk += c;
            while(stk.size() > 1 && willCollide(stk.back(), stk[stk.size() - 2])){
                if(stk.back() != 'S' && stk[stk.size() - 2] != 'S')
                    ans += 2;
                else
                    ans++;
                stk.pop_back();
                stk.pop_back();
                stk += 'S';
            }
        }
        return ans;
    }
};
// optimal
class Solution {
public:
    int countCollisions(string directions) {
        int l = 0;
        int n = directions.size();
        while(l < n && directions[l] == 'L')
            l++;
        
        int r = n - 1;
        while(r >= 0 && directions[r] == 'R')
            r--;
        int ans = 0;
        for(int i = l; i <= r; i++){
            if(directions[i] != 'S')
                ans++;
        }
        return ans;
    }   
};
