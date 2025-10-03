
#include <bits/stdc++.h>
using namespace std;

// ---------- Typedefs ----------
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define usi unordered_set<int>
#define si set<int>

// ---------- Macros ----------
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// ---------- Fast IO ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;


int main() {
    fastio;

    int T; 
    cin >> T;
    while (T--) {
        int result = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                char tmp;
                cin >> tmp;
                if(tmp == 'X'){
                    if(i == 0){
                        result++;
                    }
                    else if(i == 1){
                        if(j == 0 || j == 9)
                            result++;
                        else
                            result += 2;
                    }
                    else if(i == 2){
                        if(j == 0 || j == 9)
                            result++;
                        else if(j == 1 || j == 8)
                            result += 2;
                        else
                            result += 3;
                    }
                    else if(i == 3){
                        if(j == 0 || j == 9)
                            result++;
                        else if(j == 1 || j == 8)
                            result += 2;
                        else if(j == 2 || j == 7)
                            result += 3;
                        else 
                            result += 4;
                    }
                    else if(i == 4){
                        if(j == 0 || j == 9)
                            result++;
                        else if(j == 1 || j == 8)
                            result += 2;
                        else if(j == 2 || j == 7)
                            result += 3;
                        else if(j == 3 || j == 6) 
                            result += 4;
                        else
                            result += 5;
                    }
                    else if(i == 5){
                        if(j == 0 || j == 9)
                            result++;
                        else if(j == 1 || j == 8)
                            result += 2;
                        else if(j == 2 || j == 7)
                            result += 3;
                        else if(j == 3 || j == 6) 
                            result += 4;
                        else
                            result += 5;
                    }
                    else if(i == 6){
                        if(j == 0 || j == 9)
                            result++;
                        else if(j == 1 || j == 8)
                            result += 2;
                        else if(j == 2 || j == 7)
                            result += 3;
                        else 
                            result += 4;
                    }
                    else if(i == 7){
                        if(j == 0 || j == 9)
                            result++;
                        else if(j == 1 || j == 8)
                            result += 2;
                        else
                            result += 3;
                    }
                    else if(i == 8){
                        if(j == 0 || j == 9)
                            result++;
                        else
                            result += 2;
                    }
                    else
                        result++;
                }
            }
        }
        cout << result << endl;
        
    }

    return 0;
}
