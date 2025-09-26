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
        string str;
        cin >> str;
        // do for a, and do for b
        vector<long long> prefix_a(n, 0), prefix_b(n, 0), acount(n, 0), bcount(n, 0);
        for(int i = 0; i < n; i++){
            if(str[i] == 'a'){
                prefix_a[i] = i;
                acount[i] = 1;
            }
            else{
                prefix_b[i] = i;
                bcount[i] = 1;
            }
        }
        for(int i = 1; i < n; i++){
            prefix_a[i] += prefix_a[i - 1];
            acount[i] += acount[i - 1];
            prefix_b[i] += prefix_b[i - 1];
            bcount[i] += bcount[i - 1];
        }
        // do for each block of a and b
        int i = 0;
        long long result = LLONG_MAX;
        while(i < n){
            int start, end;
            if(str[i] == 'a'){
                start = i;
                while(i < n && str[i] == 'a')
                    i++;
                end = i;
                // do for left side
                // long long left = prefix_a[start] - prefix_a[0];
                // long long toleft = acount[start] - acount[0] - 1;
                // long long sub = toleft*(toleft + 1)/2;
                // left -= (toleft*start + sub);
                long long left = 0;
                if(start - 1 > 0 && acount[start - 1] != 0){
                    left = acount[start - 1]*start - prefix_a[start - 1] - acount[start - 1]*(acount[start - 1] + 1)/2;
                }
                // do for right side
                long long right = 0;
                if(end < n && acount.back() > acount[end]){
                    long long num = acount.back() - acount[end];
                    right = prefix_a.back() - prefix_a[end] - num*(end - 1) - num*(num + 1)/2;
                }
                result = min(result, left + right);

            }
            else{
                start = i;
                while(i < n && str[i] == 'b')
                    i++;
                end = min(n - 1, i);
                // do for left side
                long long left = 0;
                if(start - 1 > 0 && bcount[start - 1] != 0){
                    left = bcount[start - 1]*start - prefix_b[start - 1] - bcount[start - 1]*(bcount[start - 1] + 1)/2;
                }
                // do for right side
                long long right = 0;
                if(end < n && bcount.back() > bcount[end]){
                    long long num = bcount.back() - bcount[end];
                    right = prefix_b.back() - prefix_b[end] - num*(end - 1) - num*(num + 1)/2;
                }
                result = min(result, left + right);

            }
        }
        cout << result << endl;
    }
    return 0;

}