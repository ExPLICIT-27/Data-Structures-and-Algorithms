#include <bits/stdc++.h>
/*
4 7
3^n(a) - 2^n(b) >= 0
2^n(na - b) = 1

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
        if(n == 1){
            cout << "Yes" << endl;
            continue;
        }
        if(n == 2){
            if(arr[0] > arr[1])
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
            continue;
        }
        bool can = true;
        for(int i = 1; i < n - 1; i++){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
                if(arr[i + 1] > arr[i - 1]){
                    can = false;
                    break;
                }
                else
                    swap(arr[i], arr[i + 1]);
            }
        }
        if(!can)
            cout << "No" << endl;
        else{
            for(int i = 1; i < n; i++){
                if(arr[i] < arr[i - 1]){
                    can = false;
                    break;
                }
            }
            if(can)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

    }
    return 0;

}