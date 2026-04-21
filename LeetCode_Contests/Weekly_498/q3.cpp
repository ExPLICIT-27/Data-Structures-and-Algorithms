#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x, y, c, t;

    Node(){}

    Node(int x, int y, int c, int t) : x(x), y(y), c(c), t(t) {}
};
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& src) {
        /*
        same time means overwrite is posssible
        */
        vector<vector<int>> time(n, vector<int>(m, -1));

        queue<Node> q;


        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(auto &s : src){
            ans[s[0]][s[1]] = s[2];
            q.push(Node(s[0], s[1], s[2], 0));
            time[s[0]][s[1]] = 0;
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};


        auto isValid = [&](int x, int y) -> bool {
            return (x >= 0 && x < n && y >= 0 && y < m);
        };
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = curr.x + dx[i], ny = curr.y + dy[i];

                if(!isValid(nx, ny))
                    continue;

                if(time[nx][ny] == -1){
                    time[nx][ny] = curr.t + 1;
                    ans[nx][ny] = curr.c;
                    q.push(Node(nx, ny, curr.c, curr.t + 1));
                }
                else{
                    if(time[nx][ny] >= curr.t + 1 && curr.c > ans[nx][ny]){
                        time[nx][ny] = curr.t + 1;
                        ans[nx][ny] = curr.c;
                        q.push(Node(nx, ny, curr.c, time[nx][ny]));
                    }
                }
            }
            
        }

        return ans;
        
    }
};