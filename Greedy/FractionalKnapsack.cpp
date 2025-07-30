/*
 Problem Description :
 Given n items where each item has some weight and profit associated with it and also given a bag with capacity W,
 [i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of
 profits associated with them is the maximum possible.
 Here you are allowed to take a fraction of the value depending on how much you can carry

 Greedy Logic : Sort on the basis of value per weight unit vi/wi and keep picking weights with highest value per
 weight unit till the knapsack is full
*/
#include <bits/stdc++.h>

using namespace std;

double maxProfit(vector<pair<int, int>> &items, double W)
{
    int n = items.size();
    sort(items.begin(), items.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return float(a.first) / a.second > float(b.first) / b.second; });
    double maxmoney = 0;
    for (int i = 0; i < n; i++)
    {
        if (!W)
            break;
        if (items[i].second <= W)
        {
            maxmoney += items[i].first, W -= items[i].second;
        }
        else
        {
            maxmoney += W * (float(items[i].first) / items[i].second);
            W = 0;
        }
    }
    return maxmoney;
}
int main()
{
    int n;
    cout << "\nEnter the number of items : ";
    cin >> n;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++)
    {
        int val, weight;
        cout << "\nEnter value and weight : ";
        cin >> val >> weight;
        items.push_back({val, weight});
    }
    double W;
    cout << "\nEnter knapsack Weight : ";
    cin >> W;
    cout << "\nMax profit : " << maxProfit(items, W);
    return 0;
}