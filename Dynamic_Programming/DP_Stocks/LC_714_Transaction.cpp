
#include <bits/stdc++.h>

using namespace std;

// only optimal, as this logic is the same as majority of the qns in this section

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    pair<int, int> prev = {0, 0}, curr;
    for(int i = n - 1; i >= 0; i--){
        curr.first = max(prev.first, prices[i] - fee + prev.second);
        curr.second = max(prev.second, -prices[i] + prev.first);
        prev = curr;
    }
    return prev.second;
}
int main(){
    return 0;
}