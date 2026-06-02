#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long planet = mass;

        for(auto a : asteroids){
            if(a > planet)
                return false;
            planet += a;
        }

        return true;
    }
};