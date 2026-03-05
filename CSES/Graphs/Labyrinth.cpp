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
 

void solve(){
    int n, m; cin >> n >> m;
 
    vector<string> G(n);
 
 
    for(auto &s : G)
        cin >> s;
    
    // find the number of connected components
 
    auto isValid = [&](int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    };
 
    /*
    find location of A -> O(n*m)
    find location of B -> O(n*m)
 
    bfs to get path -> O(n*m)
    store path -> for each path store string -> O(max(n, m)*n*m)
    */
    // lets see
 
 
 
    auto findLoc = [&](char c){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(G[i][j] == c)
                    return make_pair(i, j);
            }
        }
 
        return make_pair(-1, -1);
    };
 
    pii start = findLoc('A'), end = findLoc('B');
 
    int dirx[] = {0, 0, 1, -1};
    int diry[] = {1, -1, 0, 0};
    string dir = "RLDU";
    auto findDist = [&](){
        // use parent array for storing the path

        vector<vector<char>> parent(n, vector<char>(m, '#'));


        queue<pii> Q;

        Q.push({start.ff, start.ss});
        parent[start.ff][start.ss] = '$';


        while(!Q.empty()){
            auto u = Q.front();
            Q.pop();

            if(u.ff == end.ff && u.ss == end.ss)
                break;
            
            for(int i = 0; i < 4; i++){
                int nx = u.ff + dirx[i];
                int ny = u.ss + diry[i];

                if(isValid(nx, ny) && parent[nx][ny] == '#' && G[nx][ny] != '#'){
                    parent[nx][ny] = dir[i];
                    Q.push({nx, ny});
                }
            }
        }

        if(parent[end.ff][end.ss] == '#')
            return make_pair(-1, string(1, 'n'));
        
        int x = end.ff, y = end.ss;
        string path = "";
        while(x != start.ff || y != start.ss){
            path += parent[x][y];
            
            if(parent[x][y] == 'U')
                x++;
            else if(parent[x][y] == 'L')
                y++;
            else if(parent[x][y] == 'D')
                x--;
            else
                y--;
        }
        reverse(all(path));
        return make_pair(sz(path), path);
    };
 
 
    auto ans = findDist();
 
 
    if(ans.ff == -1)
        cout << "NO\n";
    else{
        cout << "YES\n";
        cout << ans.ff << "\n" << ans.ss << nline;
    }
    
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