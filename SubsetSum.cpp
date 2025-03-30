/*
Given a subset of numbers and an integer k, find a non empty subset that
gives the sum k
*/
#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &numset, int index, int k, vector<int> &subset)
{
    if (k == 0)
        return true;
    if (index >= numset.size())
        return false;
    for (int i = index; i < numset.size(); i++)
    {
        if (k - numset[i] >= 0)
        {
            subset.push_back(numset[i]);
            if (subsetSum(numset, i + 1, k - numset[i], subset))
                return true;
            subset.pop_back();
        }
    }
    return false;
}
int main()
{
    vector<int> numset{1, 2, 3};
    int k = 4;
    vector<int> subset;
    if (subsetSum(numset, 0, k, subset))
    {
        cout << "Subset : ";
        for (int num : subset)
            cout << num << " ";
    }
    else
    {
        cout << "Not possible";
    }
    return 0;
}