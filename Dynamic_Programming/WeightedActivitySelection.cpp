/*
instead of just maximising the count of the total number of non overlapping activities
we need to maximise the value associated with each activity
*/
#include <bits/stdc++.h>

using namespace std;

struct activity
{
    int start, finish, value;
    activity(int s, int f, int v) : start(s), finish(f), value(v) {};
};
int binarySearch(vector<activity> &arr, int index)
{
    int low = 0, high = index - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid].finish <= arr[index].start)
        {
            if (mid + 1 < index && arr[mid + 1].finish <= arr[index].start)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int maxActivityValue(vector<activity> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), [](const activity &a, const activity &b)
         { return a.finish < b.finish; });
    vector<int> dp(n, 0);
    dp[0] = arr[0].value;
    for (int i = 1; i < n; i++)
    {
        int includeVal = arr[i].value;
        int lastCompat = binarySearch(arr, i);
        if (lastCompat != -1)
        {
            includeVal += dp[lastCompat];
        }
        dp[i] = max(dp[i - 1], includeVal);
    }
    return dp[n - 1];
}
int main()
{
    vector<activity> activities = {
        {1, 4, 5}, {3, 5, 6}, {0, 6, 8}, {5, 7, 4}, {3, 9, 7}, {5, 9, 3}, {6, 10, 2}, {8, 11, 4}};

    cout << "Maximum Value Sum: " << maxActivityValue(activities) << endl;
    return 0;
}