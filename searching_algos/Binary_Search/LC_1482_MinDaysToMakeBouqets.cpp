#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMake(vector<int> &bloomDay, int m, int k, int day){
        int bouqets = 0;
        int t_k = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                t_k++;
                if(t_k == k){
                    bouqets++;
                    t_k = 0;
                }
            }
            else{
                t_k = 0;
            }
        }
        return bouqets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = bloomDay[0], right = bloomDay[0];
        for(int i = 0; i < bloomDay.size(); i++){
            left = min(left, bloomDay[i]);
            right = max(right, bloomDay[i]);
        }
        while(left <= right){
            int mid = (left + right)/2;
            if(canMake(bloomDay, m, k, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return (canMake(bloomDay, m, k, left))? left : -1;
    }
};