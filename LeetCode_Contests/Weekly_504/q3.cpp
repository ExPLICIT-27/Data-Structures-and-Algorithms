#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        /*
        now there must exist a greedy solution to this prob

        cannot have budget as a dp parameter

        cannot pre calculate the free factors in O(N^2)

        for each item
        if its factor is x
        then free[x] += mp[multiples of x]
        multiples can be found in O(nlogn)


        extra factor calculation is done


        is there any method which involves not spending 

        the weightage should be on
        the no of copies you can get with an amount x


        for each item
        if the cost is x,


        goal : just maximise the NUMBER of items bought

        so the free count only affects first buy

        initially (free[x] + 1)/cost[x] is the value of x

        theres a min threshold -> no of items i can get by buying the cheapest 
        item as many items as possible



        separate the items into class 1 and class 2
        class 1 -> i can get extras
        class 2 -> just simply 1 (will only buy based on lower cost)

        stupid shit, ONLY 1 item MAX
        */
        
        /*
        hence 2 or 1, thats all
        */

        int maxN = 0;
        unordered_map<int, int> mp;

        for(auto &it : items){
            maxN = max(maxN, it[0]);
            mp[it[0]]++;
        }

        vector<int> cnt(maxN + 1, -1);

        for(auto &it : items){
            int x = it[0];
            if(cnt[x] != -1)
                continue;
            
            cnt[x] = mp[x] - 1;

            for(int i = x + x; i <= maxN; i += x){
                if(mp.contains(i))
                    cnt[x] += mp[i];
            }
        }
        /*
        if there was no extra constraint as such
        then greedily picking the cheapest sack is optimal in knapsack
        so the same principle can be applied here

        store the cost of 2 items
        2,6
        2,8

        as long as i can buy two items
        */
        int n = items.size();
        vector<pair<int, int>> cheaper;

        for(auto &it : items){
            if(cnt[it[0]])
                cheaper.emplace_back(cnt[it[0]], it[1]);
        }

        int minP = INT_MAX;

        for(auto &it : items)
            minP = min(minP, it[1]);
        

        sort(cheaper.begin(), cheaper.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second;
        });


        // for(auto &p : cheaper){
        //     cout << p.first << " " << p.second << endl;
        // }
        int ans = 0;
        for(auto &[c, p] : cheaper){
            ll min2 = 2ll*minP;

            if(min2 < p){
                break;
            }
            else{
                if(1ll*p*c <= budget){
                    ans += 2*c;
                    budget -= p*c;
                }
                else{
                    int canBuy = budget/p;
                    budget -= p*canBuy;
                    ans += 2*canBuy;
                    break;
                }
            }
        }

        return ans + budget/minP;

    }
};
