#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<string> v1 = {s1};

        swap(s1[0], s1[2]);
        v1.push_back(s1);
        swap(s1[1], s1[3]);
        v1.push_back(s1);

        vector<string> v2 = {s2};
        swap(s2[0], s2[2]);
        v2.push_back(s2);
        swap(s2[1], s2[3]);
        v2.push_back(s2);
        
        for(auto &s : v1){
            for(auto &ss : v2)
                if(s == ss)
                    return true;
        }

        return false;
    }
};