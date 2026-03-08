#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int minFlips(string s) {
        /*
        can use as many type 1 ops as i want
        need to minimize type 2 flips

        type 1 always is associated with the prefix
        and the only way it affects type 2 count is its
        current count + the parity of the first and last character

        idea 1
        build prefix counts for 01 and 10 type and see what the answer is 
        then the change in how the ans would be is
        
        ans = min(pre10[n - 1] - pre10[i - 1] + pre01[i - 1] + .. , pre01[n - 1] - pre01[i - 1] + pre10[i - 1])
        
        correction : as i implemented i realized

        you need to build a suffix as well otherwise it wouldnt make sense
        cause if you delete and push elements to the end, then you have to see from THAT index what is the amount of ops required, prefix always builds from the start, hence its useful only for checking
        the number of ops required for pushing a particular prefix to the end

        modified correct formula

        int c1 = suff10[i] + pre01[i - 1];
        int c2 = suff01[i] + pre10[i - 1];

        ans = min(ans, min(c1, c2))
        */
        int n = s.size();
        vector<int> pre10(n, 0), pre01(n, 0);

        
        // should i build the prefix in reverse?, lemme try
        /*
        i need front AND back
        */

        if(s[0] == '0')
            pre10[0]++;
        else
            pre01[0]++;

        for(int i = 1; i < n; i++){
            if(i & 1){
                if(s[i] == '0'){
                    pre01[i] = 1 + pre01[i - 1];
                    pre10[i] = pre10[i - 1];
                }
                else{
                    pre10[i] = 1 + pre10[i - 1];
                    pre01[i] = pre01[i - 1];
                }
            }
            else{
                if(s[i] == '1'){
                    pre01[i] = 1 + pre01[i - 1];
                    pre10[i] = pre10[i - 1];
                }
                else{
                    pre10[i] = 1 + pre10[i - 1];
                    pre01[i] = pre01[i - 1];
                }
            }
        }
        // back suffix
        vector<int> suff10(n, 0), suff01(n, 0);

        if(s[n - 1] == '0')
            suff10[n - 1]++;
        else
            suff01[n - 1]++;
        int parity = 1;
        for(int i = n - 2; i >= 0; i--){
            if(parity & 1){
                if(s[i] == '0'){
                    suff01[i] = 1 + suff01[i + 1];
                    suff10[i] = suff10[i + 1];
                }
                else{
                    suff10[i] = 1 + suff10[i + 1];
                    suff01[i] = suff01[i + 1];
                }
            }
            else{
                if(s[i] == '1'){
                    suff01[i] = 1 + suff01[i + 1];
                    suff10[i] = suff10[i + 1];
                }
                else{
                    suff10[i] = 1 + suff10[i + 1];
                    suff01[i] = suff01[i + 1];
                }
            }
            parity++;
        }

        int ans = min(pre10[n - 1], pre01[n - 1]);
        
        for(int i = 1; i < n; i++){
            int c1 = suff10[i] + pre01[i - 1];// suff 10 => ....01 + pre01 gives ...010...
            int c2 = suff01[i] + pre10[i - 1]; // ....101....

            ans = min(ans, min(c2, c1));
        }

        return ans;
    }
};