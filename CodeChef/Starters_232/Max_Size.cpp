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


// standard SGT can be used since there r no range updates

class SGT{
    public:

    vll S;
    SGT(int n){
        S.resize(4*n + 1, 0);
    }

    void build(int idx, int low, int high, const vll &A){
        if(low == high){
            S[idx] = A[low];
            return;
        }

        int mid = (low + high)/2;

        build(2*idx + 1, low, mid, A);
        build(2*idx + 2, mid + 1, high, A);

        S[idx] = S[2*idx + 1] + S[2*idx + 2];
    }

    void pointUpdate(int idx, int low, int high, int targetIdx, ll newVal){
        if(low == high){
            S[idx] = newVal;
            return;
        }

        int m = (low + high)/2;

        if(targetIdx <= m)
            pointUpdate(2*idx + 1, low, m, targetIdx, newVal);
        else
            pointUpdate(2*idx + 2, m + 1, high, targetIdx, newVal);
        
        S[idx] = S[2*idx + 1] + S[2*idx + 2];
    }

    ll query(int idx, int low, int high, int L, int R){
        if(low > R || high < L)
            return 0;
        
        if(low >= L && high <= R)
            return S[idx];
        
        int m = (low + high)/2;

        ll left = query(2*idx + 1, low, m, L, R);
        ll right = query(2*idx + 2, m + 1, high, L, R);

        return left + right;
    }
};
void solve(){
    /*
    greedy always works, as in, the first index where it
    exceeds the target in the sorted prefix sum index, its the answer
    
    I have to group the queries by their X values
    as i build the sorted prefix array i have to answer the query

    if i have built the sorted prefix sum array 

    the best way to go about it
    start answering queries from X = N to all the way tille X = 1

    smartly performing these updates :

    let a = [5, 2, 3, 4, 3]
    sorted a = [2, 3, 3, 4, 5]

    consider c = [1, 1, 1, 1, 1] => (indicates whether element is present or not)

    build seg trees on both c and sorted a
    we can use binary search to find K such that sum <= y
    query seg tree for range (0, k) to find prefix sum of sorted a

    now the only change we need to do to move on to the X = N - 1
    is find the index of the last element in the sorted array
    then set seg[index] = c[index] = 0 to nullify its contribution
    next time answer will be cumulative sum of c till k, not k itself (cumulative sum of c indicates how many indices still present are taken)


    smartest way to do this
    create 2D vector with inner dimensions as element, original index, sorted index
    when we take input, sorted index will remain unassigned, we just assing element an og index

    after sorting we assign sorted index
    also build the segment tree on it

    after that we sort it based on og index to get original array back BUT now with sorted index (300 IQ lmao, credits to CC editorial)

    now while answering queries we know which index
    */
    int n, q; cin >> n >> q;

    vector<vector<int>> A(n, vector<int>(3)); // element, og index, sorted idx

    for(int i = 0; i < n; i++){
        cin >> A[i][0];
        A[i][1] = i;
    }

    sort(all(A));
    // instead of building from A, since it is a 3D arr, ill just do point update on every idx
    SGT arr(n), cnt(n);
    for(int i = 0; i < n; i++){
        arr.pointUpdate(0, 0, n - 1, i, A[i][0]);
        cnt.pointUpdate(0, 0, n - 1, i, 1);
        A[i][2] = i;
    }

    sort(all(A), [](const auto &a, const auto &b){
        return a[1] < b[1];
    }); // get og array back, but now with sorted indices

    // take in and group the queries
    vector<vector<pair<ll, int>>> Q(n);

    for(int i = 0; i < q; i++){
        int X; cin >> X;
        ll Y; cin >> Y;
        Q[X - 1].pb({Y, i});
    }

    // now answer queries as you go

    vi ans(q);
    for(int i = n - 1; i >= 0; i--){
        
        
        for(auto &[Y, j] : Q[i]){
            int L = 0, R = n - 1;

            while(L <= R){
                int M = (L + R)/2;

                ll presum = arr.query(0, 0, n - 1, 0, M);
                if(presum <= Y)
                    L = M + 1;
                else
                    R = M - 1;
            }

            ans[j] = cnt.query(0, 0, n - 1, 0, R);
        }

        // now update the values
        arr.pointUpdate(0, 0, n - 1, A[i][2], 0);
        cnt.pointUpdate(0, 0, n - 1, A[i][2], 0);
    }

    for(int i : ans)
        cout << i << nline;
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