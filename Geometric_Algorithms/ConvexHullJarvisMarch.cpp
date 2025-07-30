/*
Given a set of points in the plane. the convex hull of the set is
the smallest convex polygon that contains all the points of it.
Jarvis March algorithm logic:
starting from the leftmost point (some algorithms start from the bottommost)
find the point with the largest amount of anticlockwise turn and add it to the set
of convex hull points.
TC -> O(m*n) (m -> hull points, n -> total points)
*/
#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};
int orientation(Point p, Point q, Point r);
vector<Point> JarvisMarch(vector<Point> &points);
int main()
{
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};

    vector<Point> convexHull = JarvisMarch(points);
    for (auto point : convexHull)
    {
        cout << "(" + to_string(point.x) + ", " + to_string(point.y) + ")" << endl;
    }
    return 0;
}
int orientation(Point p, Point q, Point r)
{
    int value = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (q.x - p.x);

    return (value == 0) ? 0 : (value > 0) ? 1
                                          : 2;
}
vector<Point> JarvisMarch(vector<Point> &points)
{
    int n = points.size();
    if (n <= 3)
        return points;
    int minPoint = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[minPoint].x)
            minPoint = i;
    }

    vector<Point> hull;

    int currPoint = minPoint, next_candidate;
    do
    {
        hull.push_back(points[currPoint]);

        next_candidate = (currPoint + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[currPoint], points[i], points[next_candidate]) == 2)
                next_candidate = i;
        }
        currPoint = next_candidate;
    } while (currPoint != minPoint);
    return hull;
}