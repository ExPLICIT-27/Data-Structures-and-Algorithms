#include <bits/stdc++.h>

using namespace std;
// explore all possible cases thru bfs
string findLexSmallestString(string s, int a, int b) {
    queue<string> q;
    unordered_set<string> vis;
    q.push(s);
    vis.insert(s);
    int n = s.length();
    string res = s;
    while(!q.empty()){
        string t = q.front();
        q.pop();
        res = min(res, t);
        for(int i = 1; i < n; i += 2){
            t[i] = ('0' + (t[i] - '0' + a)%10);
        }
        if(!vis.count(t)){
            vis.insert(t);
            q.push(t);
        }
        
        t = t.substr(n - b, b) + t.substr(0, n - b);
        if(!vis.count(t)){
            vis.insert(t);
            q.push(t);
        }
    }
    return res;
}
int main(){
    return 0;
}