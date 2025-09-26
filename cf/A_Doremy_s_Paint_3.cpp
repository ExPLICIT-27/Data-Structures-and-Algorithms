#include <bits/stdc++.h>
/*
4 7
3^n(a) - 2^n(b) >= 0
2^n(na - b) = 1
1 
*/
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        if(n <= 2){
            cout << "Yes" << endl;
            continue;
        }
        unordered_map<int, int> mp;
        for(int i : arr)
            mp[i]++;
        if(mp.size() >= 3){
            cout << "No" << endl;
            continue;
        }
        if(mp.size() == 1){
            cout << "Yes" << endl;
        }
        else{
            auto it = mp.begin();
            int first_freq = it->second;
            ++it;
            int second_freq = it->second;
            if(first_freq == second_freq || first_freq == second_freq - 1 || first_freq == second_freq + 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;

}