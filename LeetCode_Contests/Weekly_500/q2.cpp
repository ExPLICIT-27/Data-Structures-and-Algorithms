#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int r = 0;
        int t = n;

        while(t){
            r = r*10 + t%10;
            t /= 10;
        }

        int L = min(n, r), R = max(n, r);

        auto isPrime = [&](int n) -> bool {
            if(n <= 1)
                return false;

            for(int i = 2; i*i <= n; i++)
                if(n%i == 0)
                    return false;

            return true;
        };

        int ans = 0;
        for(int i = L; i <= R; i++)
            if(isPrime(i))
                ans += i;


        return ans;
            
    }
};