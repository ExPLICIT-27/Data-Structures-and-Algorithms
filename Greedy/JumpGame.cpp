/*
Problem Description
Given an array arr[] of non-negative numbers. Each number tells you the maximum
number of steps you can jump forward from that position.
For example:

If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position
in the array to the last position.

Note: Print -1 if you can’t reach the end of the array.
*/
#include <bits/stdc++.h>
using namespace std;

int JumpGame(vector<int> &jumps)
{
    int n = jumps.size();
    int maxReach = 0, currReach = 0, jumpCount = 0;
    for (int i = 0; i < n; i++)
    {
        maxReach = max(maxReach, i + jumps[i]);
        if (maxReach >= n - 1)
            return jumpCount + 1;

        if (i == currReach)
        {
            if (i == maxReach)
            {
                return -1;
            }
            else
            {
                jumpCount++;
                currReach = maxReach;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> jumps{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << JumpGame(jumps) << endl;
    return 0;
}