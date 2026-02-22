#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<long long>> nCr(55, vector<long long>(55, 0));


    for(int i = 0; i < 55; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i)
                nCr[i][j] = 1;
            else
                nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
        }
    }

    return 0;
}