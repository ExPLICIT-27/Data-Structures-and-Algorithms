#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'
// Ordered Multiset (allows duplicates using unique IDs)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


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

void solve() {
    ordered_multiset<int> S;

    int id = 0;

    int x; cin >> x;

    S.insert(make_pair(x, id++));

    int q; cin >> q;

    int cnt = 1;
    while(q--){
        int a, b; cin >> a >> b;

        cnt += 2;
        
        S.insert(make_pair(a, id++));
        S.insert(make_pair(b, id++));

        auto it = S.find_by_order(cnt/2);


        cout << (*it).first << nline;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}