#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int flow, capacity;

    int u, v;
    Edge(int f, int c, int u, int v) : flow(f), capacity(c), u(u), v(v) {};
};
struct Vertex
{
    int h, e_flow;

    Vertex(int h, int e) : h(h), e_flow(e) {};
};

class Graph
{
    int V;
    vector<Vertex> ver;
    vector<Edge> edges;

    bool push(int u);
    void relabel(int u);
    void preflow(int s);
    void updateReverseEdge(int i, int flow);

public:
    Graph(int V);

    void addEdge(int u, int v, int capacity);

    int getMaxFlow(int s, int t);
};
Graph::Graph(int V)
{
    this->V = V;
    for (int i = 0; i < V; i++)
    {
        ver.push_back(Vertex(0, 0));
    }
}
void Graph::addEdge(int u, int v, int w)
{
    this->edges.push_back(Edge(0, w, u, v));
}
void Graph::preflow(int s)
{
    ver[s].h = this->V;

    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i].u == s)
        {
            edges[i].flow = edges[i].capacity;

            ver[edges[i].v].e_flow += edges[i].flow;

            edges.push_back(Edge(-edges[i].flow, 0, edges[i].v, s));
        }
    }
}
int overFlowVertex(vector<Vertex> &ver)
{
    for (int i = 1; i < ver.size() - 1; i++)
    {
        if (ver[i].e_flow > 0)
            return i;
    }
    return -1;
}
void Graph::updateReverseEdge(int i, int flow)
{
    int u = edges[i].v, v = edges[i].u;

    for (int j = 0; j < edges.size(); j++)
    {
        if (edges[j].v == v && edges[j].u == u)
        {
            edges[j].flow -= flow;
            return;
        }
    }
    // if not found, then create an edge
    Edge edge = Edge(0, flow, u, v);
    edges.push_back(edge);
}
bool Graph::push(int u)
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i].u == u)
        {
            // flow = capacity, no push
            if (edges[i].flow == edges[i].capacity)
                continue;
            if (ver[u].h > ver[edges[i].v].h)
            {
                int flow = min(edges[i].capacity - edges[i].flow, ver[u].e_flow);
                edges[i].flow += flow;
                ver[u].e_flow -= flow;
                ver[edges[i].v].e_flow += flow;
                updateReverseEdge(i, flow);
                return true;
            }
        }
    }
    return false;
}
void Graph::relabel(int u)
{
    int min_height = INT_MAX;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i].u == u)
        {
            if (edges[i].capacity == edges[i].flow)
                continue;
            if (ver[edges[i].v].h < min_height)
            {
                min_height = ver[edges[i].v].h;
                ver[u].h = min_height + 1;
            }
        }
    }
}
int Graph::getMaxFlow(int s, int t)
{
    preflow(s);

    while (overFlowVertex(ver) != -1)
    {
        int u = overFlowVertex(ver);
        if (!push(u))
            relabel(u);
    }
    return ver.back().e_flow;
}
int main()
{
    int V = 6;
    Graph g(V);

    // Creating above shown flow network
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(2, 1, 4);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);

    // Initialize source and sink
    int s = 0, t = 5;

    cout << "Maximum flow is " << g.getMaxFlow(s, t);
    return 0;
}