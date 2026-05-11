#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int sc = 0, cnt = 0;

        for(string &s : events){
            if(s == "WD" || s == "NB")
                sc++;
            else if(s == "W")
                cnt++;
            else{
                sc += stoi(s);
            }

            if(cnt >= 10)
                break;
                
        }

        return {sc, cnt};
    }
};