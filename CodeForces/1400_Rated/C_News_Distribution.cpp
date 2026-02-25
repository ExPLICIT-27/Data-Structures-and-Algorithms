#include <iostream>
#include <vector>
using namespace std;


class DSU{
    public:

    vector<int> P, S;
    DSU(int n){
        for(int i = 0; i <= n; i++){
            P.push_back(i);
            S.push_back(1);
        }
    }

    int findP(int x){
        if(x == P[x])
            return x;
        
        return P[x] = findP(P[x]);
    }

    void unionBySize(int u, int v){
        int u_p = findP(u), v_p = findP(v);

        if(u_p == v_p)
            return;

        if(S[u_p] > S[v_p]){
            P[v_p] = u_p;
            S[u_p] += S[v_p];
        }
        else{
            P[u_p] = v_p;
            S[v_p] += S[u_p];
        }
    }
};
void solve(){
    int n, m; cin >> n >> m;

    DSU ds(n);

    for(int g = 0; g < m; g++){
        int k; cin >> k;
        vector<int> nodes(k);
        for(int i = 0; i < k; i++){
            cin >> nodes[i];
        }
        for(int i = 1; i < k; i++)
            ds.unionBySize(nodes[0], nodes[i]);
    }

    for(int i = 1; i <= n; i++)
        cout << ds.S[ds.findP(i)] << " ";
    cout << endl;
}

int main(){
    solve();
    // int T;
    // cin >> T;

    // while(T--){
    //     solve();
    // }
    return 0;
}