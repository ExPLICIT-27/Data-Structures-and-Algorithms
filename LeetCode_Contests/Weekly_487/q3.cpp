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
class RideSharingSystem {
public:
    umap<int, int> match1, match2;
    umap<int, pii> mp1, mp2;
    set<pii, less<pii>> rider;
    set<pii, less<pii>> driver;
    ll time = 0;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        mp1[riderId] = {time, riderId};
        rider.insert({time++, riderId});
    }
    
    void addDriver(int driverId) {
        mp2[driverId] = {time, driverId};
        driver.insert({time++, driverId});
    }
    
    vector<int> matchDriverWithRider() {
        if(sz(match1) == sz(rider) || sz(match2) == sz(driver))
            return {-1, -1};

        int r = -1, d = -1;
        for(auto &p : rider){
            if(!match1.count(p.ss)){
                r = p.ss;
                break;
            }
        }

        for(auto &p : driver){
            if(!match2.count(p.ss)){
                d = p.ss;
                break;
            }
        }
        if(r != -1 && d != -1){
            match1[r] = d;
            match2[d] = r;
            return {d, r};
        }

        return {-1, -1};
        
    }
    
    void cancelRider(int riderId) {
        if(match1.count(riderId)){
            return;
        }
        if(mp1.count(riderId)){
            rider.erase(mp1[riderId]);
            mp1.erase(riderId);
        }
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */