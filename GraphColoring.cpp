/*
Given the adjacency matrix representing connections in a graph, find the minimum number of
colors required to color the graph such that no adjacent vertices have the same color
*/
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<bool>> &graph, vector<int> &colors, int c, int vertex);
bool graphColorhelper(vector<vector<bool>> &graph, vector<int> &colors, int vertex, int m);
int minColors(vector<vector<bool>> &graph, int m);
int main()
{
    vector<vector<bool>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    int m = 3;
    cout << minColors(graph, m);
    return 0;
}
bool isSafe(vector<vector<bool>> &graph, vector<int> &colors, int c, int vertex)
{
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        if (graph[vertex][i] && colors[i] == c)
            return false;
    }
    return true;
}
bool graphColorhelper(vector<vector<bool>> &graph, vector<int> &colors, int vertex, int m)
{
    if (vertex == graph.size())
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(graph, colors, i, vertex))
        {
            colors[vertex] = i;
            if (graphColorhelper(graph, colors, vertex + 1, m))
                return true;
            colors[vertex] = 0;
        }
    }
    return false;
}
int minColors(vector<vector<bool>> &graph, int m)
{
    int V = graph.size();
    vector<int> colors(V, 0);
    if (graphColorhelper(graph, colors, 0, m))
    {
        return *max_element(colors.begin(), colors.end());
    }
    else
    {
        return -1;
    }
}