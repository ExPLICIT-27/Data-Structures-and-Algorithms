#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x, y, t;
    Node(int x, int y, int t){
        this->x = x;
        this->y = y;
        this->t = t;
    }
};
struct Comparator{
    bool operator()(const Node &a, const Node &b) const {
        if(a.t != b.t)
            return a.t < b.t;
        if(a.y != b.y)
            return a.y < b.y;
        return a.x < b.x;
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> A(n, false);
        A[0] = A[firstPerson] = true;

        vector<vector<pair<int, int>>> G(n);
        for(auto &v : meetings){
            G[v[0]].push_back({v[1], v[2]});
            G[v[1]].push_back({v[0], v[2]});
        }
        set<Node, Comparator> S;
        for(auto &v : G[0]){
            S.insert({0, v.first, v.second});
        }
        for(auto &v : G[firstPerson]){
            S.insert({firstPerson, v.first, v.second});
        }

        while(!S.empty()){
            auto T = *(S.begin());
            S.erase(S.begin());

            if(!A[T.y]){
                A[T.y] = true;
                for(auto &v : G[T.y]){
                    if(!A[v.first] && v.second >= T.t){
                        S.insert({T.y, v.first, v.second});
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(A[i])
                ans.push_back(i);
        }

        return ans;
    }
};