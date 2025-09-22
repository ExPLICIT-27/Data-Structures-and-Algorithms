/*
core logic: sparse tables for min and max queries
important observation : from any index l, to the end, as you keeep decreasing the end, the value (max - min) always decreases
store this l, n-1 for all l in a pq
while pq is not empty and k is non zero
pop out the value, if the right > left, we find value for that and push it into the pq
*/
#include <bits/stdc++.h>

using namespace std;

// sparse table construction
pair<vector<vector<int>>, vector<vector<int>>> minMaxTable(vector<int> &nums){
    int n = nums.size();
    int LOG = int(log2(n)) + 1;
    vector<vector<int>> minSparse(n, vector<int>(LOG));
    vector<vector<int>> maxSparse(n, vector<int>(LOG));
    for(int i = 0; i < n; i++)  
        minSparse[i][0] = maxSparse[i][0] = nums[i];
    
    for(int j = 1; j < LOG; j++){
        for(int i = 0;(i + (1 << j) - 1) < n; i++){
            minSparse[i][j] = min(minSparse[i][j - 1], minSparse[i + (1 << (j - 1))][j - 1]);
            maxSparse[i][j] = max(maxSparse[i][j - 1], maxSparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    return {minSparse, maxSparse};
}

// min max query
pair<int, int> query(vector<vector<int>> &mis, vector<vector<int>> &mas, vector<int> &nums, int L, int R){
    int length = R - L + 1;
    int bits = log2(length);
    int maxel = max(mas[L][bits], mas[R - (1 << bits) + 1][bits]);
    int minel = min(mis[L][bits], mis[R - (1 << bits) + 1][bits]);

    return {maxel, minel};
}
// main fucntion

long long maxTotalValue(vector<int>& nums, int k) {
    priority_queue<vector<int>, vector<vector<int>>> pq;
    auto [mis, mas] = minMaxTable(nums);
    int n = nums.size();
    for(int i = 0; i < n; i++){
        auto [mx, mi] = query(mis, mas, nums, i, n - 1);
        pq.push({mx - mi, i, n - 1});
    }

    long long count = 0;
    while(!pq.empty() && k > 0){
        auto top = pq.top();
        pq.pop();
        count += 1LL*top[0];
        k--;
        if(top[2] > top[1]){
            auto [mx, mi] = query(mis, mas, nums, top[1], top[2] - 1);
            pq.push({mx - mi, top[1], top[2] - 1});
        }
    }
    return count;
}
int main(){
    return 0;
}