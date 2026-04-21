#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        // sides is always of len 3
        sort(sides.begin(), sides.end(), greater<int>());
        int s1 = sides[0], s2 = sides[1], s3 = sides[2];
        if(s1 >= (s2 + s3))
            return {};
        /*
        
        */
        double cos1 = (s1*s1 + s2*s2 - s3*s3*1.0)/(2.0*s1*s2);
        double cos2 = (s1*s1 + s3*s3 - s2*s2*1.0)/(2.0*s1*s3);
        double cos3 = (s2*s2 + s3*s3 - s1*s1*1.0)/(2.0*s2*s3);

        double pi = acos(-1.0);
        double a1 = acos(cos1)*180.0/pi, a2 = acos(cos2)*180.0/pi, a3 = acos(cos3)*180.0/pi;

        vector<double> ans = {a1, a2, a3};
        sort(ans.begin(), ans.end());

        return ans;
        
    }
};