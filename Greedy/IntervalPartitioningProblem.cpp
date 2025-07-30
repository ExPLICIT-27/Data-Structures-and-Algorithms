/*
You have lectures/activities with their start and finish times, you cannot host a lecture that starts
before a certain one finishes in the same hall, determine the minimum number of
lecture halls required
*/
#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start, finish;
    Activity(int s = 0, int f = 0) : start(s), finish(f) {};
};
int MinHallsRequired(vector<Activity> &activities)
{
    int n = activities.size();
    sort(activities.begin(), activities.end(), [](const Activity &a, const Activity &b)
         { return a.start < b.start; });
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (const auto &activity : activities)
    {
        if (!minHeap.empty() && minHeap.top() <= activity.start)
        {
            minHeap.pop();
        }
        minHeap.push(activity.finish);
    }
    return minHeap.size();
}
int main()
{
    vector<Activity> activities = {
        {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}, {6, 9}};

    cout << "Minimum number of lecture halls required: " << MinHallsRequired(activities) << endl;
    return 0;
}
