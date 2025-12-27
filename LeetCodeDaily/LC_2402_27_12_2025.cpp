#include <bits/stdc++.h>

using namespace std;


#define ll long long

struct Comparator{
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        if(a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& M) {
        sort(M.begin(), M.end());

        priority_queue<ll, vector<ll>, greater<ll>> availRooms;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Comparator> meeting;

        for(int i = 0; i < n; i++)
            availRooms.push(i);

        vector<ll> ans(n, 0);
        for(auto &m : M){
            while(!meeting.empty() && meeting.top().first <= m[0]){
                availRooms.push(meeting.top().second);
                meeting.pop();
            }
            if(availRooms.empty()){
                auto T = meeting.top();
                meeting.pop();
                ll newT = m[1] - m[0] + max(1ll*m[0], T.first);
                ll ar = T.second;
                ans[ar]++;
                meeting.push({newT, ar});
            }
            else{
                ll avail = availRooms.top();
                availRooms.pop();
                ans[avail]++;
                meeting.push({m[1], avail});
            }
        }   
        int res = 0, min = ans[0];
        
        for(int i = 1; i < n; i++){
            if(ans[i] > min){
                min = ans[i];
                res = i;
            }
        }

        return res;
    }
};