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

// ---------- PBDS ----------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename K, typename V>
using ordered_map = tree<pair<K,V>, null_type, less<pair<K,V>>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int h, w; cin >> h >> w;

    vector<vector<char>> G(h, vector<char>(w));

    pii start, goal;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> G[i][j];

            if(G[i][j] == 'S')
                start = {i, j};
            if(G[i][j] == 'G')
                goal = {i, j};
        }
    }

    /*
    here dirn of entry matters as well
    itll be h*w*4 grid

    instead of maintaining a 3D grid of visited and parent which is difficult to track
    encode the 3D coordinate into 1D
    h*w*4 
    given x, y, dir

    encode, row major = (x*w + y)*4 + dir


    in general if we had dimensions d1, d2, d3, ... dn
    encoding would be x1*d2*d3...dn + x2*d3*d4...dn
    */

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char move[] = {'D', 'U', 'R', 'L'};

    auto encode = [&](int x, int y, int dir) -> int {
        return (x*w + y)*4 + dir;
    };

    auto decode = [&](int code) -> array<int, 3> {
        int dir = code%4;
        code /= 4;
        int y = code%w;;
        int x = code/w;

        return array<int, 3>{x, y, dir};
    };


    queue<int> q;
    int mxsize = h*w*4;
    vector<int> par(mxsize, -1);
    vector<bool> vis(mxsize, false);

    int st = encode(start.ff, start.ss, 0);

    q.push(st);
    vis[st] = true;

    int gl = -1;


    auto isvalid = [&](int x, int y) -> bool {
        return (x >= 0 && x < h && y >= 0 && y < w && G[x][y] != '#');
    };

    while(!q.empty()){
    
        int curr = q.front();
        q.pop();

        auto [x, y, dir] = decode(curr);


        if(x == goal.ff && y == goal.ss){
            gl = curr;
            break;
        }
        for(int i = 0; i < 4; i++){
            if((G[x][y] == 'o' && i != dir) || (G[x][y] == 'x' && i == dir))
                continue;
            
            int nx = x + dx[i], ny = y + dy[i];
            
            int nxt = encode(nx, ny, i);

            if(!isvalid(nx, ny) || vis[nxt])
                continue;
            
            vis[nxt] = true;
            q.push(nxt);
            par[nxt] = curr;
        }
    }

    if(gl == -1){
        cout << "No\n";
        return;
    }

    string ans = "";

    int curr = gl;

    while(par[curr] != -1){
        
        int dir = curr%4;
        ans += move[dir];

        curr = par[curr];
    }

    reverse(all(ans));

    cout << "Yes\n" << ans;


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