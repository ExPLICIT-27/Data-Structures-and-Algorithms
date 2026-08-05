#include <bits/stdc++.h>

using namespace std;


// O(N*LOG(N)) solution
vector<int> maxSlidingWindowSet(vector<int>& nums, int k) {
        
    multiset<int, greater<int>> mset;

    int N = nums.size();

    vector<int> ans(N - k + 1);
    for(int i = 0; i < N; i++){
        mset.insert(nums[i]);

        if(i >= k){
            mset.erase(mset.find(nums[i - k]));
            ans[i - k + 1] = *mset.begin();
        }
        if(i == k - 1)
            ans[0] = *mset.begin();
    }

    return ans;
}


// O(N) soln
vector<int> maxSlidingWindowDQ(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    int N = nums.size();


    // insert operation at the back
    auto backop = [&](int i) -> void {
        while(!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    };

    // delete op from the front
    auto frontop = [&](int i) -> void {
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
    };

    // process first window
    for(int i = 0; i < k; i++){
        backop(i);
    }

    // remaining window, starting stores the prev windows answer
    for(int i = k; i < N; i++){
        ans.push_back(nums[dq.front()]);

        frontop(i);
        backop(i);
    }

    // final window ans
    ans.push_back(nums[dq.front()]);


    return ans;
}
int main(){
    return 0;
}