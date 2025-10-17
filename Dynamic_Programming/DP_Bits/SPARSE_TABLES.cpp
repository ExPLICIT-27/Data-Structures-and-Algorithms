    /*
    To find minimum/maximum queries in range[L, R] in O(1) time
    requires Nlog(N) preprocessing

    logic is to store the maximum min, max values for all subarrays with length of powers of 2
    (length 0, 1, 2, 4)
    and then utilize them to obtain any min max within rangw [L, R]
    for eg : [1,3,4,5,6,2,1,9,7,6,2,1,3,4]
    for index 3 to 8
    [5,6,2,1,9,7]
    find the largest power of 2 <= query length
    here 2**2 <= 6
    find answer for 5,6,2,1 using precomputed values
    then find answer for 2,1,9,7 (we dont care if it overlaps as the overall range remains the same) 


    constructing the sparse table:
    - since we are storing the min/max value starting from every index to the end, and from each index to end there is at most log(N) values 
    we need a N*log(N) array
    - for all subarrays of size 1, the min/max is the element itself, therefore 
        for i = 0 to N - 1
            sparse[i][0] = arr[i] // by 0 we mean 1 - 0 (2**i - 1 for accounting for 0 based indexing)
    - find for all others
    - for k = 1 to LOG(N)  // for all 2** subarray sizes
        for i = 0 to i + (1 << (k - 1)) < N(go till whatever's possible), 
            set sparse[i][k] = min(sparse[i][k - 1], sparse[i + (1 <<(k - 1))][k - 1]) 

    - handling range query for [L, R]
    length = R - L + 1
    bits = log2(length)
    // do the overlap thing 
    return min(sparse[L][bits], sparse[R - (1<<bits) + 1][bits])
    */

    #include <bits/stdc++.h>

    using namespace std;
    // minimum query sparse table
    vector<vector<int>> buildTable(vector<int> &nums){
        int n = nums.size();
        int LOG = log2(n) + 1;

        vector<vector<int>> sparse(n, vector<int>(LOG));

        // for size = 1, every element is itself min/max
        for(int i = 0; i < n; i++){
            sparse[i][0] = nums[i];
        }

        for(int j = 1; j < LOG; j++){
            for(int i = 0; (i + (1 << j) - 1) < n; i++){
                sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]); // max for max sparse table
            }
        }

        return sparse;
    }

    // query function
    int query(vector<vector<int>> &sparse, int L, int R){
        int length = R - L + 1;
        int bits = log2(length);
        return min(sparse[L][bits], sparse[R - (1 << bits) + 1][bits]);
    }
    int main(){
        vector<int> arr = {4, 2, 5, 1};
        auto sparse = buildTable(arr);
        cout << query(sparse, 2, 3);
        return 0;
    }