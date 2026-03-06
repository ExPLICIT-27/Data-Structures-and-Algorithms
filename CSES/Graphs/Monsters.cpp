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
#define nline '\n'
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
#define ExPLICIT_27 ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

// ---------- PBDS ---------- policy based data strcutures, faster sets and maps
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered Set (no duplicates)
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Ordered Multiset (allows duplicates using unique IDs)
template<typename T>
using ordered_multiset = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Ordered Map (key → value)
template<typename K, typename V>
using ordered_map = tree<
    pair<K,V>,
    null_type,
    less<pair<K,V>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

struct Node{
    int x, y, t;

    Node(){}
    Node(int x, int y, int t) : x(x), y(y), t(t) {}
};
void solve(){
    int n, m; cin >> n >> m;

    vector<string> G(n);

    for(auto &s : G)
        cin >> s;


    /*
    Idea 1
    Use multisource bfs from the monsters and determine the time they take to reach every cell

    now use bfs from the starting node with one of the restricting factors being moving to a cell with higher time
    than the least possible time achieved by a monster
    yep this works :)
    */

    // multi src bfs for the monsters
    queue<Node> Q;
    pii start;

    vector<vi> time(n, vi(m, INT_MAX));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(G[i][j] == 'M'){
                Q.push({i, j, 0});
                time[i][j] = 0;
            }
            if(G[i][j] == 'A'){
                start.ff = i, start.ss = j;
            }
        }
    }

    int dirx[] = {1, -1, 0, 0};
    int diry[] = {0, 0, 1, -1};

    auto isValid = [&](int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    while(!Q.empty()){

        auto u = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++){
            int nx = u.x + dirx[i];
            int ny = u.y + diry[i];
            if(isValid(nx, ny) && G[nx][ny] != '#' && time[nx][ny] == INT_MAX){
                Q.push({nx, ny, u.t + 1});
                time[nx][ny] = u.t + 1;
            }
        }
    }


    /*
    condition for border ?
    i == 0 or j == 0
    i == n - 1 or j == m - 1
    */
    auto checkBoundary = [&](int i, int j){
        return i == 0 || i == n - 1 || j == 0 || j == m - 1;
    };

    Q.push({start.ff, start.ss, 0});

    vector<vector<char>> path(n, vector<char>(m, '$'));

    pii border = {-1, -1};


    auto updPath = [&](int nx, int ny, int i){
        if(i == 0)
            path[nx][ny] = 'D';
        else if(i == 1)
            path[nx][ny] = 'U';
        else if(i == 2)
            path[nx][ny] = 'R';
        else
            path[nx][ny] = 'L';
    };

    // bfs for the starting position, DONT FORGET THE !VISITED CONDITION (USE PATH ARRAY ONLY)
    while(!Q.empty()){
        auto u = Q.front();
        Q.pop();
        if(checkBoundary(u.x, u.y)){
            border = make_pair(u.x, u.y);
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = u.x + dirx[i];
            int ny = u.y + diry[i];
            
            if(isValid(nx, ny) && G[nx][ny] != '#' && (u.t + 1) < time[nx][ny] && path[nx][ny] == '$'){
                updPath(nx, ny, i);
                Q.push({nx, ny, u.t + 1});
            }
        }
    }
    
    if(border.ff == -1){
        cout << "NO\n";
        return;
    }

    int x = border.ff, y = border.ss;

    string pathStr = "";
    while(x != start.ff || y != start.ss){
        
        pathStr += path[x][y];

        if(path[x][y] == 'D')
            x--;
        else if(path[x][y] == 'L')
            y++;
        else if(path[x][y] == 'R')
            y--;
        else
            x++;
    }

    reverse(all(pathStr));
    cout << "YES\n";
    cout << sz(pathStr) << nline;

    cout << pathStr << nline;
    
}
int main(){
    ExPLICIT_27;
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }

    return 0;
}