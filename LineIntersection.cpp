/*
Given the coordinates for two line segments, check whether they intersect or not
*/

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};
int onSegment(Point p, Point q, Point r);
int doIntersect(Point p1, Point q1, Point p2, Point q2, Point &intersection);
int orientation(Point p, Point q, Point r);
int main()
{
    Point p1 = {2, 3}, q1 = {5, 7};
    Point p2 = {3, 9}, q2 = {6, 2};
    Point res;

    if (doIntersect(p1, q1, p2, q2, res))
    {
        cout << "The lines intersect at point ("
             << res.x << ", " << res.y
             << ")." << endl;
    }
    else
    {
        cout << "The lines do not intersect within the "
                "segments."
             << endl;
    }
    return 0;
}
// check if point q lies in pr
int onSegment(Point p, Point q, Point r)
{
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y >= min(p.y, r.y) && q.y <= max(p.y, r.y));
}
// checking the orientation of line pq with pr
int orientation(Point p, Point q, Point r)
{
    int value = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (q.x - p.x);

    // collinear
    if (value == 0)
        return 0;

    return (value > 0) ? 1 : -1;
    // 1 -> clockwise, -1 anticlockwise
}
int doIntersect(Point p1, Point q1, Point p2, Point q2, Point &intersection)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // converting line into form ax + by = c
    // we know y = mx + c
    // mx - y = -c, let -c = C,
    // m = slope = (y2-y1)/(x2-x1)
    // ((y2-y1)/(x2-x1))*x - y = C
    // multiply by x2 - x1
    // (y2-y1)*x - (x2-x1)*y = C
    // (y2-y1)*x + (x1 - x2)*y = C
    // ax + by = C
    // after getting 2 equations from line 1 and 2,
    // we use cramer's rule to find the intersection by solving the
    // equations of line 1 and line 2
    if (o1 != o2 && o3 != o4)
    {
        double a1 = q1.y - p1.y;
        double b1 = p1.x - q1.x;

        double c1 = a1 * p1.x + b1 * p1.y;

        double a2 = q2.y - p2.y;
        double b2 = p2.x - q2.x;
        double c2 = a2 * p2.x + b2 * p2.y;

        double determinant = a1 * b2 - a2 * b1; // | a1 b1 |
                                                // | a2 b2 |
        if (determinant != 0)
        {
            intersection.x = (c1 * b2 - c2 * b1) / determinant;
            intersection.y = (a1 * c2 - a2 * c1) / determinant;
            return true;
        }
    }
    if (o1 == 0 && onSegment(p1, p2, q1))
    {
        intersection.x = p2.x, intersection.y = p2.y;
        return true;
    }
    if (o2 == 0 && onSegment(p1, q2, q1))
    {
        intersection.x = q2.x, intersection.y = q2.y;
        return true;
    }
    if (o3 == 0 && onSegment(p2, p1, q2))
    {
        intersection.x = p1.x, intersection.y = p1.y;
        return true;
    }
    if (o4 == 0 && onSegment(p2, q1, q2))
    {
        intersection.x = q1.x, intersection.y = q1.y;
        return true;
    }
    return false;
}