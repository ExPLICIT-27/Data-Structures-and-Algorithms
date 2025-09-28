/*
buy if its smaller than the current, buy else see how much profit you get by selling
*/
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0];
    int result = 0;
    int n = prices.size();
    for(int i = 1; i < n; i++){
        if(prices[i] < buy)
            buy = prices[i];
        else
            result = max(result, prices[i] - buy);
    }
    return result;
}
int main(){
    return 0;
}