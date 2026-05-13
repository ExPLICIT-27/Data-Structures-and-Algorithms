#include <bits/stdc++.h>

using namespace std;

// binary search soln
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        /*
        what is the optimal ordering to finish the tasks
        I know the optimal ans is the sum of all actuals
        
        what does the minimum do, it creates a bottleneck
        [10, 12], [10, 11], []


        what is the best sequence in which the tasks should be completed?
        well i guessed for the difference between min and actual, bang on
        */
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            int d1 = a[1] - a[0], d2 = b[1] - b[0];

            return d1 > d2;
        });

        auto canComplete = [&](int energy) -> bool {
            for(auto &v : tasks){
                if(energy < max(v[0], v[1]))
                    return false;
                energy -= v[0];
            }

            return energy >= 0;
        };

        int L = 0, R = 1e9;

        while(L <= R){
            int M = L + (R - L)/2;

            if(canComplete(M))
                R = M - 1;
            else
                L = M + 1;
        }

        return L;
    }
};

// greedy soln
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            return a[1] - a[0] < b[1] - b[0];
        });


        int res = 0;
        for(auto &v : tasks)
            res = max(res + v[0], v[1]);
        
        return res;
    }
};