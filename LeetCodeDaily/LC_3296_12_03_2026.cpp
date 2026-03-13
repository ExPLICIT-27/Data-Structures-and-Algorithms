#include <bits/stdc++.h>

using namespace std;

#define ll long long
struct Worker{
    ll tt, ct, mul;
    Worker(){}
    Worker(ll tt, ll ct, ll mul) : tt(tt), ct(ct), mul(mul) {};
};

struct Comparator{
    bool operator()(const Worker &a, const Worker &b) const {
        return a.tt > b.tt;
    }
};
// first approach -> priority queue O(H*log(N))
class Solution1 {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll ans = 0;

        priority_queue<Worker, vector<Worker>, Comparator> pq;

        int n = workerTimes.size();
        for(int i = 0; i < n; i++)
            pq.push(Worker(workerTimes[i], workerTimes[i], 1));
        
        for(int i = 0; i < mountainHeight; i++){
            auto fr = pq.top();
            pq.pop();

            ll nxt = (fr.ct/fr.mul)*(fr.mul + 1);
            ll tot = fr.tt + nxt;
            ans = max(ans, fr.tt);
            pq.push(Worker(tot, nxt, fr.mul + 1));
        }

        return ans;
    }
};
// approach two - BS O(N*Log(R))
#define ll long long
class Solution2 {
public:
    long long minNumberOfSeconds(int H, vector<int>& WT) {
        int max_w = *max_element(WT.begin(), WT.end());

        ll L = 0, R = 1ll*max_w*(1ll*H*(H + 1)/2);

        while(L <= R){
            ll M = (L + R)/2;
            /*
            M represents max time each worker should be workin
            hence WT[i]*(k*(k + 1)/2) <= M
            can do binary search on k for each worker -> logarithmic
            use quadratic formula?
            k^2 + k = 2*M/WT[i]
            k^2 + k - 2*M/WT[i]
            root = (-b +- root(b^2 - 4ac))/2a, c is neg so inside root becomes +
            k = (-1 +- root(1 + 4*2*M/WT[i]))/2
            take +, cause the we dont want negative k
            k = (-1 + root(1 + 4*2*M/WT[i]))/2
            */
            ll completed = 0;

            for(int w : WT){
                ll k = (-1 + sqrt(1ll + 8*M/w))/2;
                completed += k;
            }

            if(completed >= H)
                R = M - 1;
            else
                L = M + 1;
        }

        return L;
    }
};