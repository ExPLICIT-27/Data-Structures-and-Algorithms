#include <bits/stdc++.h>

using namespace std;

int findSmallestInteger(vector<int>& nums, int value) {
    vector<int> mp(value, -1);
    int n = nums.size();
    vector<bool> marked(n + 1, false);
    for(int &i : nums){
        int tmp = (i%value + value)%value;
        if(mp[tmp] != -1){
            i = mp[tmp] + value;
            mp[tmp] = i;
        }
        else{
            mp[tmp] = tmp;
            i = tmp;
        }
        if(i <= n)
            marked[i] = true;
    }
    for(int i = 0; i < n + 1; i++){
        if(!marked[i])
            return i;
    }

    return marked.size();
}
int main(){
    return 0;
}