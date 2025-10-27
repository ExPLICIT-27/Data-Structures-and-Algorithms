/*
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n/7;
        int weekMoney = weeks*28 + weeks*((weeks - 1)*7)/2;
        int nth = (n + 6)/7, left = n%7;
        int finalWeekMoney = left*(left + 1)/2 + (nth - 1)*left;
        return weekMoney + finalWeekMoney;
    }
};