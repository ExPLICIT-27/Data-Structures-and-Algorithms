/*
 Given coordinates for multiple line segments, find the lines which intersect.
 Brute Force = O(n^2) -> check each pair of lines
 Expected  O(n*log(n)) -> Sweeping line algorithm.
*/

#include <bits/stdc++.h>

using namespace std;

// event class for each line segment
class Event
{
public:
    int x, y;
    bool isLeft;
    int index;
    Event(int x, int y, int l, int i)
    {
        this->x = x;
        this->y = y;
        this->isLeft = l;
        this->index = i;
    }

    bool operator<(const Event &e) const
    {
        if (y == e.y)
        {
            return x < e.x;
        }
        return y < e.y;
    }
};
bool onSegment(vector<int> &p, vector<int> &q, vector<int> &r);
int orientation(vector<int> &p, vector<int> &q, vector<int> &r);
bool doIntersect(vector<vector<int>> &s1, vector<vector<int>> &s2);
void isIntersecting(vector<vector<vector<int>>> &lines);
set<Event>::iterator pred(set<Event> &s, set<Event>::iterator it)
{
    return (it == s.begin()) ? s.end() : --it;
}
set<Event>::iterator succ(set<Event> &s, set<Event>::iterator it)
{
    return ++it;
}
int main()
{
    vector<vector<vector<int>>> lines = {
        {{1, 5}, {4, 5}},  // Horizontal line (Line 1)
        {{2, 5}, {10, 1}}, // Diagonal line crossing Line 1 and Line 3 (Line 2)
        {{3, 2}, {10, 3}}, // Almost horizontal, crosses Line 2 (Line 3)
        {{6, 4}, {9, 4}},  // Horizontal line, intersects Line 2 (Line 4)
        {{7, 1}, {8, 1}},  // Horizontal line at bottom, does not intersect anything (Line 5)
        {{1, 1}, {1, 6}},  // Vertical line, intersects Line 1 (Line 6)
        {{5, 2}, {5, 6}},  // Vertical line, intersects Line 2, 3, and 4 (Line 7)
        {{0, 0}, {0, 1}}   // Far away vertical, no intersection (Line 8)
    };
    isIntersecting(lines);
    return 0;
}
bool onSegment(vector<int> &p, vector<int> &q, vector<int> &r)
{
    return (q[0] >= min(p[0], r[0]) && q[0] <= max(p[0], r[0]) && q[1] >= min(p[1], r[1]) && q[1] <= max(p[1], r[1]));
}
int orientation(vector<int> &p, vector<int> &q, vector<int> &r)
{
    int value = (q[1] - p[1]) * (r[0] - q[0]) - (r[1] - q[1]) * (q[0] - p[0]);
    if (!value)
        return value;
    return (value > 0) ? 1 : -1;
}
bool doIntersect(vector<vector<int>> &s1, vector<vector<int>> &s2)
{
    vector<int> p1 = s1[0], q1 = s1[1];
    vector<int> p2 = s2[0], q2 = s2[1];

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;
    return false;
}
// logic:
// sort based on x axis points, (line sweeps from left to right)
// while inserting a left point, check if the left point intersects with any of its neighbours
// while encountering a right point, check if the neighbours of the right point intersect with each other, then remove the line as it passes the right point
void isIntersecting(vector<vector<vector<int>>> &lines)
{
    unordered_map<string, int> mp;

    vector<Event> events;

    int n = lines.size();
    for (int i = 0; i < n; i++)
    {
        events.push_back(Event(lines[i][0][0], lines[i][0][1], true, i));
        events.push_back(Event(lines[i][1][0], lines[i][1][1], false, i));
    }

    sort(events.begin(), events.end(), [](const Event &e1, const Event &e2)
         { return e1.x < e2.x; });

    set<Event> active;
    int intersections = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        Event curr = events[i];
        int index = curr.index;

        if (curr.isLeft)
        {
            // find the neighbours
            auto next = active.lower_bound(curr); // lower bound returns the smallest value in set which is greater than curr
            auto prev = pred(active, next);

            // check for the current line's intersection with its exisiting neightbours
            if (next != active.end() && doIntersect(lines[next->index], lines[index]))
            {
                string key = to_string(next->index + 1) + " " + to_string(index + 1);
                if (mp.count(key) == 0)
                    mp[key]++, intersections++;
            }

            if (prev != active.end() && doIntersect(lines[prev->index], lines[index]))
            {
                string key = to_string(prev->index + 1) + " " + to_string(index + 1);
                if (mp.count(key) == 0)
                    mp[key]++, intersections++;
            }

            if (prev != active.end() && next != active.end() && prev->index == next->index)
                intersections--;
            active.insert(curr);
        }
        else
        {

            // find left endpoint of the line
            auto it = active.find(Event(lines[index][0][0], lines[index][0][1], true, index));
            auto prev = pred(active, it);
            auto next = succ(active, it);

            // if both neighbours exist, check if they intersect
            if (prev != active.end() && next != active.end())
            {
                string key1 = to_string(prev->index + 1) + " " + to_string(next->index + 1);
                string key2 = to_string(next->index + 1) + " " + to_string(prev->index + 1);

                if (mp.count(key1) == 0 && mp.count(key2) == 0 && doIntersect(lines[prev->index], lines[next->index]))
                    intersections++;
                mp[key1]++;
            }
            active.erase(it);
        }
    }
    cout << "Number of intersections: " << intersections << endl;
    for (auto pair : mp)
    {
        cout << "Line : " << pair.first << endl;
    }
}