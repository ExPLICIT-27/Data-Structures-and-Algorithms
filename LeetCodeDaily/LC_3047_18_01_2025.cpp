#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Square{
    public:
    ll a, b, c, d;
    Square() : a(0), b(0), c(0), d(0) {}
    Square(ll a, ll b, ll c, ll d){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
};
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& BR, vector<vector<int>>& TR) {
        int n = BR.size();
        vector<Square> V(n);


        for(int i = 0; i < n; i++){
            V[i] = Square(BR[i][0], BR[i][1], TR[i][0], TR[i][1]);
        }


        sort(V.begin(), V.end(), [](Square &a, Square &b){
            if(a.a != b.a)
                return a.a < b.a;
            if(a.c != b.c)
                return a.c < b.c;
            if(a.b != b.b)
                return a.b < b.b;    
            return a.d < b.d;
        });
        ll ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ll a1 = V[i].a, c1 = V[i].c, a2 = V[j].a, c2 = V[j].c;
                ll b1 = V[i].b, d1 = V[i].d, b2 = V[j].b, d2 = V[j].d;

                
                ll ff = min(c1, c2) - max(a1, a2), ss = min(d1, d2) - max(b1, b2);

                if(ff <= 0 || ss <= 0)
                    continue;

                ans = max(ans, min(ff, ss));

            }
        }


        return ans*ans;
    }
};