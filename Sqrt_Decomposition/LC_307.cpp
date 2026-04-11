#include <bits/stdc++.h>

using namespace std;
/*
ill do sqrt decomp, because ive just learned it

as the name suggests, divide the array into blocks of size ceil(sqrt(n))

store each block sum in an block array

now for query =>
if l and r are in the same block, just iterate (O(root(n))) time

if l and r are different blocks

iterate from l to end of l block O(root(n))
iterate all blocks in between l and r block O(root(n))
iterate last block to r (O(root(n)))

O(3*root(n)) = O(root(n))
done
*/
class NumArray {
public:
    vector<int> A, B;
    int n, bsize;
    NumArray(vector<int>& nums) {
        A = nums;
        n = nums.size();

        bsize = int(ceil(sqrt(n)));
        B.resize(bsize);

        for(int i = 0; i < n; i++){
            B[i/bsize] += A[i];
        }
    }   
    
    void update(int index, int val) {
        int b = index/bsize;

        B[b] -= A[index];
        B[b] += val;
        A[index] = val;
    }
    
    int sumRange(int left, int right) {
        int s = left/bsize, e = right/bsize;

        int ans = 0;
        if(s == e){
            // within same block, ez root(n)
            for(int i = left; i <= right; i++)
                ans += A[i];
            
            return ans;
        }

        // partial block of left side
        int se = (s + 1)*bsize - 1;
        for(int i = left; i <= se; i++)
            ans += A[i];
        
        // da middle blocks
        for(int i = s + 1; i < e; i++)
            ans += B[i];
        
        // partial right block
        int be = e*bsize;
        for(int i = be; i <= right; i++)
            ans += A[i];
        
        return ans;

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */