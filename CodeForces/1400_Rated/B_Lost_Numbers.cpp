#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


struct Pair{
    int x, y;
    Pair(){}
    Pair(int x, int y) : x(x) , y(y) {}
};
void solve(){
    map<int, Pair> mp;

    vector<int> A = {4, 8, 15, 16, 23, 42};

    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++)
            mp[A[i]*A[j]] = Pair(A[i], A[j]);
    }

    vector<int> ans(5);

    for(int i = 1; i <= 4; i++){
        int l = i, r = i + 1;
        cout << "? " << l << " " << r << endl;
        int prod; cin >> prod;
        ans[i] = prod;
    }
    vector<int> output(6);
    set<int> S = {4, 8, 15, 16, 23, 42};
    for(int i = 1; i < 4; i++){
        int p1 = ans[i], p2 = ans[i + 1];
        auto pair1 = mp[p1], pair2 = mp[p2];

        map<int, int> mp2;
        mp2[pair1.x]++, mp2[pair1.y]++, mp2[pair2.x]++, mp2[pair2.y]++;
        for(auto &p : mp2){
            if(p.second == 2){
                output[i] = p.first;
                break;
            }
        }
        output[i - 1] = p1/output[i];
        output[i + 1] = p2/output[i];
        for(int j = i - 1; j <= i + 1; j++){
            if(S.count(output[j]))
                S.erase(output[j]);
        }
    }
    output[5] = *(S.begin());
    cout << "! ";
    for(int i : output)
        cout << i << " ";
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