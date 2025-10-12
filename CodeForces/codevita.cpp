#include <bits/stdc++.h>
using namespace std;

// ---------- Typedefs ----------
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define uset unordered_set
#define umap unordered_map

// ---------- Macros ----------
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define vmax(a) (*max_element(all(a)))
#define vmin(a) (*min_element(all(a)))
#define vsum(a) (accumulate(all(a), 0LL))
#define vsumd(a) (accumulate(all(a), 0.0))

// ---------- Fast IO ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

struct Node {
    int x, y;
    string el;
    ll dist;
    Node(int x, int y, string el, ll dist) {
        this->x = x;
        this->y = y;
        this->el = el;
        this->dist = dist;
    }
};

struct Comparator {
    bool operator()(const Node &a, const Node &b) const {
        return a.dist > b.dist;
    }
};

bool isValid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> graph(n, vector<string>(n));
    
    int bricks = 0;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        size_t j = 0;     // ✅ size_t for string indexing
        int idx = 0;
        while (j < row.length()) {
            string nm = "";
            while (j < row.length() && row[j] >= '0' && row[j] <= '9') {
                nm += row[j++];
            }
            int nxt = stoi(nm);
            while (nxt-- && idx < n) {
                string el = to_string(bricks) + row[j];
                graph[i][idx++] = el;
            }
            j++;
            bricks++;
        }
    }

    priority_queue<Node, vector<Node>, Comparator> q;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (graph[i][j].back() == 'S')
                q.push({i, j, graph[i][j], 0});
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    ll res = INF;
    int dirx[] = {-1, 1, 0, 0};
    int diry[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto node = q.top();
        q.pop();
        if (graph[node.x][node.y].back() == 'D') {
            res = min(res, node.dist);
        }

        for (int i = 0; i < 4; i++) {
            int newx = node.x + dirx[i];
            int newy = node.y + diry[i];
            if (isValid(newx, newy, n) && !vis[newx][newy] && 
                (graph[newx][newy].back() == 'G' || graph[newx][newy].back() == 'D')) {
                
                vis[newx][newy] = true;
                if ((graph[newx][newy].back() == 'G') && (graph[newx][newy] != node.el))
                    q.push({newx, newy, graph[newx][newy], node.dist + 1});
                else
                    q.push({newx, newy, graph[newx][newy], node.dist});
            }
        }
    }

    cout << res << endl;
    return 0;
}
