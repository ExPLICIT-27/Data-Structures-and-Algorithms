#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    string decodeCiphertext(string enc, int rows) {
        int n = enc.size();
        int cols = (n + rows - 1)/rows;

        if(enc.empty())
            return "";

        // we'll start from i == j, and go for all cases where i < j

        /*
        to get pair (r, c) from i as i goes through enc

        r = i/cols
        c = i%cols
        
        first try by making the grid only

        r*cols + c
        */

        
        
        
        string dec = "";
        for(int k = 0; k < cols; k++){
            for(int r = 0, c = k; r < rows && c < cols; r++, c++)
                dec += enc[r*cols + c];
        }

        while(!dec.empty() && dec.back() == ' ')
            dec.pop_back();
        
        return dec;
    }
};