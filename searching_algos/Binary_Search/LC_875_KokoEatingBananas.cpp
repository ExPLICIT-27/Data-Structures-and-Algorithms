#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPossible(vector<int> &piles, int h, int k){
        int hours = 0;
        for(int i = 0; i < piles.size() && hours <= h; i++){
            int chours = (piles[i] + k - 1)/k;
            if(hours + chours <= h){
                hours += chours;
            }
            else
                return false;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        // range for koko
        int mid;
        while(left <= right){
            mid = (left + right)/2;
            if(isPossible(piles, h, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;

    }
};