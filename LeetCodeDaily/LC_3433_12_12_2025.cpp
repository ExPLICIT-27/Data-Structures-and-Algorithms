#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b){
            int x = stoi(a[1]), y = stoi(b[1]);

            if(x != y)
                return x < y;
            return a[0][0] > b[0][0];
        });
        vector<int> res(n, 0);
        unordered_map<int, int> availMap;
        for(int i = 0; i < n; i++)
            availMap[i] = 0;
        
        for(auto &vec : events){
            // cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
            int time = stoi(vec[1]);
            if(vec[0][0] == 'M'){
                if(vec[2][0] == 'A'){
                    for(int i = 0; i < n; i++)
                        res[i]++;
                }
                else if(vec[2][0] == 'H'){
                    for(auto &[x, y] : availMap){
                        if(y <= time)
                            res[x]++;
                    }
                }
                else{
                    istringstream iss(vec[2]);
                    string s;
                    while(iss >> s){
                        if(!s.empty()){
                            int id = stoi(s.substr(2));
                            res[id]++;
                        }
                    }
                }
            }
            else{
                availMap[stoi(vec[2])] = time + 60;
            }
        }
        return res;
    }
};