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

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        ll pos = 0, neg = 0;
        for(int i : balance){
            if(i < 0)
                neg += llabs(i);
            else
                pos += llabs(i);
        }
        if(pos < neg)
            return -1;
        if(neg == 0)
            return 0;
        int nidx = -1;
        int n = balance.size();
        rep(i, 0, n){
            if(balance[i] < 0){
                nidx = i;
                break;
            }
        }
        ll moves = 0;
        vector<pll> M;
        rep(i, 0, n){
            if(i == nidx)
                continue;
            if(i < nidx){
                ll t = min(llabs(balance[nidx]), 1ll*balance[i])*(nidx - i);
                t = min(t, min(llabs(balance[nidx]), 1ll*balance[i])*(n - nidx + i));
                M.pb({t, i});
            }
            else{
                ll t = min(llabs(balance[nidx]), 1ll*balance[i])*(i - nidx);
                t = min(t, min(llabs(balance[nidx]), 1ll*balance[i])*(n - i + nidx));
                M.pb({t, i});
            }
        }
        sort(all(M), [&](const pair<ll, ll> &a, const pair<ll, ll> &b){
            int aless = min(nidx - a.ss, n - nidx + a.ss);
            int am = min(a.ss - nidx, n + nidx - a.ss);
            int bless = min(nidx - b.ss, n - nidx + b.ss);
            int bm = min(b.ss - nidx, n + nidx - b.ss);
            if(a.ss < nidx && b.ss < nidx)
                return aless < bless;
            else if(a.ss > nidx && b.ss < nidx)
                return am < bless;
            else if(a.ss > nidx && b.ss > nidx)
                return am < bm;
            else
                return aless < bm;
        });
        ll csum = llabs(balance[nidx]);
        rep(i, 0, sz(M)){
            if(M[i].ss == -1)
                continue;
            if(balance[M[i].ss] <= csum){
                csum -= balance[M[i].ss];
                moves += M[i].ff;
            }
            else{
                int idx = M[i].ss;
                if(idx < nidx){
                    ll cost = min(csum, 1ll*balance[idx])*(nidx - idx);
                    cost = min(cost, min(csum, 1ll*balance[idx])*(n - nidx + idx));
                    moves += cost;
                }
                else{
                    ll cost = min(csum, 1ll*balance[idx])*(idx - nidx);
                    cost = min(cost, min(csum, 1ll*balance[idx])*(n - idx + nidx));
                    moves += cost;
                }
                break;
            }
            if(csum == 0)
                break;
            
        }
        return moves;
    }
};