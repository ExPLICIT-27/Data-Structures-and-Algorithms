#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        /*
        points to consider:
        the positions do not matter, just the counts do (clearly because you can flip any bits in any position (k times exactly))
        let the current number of zeros in the string be z, 
        then the number of ones = n - z
        our goal is to determine the smallest number of steps required to achieve z = 0 from 
        z = whatever number of zeros the input string has

        think about it differently
        we can solve it if we make the problem to be
        minimum number of steps required to make number of zeros equal to input string zeros starting from 0 zeros

        dp[i] = minimum number of steps required to make i zeros in string starting from 0 zeros

        O(n^2) logic to consider
        if we currently have z zeros
        we can define the next possible states to be the number of zeros we can achieve from this z
        we need to flip k bits
        if we choose to flip x zeros (hence k - x ones), the number of zeros
        z' becomes z' = z - x + (k - x) = z + k - 2*x

        max zeros i can flip = min(z, k)
        min zeros i can flip = max(0, k - (n - z)) // if there are less than k ones, remaining flips must be zeros

        so make transitions from curr z to all these states using bfs
        then finally return dp[number of zeroes initially in the string

        now iterating inside bfs from max(0, k - (n - z)) to min(z, k) will make the T.C O(n^2)

        can we avoid the loops
        we know the transition is like
        z' = z + k - 2*x
        only x changes, by a factor of 2
        i.e if z + k was 10, then possible z' values will depend
        only on min and max possible value of x
        i.e if min_x = 0, max_x = k
        then z' values will be 10, 8, 6, .. 10 - 2*k
        so instead of iterating over min_x to max_x every time, we only iterate over
        unvisited x values (total different x values are 0 to n, because x represents number of zeros in the string)
        so keep a set of univisited values
        different for even and different for odd, to avoid confusion when we fetch the unvisited values

        lowest unvisited z' will be lower_bound(x + k - 2*max_x)
        and highest unvisited z' will be prev(upper_bound(x + k - 2*min_x))
        so iterate from this lowest value to highest value and remove them from the set as well
        so that you dont visit them again
        */


        // O(n^2) code
        // int n = s.size();
        // vector<int> dp(n + 1, -1);
        // dp[0] = 0; // dp[i] = min moves to reach 0 zeros from i zeros

        // queue<int> Q;
        // Q.push(0);

        // while(!Q.empty()){
        //     int z = Q.front();
        //     Q.pop();
        //     int start = max(0, k - (n - z)), end = min(z, k);
        //     for(int x = start; x <= end; x++){
        //         int z_dash = z + k - 2*x;
        //         if(dp[z_dash] == -1){
        //             dp[z_dash] = dp[z] + 1;
        //             Q.push(z_dash);
        //         }
        //     }
        // }
        // int zcnt = count(s.begin(), s.end(), '0');
        // return dp[zcnt];

        int n = s.size();
        vector<int> dp(n + 1, -1);
        
        dp[0] = 0;

        set<int> evens, odds;
        //i have already visited 0, so start from 1
        for(int i = 1; i <= n; i++){
            if(i & 1)
                odds.insert(i);
            else
                evens.insert(i);
        }

        // same logic as before just lower bound, upper bound for limits
        queue<int> Q;
        Q.push(0);

        while(!Q.empty()){
            int z = Q.front();
            Q.pop();

            int start = z + k - 2*min(k, z), end = z + k - 2*max(0, k - (n - z));

            set<int>::iterator it1, it2;
            if(start & 1 ^ 1){
                // if even
                it1 = evens.lower_bound(start);
                it2 = evens.upper_bound(end);
            }
            else{
                it1 = odds.lower_bound(start);
                it2 = odds.upper_bound(end);
            }

            while(it1 != it2){// go till 1 element before it2
                int z_dash = *it1;

                dp[z_dash] = dp[z] + 1;
                Q.push(z_dash);
                if(start & 1)
                    odds.erase(it1++);
                else
                    evens.erase(it1++);
            }
        
        }
        
        int zcnt = count(s.begin(), s.end(), '0');

        return dp[zcnt];
    }
};
