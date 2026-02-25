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
// binary exponentiation
ll binexp(ll a, ll b, ll M){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans*a)%M;
        b >>= 1;
        a = (a * a)%M;
    }

    return ans;
}
class SGT{
    public:

    vi A, S;
    SGT(vi &arr, int n){
        A = arr;
        S.resize(4*n + 1, 0);
    }

    void Build(int idx, int low, int high){
        if(low == high){
            S[idx] = A[low];
            return;
        }

        int m = (low + high)/2;

        Build(2*idx + 1, low, m);
        Build(2*idx + 2, m + 1, high);

        S[idx] = max(S[2*idx + 1], S[2*idx + 2]);
    }
    
    void pointUpdate(int idx, int low, int high, int targetIdx, int updatedVal){
        if(low == high){
            S[idx] = updatedVal;
            return;
        }

        int mid = (low + high)/2;

        if(targetIdx <= mid)
            pointUpdate(2*idx + 1, low, mid, targetIdx, updatedVal);
        else
            pointUpdate(2*idx + 2, mid + 1, high, targetIdx, updatedVal);
        S[idx] = max(S[2*idx + 1], S[2*idx + 2]);
    }

    int query(int idx, int low, int high, int L, int R){
        if(low >= L && high <= R)
            return S[idx];
        
        if(low > R || high < L)
            return 0;
        
        int mid = (low + high)/2;

        int left = query(2*idx + 1, low, mid, L, R);
        int right = query(2*idx + 2, mid + 1, high, L, R);

        return max(left, right);
    }
};
void solve(){
    int n; cin >> n;

    vi A(n);

    for(int &i : A)
        cin >> i;
    vi pge(n), nge(n);

    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && A[st.top()] < A[i])
            st.pop();

        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    st = stack<int>();

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && A[st.top()] < A[i])
            st.pop();
        
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<pii> B(n);

    for(int i = 0; i < n; i++)
        B[i] = {A[i], i};
    
    sort(all(B));
    // SGT tree on dp table with updates, precompute nge and pge
    // naive soln is O(n^2), need segment trees with lazy updates for the dp table
    // vi dp(n, 1);
    // for(auto &[h, i] : B){
    //     for(int j = i - 1; j >= 0; j--){
    //         if(A[j] >= h)
    //             break;
    //         dp[i] = max(dp[i], 1 + dp[j]);
    //     }

    //     for(int j = i + 1; j < n; j++){
    //         if(A[j] >= h)
    //             break;
    //         dp[i] = max(dp[i], 1 + dp[j]);
    //     }
    // }

    // cout << vmax(dp) << nline;
    vi dp(n, 1);

    SGT seg(dp, n);

    seg.Build(0, 0, n - 1);

    for(auto &[h, i] : B){
        int L, R;

        // left side
        L = pge[i] + 1, R = i - 1;

        if(L <= R){
            int mx = seg.query(0, 0, n - 1, L, R);
            if(dp[i] < 1 + mx){
                dp[i] = 1 + mx;
                seg.pointUpdate(0, 0, n - 1, i, dp[i]);
            }
        }

        // right side
        L = i + 1, R = nge[i] - 1;

        if(L <= R){
            int mx = seg.query(0, 0, n - 1, L, R);
            if(dp[i] < 1 + mx){
                dp[i] = 1 + mx;
                seg.pointUpdate(0, 0, n - 1, i, dp[i]);
            }
      
        }
    }


    cout << vmax(dp) << nline;
    
}
int main(){
    ExPLICIT_27;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    return 0;
}