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
#include <fstream>


bool isValid(int x, int y, int N, int M){
    return (x >= 0 && x < N && y >= 0 && y < M);
}

struct Node{
    int x, y, c;
    Node(int x, int y, int c){
        this->x = x;
        this->y = y;
        this->c = c;
    }
};
struct Comparator {
    bool operator()(const Node &A, const Node &B) const {
        if (A.c != B.c) return A.c < B.c;
        if (A.x != B.x) return A.x < B.x;
        return A.y < B.y;
    }
};

int main(){
    
    ifstream file("input_4.txt");
    if (!file.is_open()) return 1;

    string line;

    vector<string> V;
    while(getline(file, line)){
        if(!line.empty())
            V.pb(line);
    }
    int N = sz(V), M = sz(V[0]);

    int dirx[] = {0, 0, -1, 1, -1, -1, 1, 1};
    int diry[] = {-1, 1, 0, 0, -1, 1, -1, 1};

    ll ans = 0;
    map<pii, int> mp;
    set<Node, Comparator> S;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(V[i][j] == '@'){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int nx = i + dirx[k];
                    int ny = j + diry[k];

                    if(isValid(nx, ny, N, M) && V[nx][ny] == '@')
                        cnt++;
                }
                mp[{i, j}] = cnt;
                S.insert(Node(i, j, cnt));
            }
        }
    }
    while(!S.empty()){
        auto u = *(S.begin());
        if(u.c < 4)
            ans++;
        else
            break;
        S.erase(S.begin());
        mp.erase({u.x, u.y});
        for(int i = 0; i < 8; i++){
            int nx = u.x + dirx[i];
            int ny = u.y + diry[i];
            if(mp.count({nx, ny})){
                Node v = Node(nx, ny, mp[{nx, ny}] - 1);
                S.erase({nx, ny, mp[{nx, ny}]});
                mp[{nx, ny}]--;
                S.insert(v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}