#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int si) {
        int n = words.size();

        int forw = -1, dist = 0;
        int i = si;
        do{
            if(words[i] == target){
                forw = dist;
                break;
            }
            dist++;
            i = (i + 1)%n;
        }while(i != si);
        
        int back = -1;
        i = si, dist = 0;
        do{
            if(words[i] == target){
                back = dist;
                break;
            }
            dist++;
            i = ((i - 1)%n + n)%n;
        }while(i != si);

        return (forw == -1 || back == -1)? max(forw, back) : min(forw, back);

    }
};