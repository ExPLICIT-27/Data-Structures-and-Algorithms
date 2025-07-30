/*
Given a subset of numbers and an integer k, find a non empty subset that
gives the sum k
*/
#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<vector<int>> &ans, vector<int> &nums, int index, vector<int> &current, int target)
{
    if (target == 0)
    {
        ans.push_back(current);
        return;
    }
    if (index >= nums.size())
        return;
    for (int i = index; i < nums.size(); i++)
    {
        if (nums[i] > target)
            continue;
        current.push_back(nums[i]);
        subsetSum(ans, nums, i + 1, current, target - nums[i]);
        current.pop_back();
    }
}
int main()
{
    vector<int> numset{2, 2, 4, 3, 5, 7};
    int k = 7;
    vector<vector<int>> ans;
    vector<int> temp;
    subsetSum(ans, numset, 0, temp, k);
    for (auto arr : ans)
    {
        for (int i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}