/*
 Problem Description :
 Given a set of activities S, with their start and finish times, find the largest set S'
 such that it contains the maximum number of compatible activities (activites whose start and end times do not overlap)
*/

/*
Greedy Choice : Choosing the activity with the smallest finish time,
Once we sort the activities based on their finish times, it is guaranteed that the first activity(activity with
smallest finish time) will be part of some maximum subset, after selecting the first activity, repeat the
procedure till n
*/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> largestCompatibleSet(vector<pair<int, int>> &activities)
{
    int n = activities.size();
    sort(activities.begin(), activities.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
    vector<pair<int, int>> result;
    result.push_back(activities[0]);
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (activities[i].first >= activities[k].second)
        {
            result.push_back(activities[i]);
            k = i;
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "\nEnter the number of activites : ";
    cin >> n;
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter start and finish time of activity " << i << " : ";
        int st, end;
        cin >> st >> end;
        activities.push_back({st, end});
    }
    vector<pair<int, int>> result = largestCompatibleSet(activities);
    cout << "\nCompatible activity set :\n";
    for (auto pair : result)
    {
        cout << pair.first << "->" << pair.second << endl;
    }
    return 0;
}