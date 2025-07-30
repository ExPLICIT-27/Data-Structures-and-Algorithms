/*
Given a set of points in the plane. the convex hull of the set is
the smallest convex polygon that contains all the points of it.
Logic -> Find the point with the lowest y coordinate
then sort the other points wrt to the angle they make with the lowest point
add the lowest y to the resulting hull,
add another point, we need to start with at least two points,

*/
#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};
Point p0; // reference point
int orientation(Point p, Point q, Point r);
double distanceSqrd(Point p1, Point p2);
Point nextToTop(stack<Point> &S);
void GrahamScan(vector<Point> &points);
int main()
{
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    GrahamScan(points);
    return 0;
}
int orientation(Point p, Point q, Point r)
{
    int value = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    return (value == 0) ? 0 : (value > 0) ? 1
                                          : 2;
}
double distanceSqrd(Point p1, Point p2)
{
    return pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
}
Point nextToTop(stack<Point> &S)
{
    Point top = S.top();
    S.pop();
    Point next = S.top();
    S.push(top);
    return next;
}
void GrahamScan(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
        return;

    int minidx = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[minidx].y > points[i].y || points[minidx].y == points[i].y && points[minidx].x > points[i].x)
        {
            minidx = i;
        }
    }
    p0 = points[minidx];
    swap(points[0], points[minidx]);

    sort(points.begin() + 1, points.end(), [](const Point &a, const Point &b)
         {
        int o = orientation(p0, a, b);
        if(o == 0)
            return distanceSqrd(p0, a) < distanceSqrd(p0, b);
        return o == 2; });

    vector<Point> filteredPoints{points[0]};
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        filteredPoints.push_back(points[i]);
    }

    if (filteredPoints.size() < 3)
        return;
    stack<Point> S;
    S.push(filteredPoints[0]);
    S.push(filteredPoints[1]);
    S.push(filteredPoints[2]);
    for (int i = 3; i < filteredPoints.size(); i++)
    {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), filteredPoints[i]) != 2)
            S.pop();
        S.push(filteredPoints[i]);
    }

    cout << "Hull Points : \n";
    while (!S.empty())
    {
        cout << "(" + to_string(S.top().x) + ", " + to_string(S.top().y) + ")" << endl;
        S.pop();
    }
}