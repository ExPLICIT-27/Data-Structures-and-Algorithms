#include <bits/stdc++.h>

using namespace std;

// O(n) soln
class Solution {
public:
    char findKthBit(int n, int k) {
        /*
        suppose you are currently on string Sn
        if k < half the length of Sn, that means it lies in its left half, i.e Sn-1
        if k == half, then the ans is 1 because
        Sn = Sn-1 + '1' + revert_invert(Sn-1)

        if k > half
        then ans is in the right half but reversed and inverted
        hence call on the right half with length of Sn - k instead of k
        */

        if(n == 1)
            return '0';
        
        int L = (1 << n);

        if(k < L/2)
            return findKthBit(n - 1, k);
        if(k == L/2)
            return '1';
        
        char bit = findKthBit(n - 1, L - k);

        return '0' + ('1' - bit);
    }
};