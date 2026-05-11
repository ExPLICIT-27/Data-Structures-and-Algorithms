#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        /*
        if its a non prime number, the only choice is to 
        move to i + 1 or i - 1

        if its a prime, then move to any position which divides the prime

        can it be done by finding the min distance to reach
        the end of index from i, combined with min distance to reach i?

        */

        if(n == 1)
            return 0;

        auto isPrime = [&](int p) -> bool {
            if(p <= 1)
                return false;

            for(int i = 2; i*i <= p; i++){
                if(p%i == 0)
                    return false;
            }

            return true;
        };

        /*
        precompute distances from index i to the end (by only considering moves to the right)
        store the prime number moves to avoid recomputation

        now for every number nums[i]

        if nums[i] is not prime
        its only options are
        1 + min(dist[i - 1], dist[i + 1])
        if prime, then 
        min(dist[prime], 1 + min(dist[i - 1], dist[i + 1]))


        every prime number is connected to all its multiples and itself in
        the array by a distance of 1

        every non prime number is connected to the number b4 and after it
        is this a djikstras problem?????

        directed graph
        there is a directed edge from i to i + 1 and i to i - 1
        directed edge from every prime p to all its multiples
        with a weight of 1
        what if the entire array is just the same prime number?
        */

        vector<int> dist(n, n);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            int curr = nums[i];

            for(int j = 2; j*j <= curr; j++){
                if(curr%j == 0){
                    mp[j].push_back(i);
                    while(curr%j == 0)
                        curr /= j;
                }
            }

            if(curr > 1)
                mp[curr].push_back(i);
        }

        queue<int> q;
        dist[0] = 0;
        q.push(0); // index, weight

        int df[] = {-1, 1};
        unordered_set<int> s;
        while(!q.empty()){
            int u = q.front();

            q.pop();

            for(int inc : df){
                int v = u + inc;

                if(v >= 0 && v < n){
                    if(dist[v] > dist[u] + 1){
                        dist[v] = 1 + dist[u];
                        q.push(v);
                    }
                }
            }


            // this is a bottleneck, if i get a complete array of primes, this explodes

            if(isPrime(nums[u]) && !s.count(nums[u])){
                s.insert(nums[u]);// all hail the set :yay lmaooo
                for(int v : mp[nums[u]]){
                    if(dist[v] > dist[u] + 1){
                        dist[v] = 1 + dist[u];
                        q.push(v);
                    }
                }


            }
        }


    
        return dist[n - 1];
    }
};