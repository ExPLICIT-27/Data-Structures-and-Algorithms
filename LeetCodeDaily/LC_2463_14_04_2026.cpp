#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        /*
        for obvious reasons
        sort robots by their position
        sort factories by their position

        it doesnt make sense to go robot by robot
        A robot can move either left or right, but then cant change direction

        question boils down to efficiently allocating each robot to a factory

        at a given factory is it always optimal to put robots closest to it there?
        nope not at all
        so it hints dp

        what can be my states
        obviously at each point, id like to know what my current answer is
        
        each point of what? the factory? or the robot
        qns would be
        robot pov : where do i fix myself (i need to go to a factory that hasnt exceeded its limit)
        factory pov : which all robots do i fix?
        
        the robot pov might mess up all the calculations as i have to keep track of a modified factory array

        so factory pov?
        qn : would i ever benefit from not filling the factory to its full capacity? yes i might
        so instead of picking exactly L robots, i TRY to pick some from the left and some from the right if they are present even
        At a given factory with limit L
        for i in (0..L)
            left_robots = i, right_robots = L - i // in my current factory i decide to fix these many robots

            how does the recurrence build then? 
            since i am moving in ascending order there can only be 3 cases then
            i put left_robots, right_robots => indices obv
            if left end is l, right end is r
            current factory location is f
            
            case 1 : both l and r are to the left r <= f
            i choose robots in the left from (-inf, l) (r, f]
            i choose right robots from (f, inf)

            case 2 : l <= f <= r
            choose left robots in the range (-inf, l)
            right robots in the range (r, inf)

            case 3 : f <= l <= r
            choose left robots in range (-inf, f]
            right robots in range (f, l) and (r, inf)

            wow wtf - they prolly dont want to hire the guy

        so 3D dp then
        dp[i][L][R] => ith factory, with robots in indices L, R already fixed
        at i == n, L must be 0 and R must be n - 1

        negative fkin positions, i need to efficiently calculate the cost of robots moving to 
        a particular factory

        __ right logic starts here___
        well the range must be avoided then to make it choose left or choose right

        convert the factory array into position only array instead of position + limit
        i.e [pi, li] => pi*li factories with limit = 1
        now it becomes easier, no need of range sums
        for each factory at position pi
        if robots in range (0, r) have been fixed
        i can choose to fix or not fix the robot at r
        */


        sort(robot.begin(), robot.end());
        vector<int> F; // factory positions ONLY, limit = 1

        for(auto &f : factory){
            for(int i = 0; i < f[1]; i++)
                F.push_back(f[0]);
        }

        sort(F.begin(), F.end());

        // dp[i][R] => ith factory, robots till index R have been fixed
        // what is max possible cost that can occur?? 
        int n = F.size(), m = robot.size();

        auto calcCost = [&](int fidx, int ridx) -> ll {
           return (F[fidx] <= robot[ridx])? 1ll*robot[ridx] - F[fidx] : 1ll*F[fidx] - robot[ridx];
        };

        ll dp[n + 1][m + 1];

        // auto helper = [&](auto &&self, int i, int R) -> ll {
        //     // all robos fixed
        //     if(R == m)
        //         return 0;
            
        //     if(i == n)
        //         return 1e12; // 2*10^11 worst case cost
            
        //     if(dp[i][R] != -1)
        //         return dp[i][R];
        //     // chooose to repair or not repair robot R at this factory

        //     return dp[i][R] = min(calcCost(i, R) + self(self, i + 1, R + 1), self(self, i + 1, R));
        // };

        // return helper(helper, 0, 0);
        
        for(int i = 0; i <= n; i++)
            dp[i][m] = 0;
        for(int j = 0; j < m; j++)
            dp[n][j] = 1e12;

        ll ans = 1e12;
        for(int i = n - 1; i >= 0; i--){
            for(int R = m - 1; R >= 0; R--){
                dp[i][R] = min(calcCost(i, R) + dp[i + 1][R + 1], dp[i + 1][R]);
            }
            ans = min(ans, dp[i][0]);
        }
        
        return ans;
    }
};