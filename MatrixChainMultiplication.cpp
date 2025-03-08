/*
Given a set of matrix dimensions (eg {10, 20, 30, 40, 50})
Use the brute force approach and generate all possible parenthesizationsa and compute the 
cost of multiplication for each parenthesization
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct ParaRes{
    string para;
    int cost;
};

vector<ParaRes> mcmBruteForce(int i, int j, vector<int> &dims, vector<string> &matNames){
    vector<ParaRes> result;

    if(i == j){
        result.push_back({matNames[i-1], 0});
        return result;
    }

    for(int k = i; k < j; k++){
        vector<ParaRes> leftRes = mcmBruteForce(i, k, dims, matNames);
        vector<ParaRes> rightRes = mcmBruteForce(k + 1, j, dims, matNames);

        for(const auto &left : leftRes){
            for(const auto &right : rightRes){
                int cost = left.cost + right.cost + dims[i-1]*dims[k]*dims[j];
                string para = "(" + left.para + "*" + right.para + ")";
                result.push_back({para, cost});
            }
        }
    }
    return result;
}

// Bottom up Dynamic Programming approach
string constructPara(vector<string> &mat, int i, int j, vector<vector<int>> &s){
    if(i == j){
        return mat[i-1];
    }
    return "(" + constructPara(mat, i, s[i][j], s) + "*" + constructPara(mat, s[i][j] + 1, j, s) + ")";
}
pair<int, string> mcmTabulated(vector<int> &dims, vector<string> &mat){
    int n = mat.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n - l + 1; i++){
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k + 1][j] + dims[i-1]*dims[k]*dims[j];
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    string optpara = constructPara(mat, 1, n, s);
    return {dp[1][n], optpara};
}

int main(){
    int n;
    cout << "Enter the number of dimensions: ";
    cin >> n;
    cout << endl;

    vector<int> dimensions(n);
    for(int i = 0; i < n; i++){
        cin >> dimensions[i];
    }

    vector<string> matNames(n-1); // of the order A1, A2, A3 etc
    for(int i = 0; i < n-1; i++){
        matNames[i] = "A" + to_string(i + 1);
    }

    vector<ParaRes> result = mcmBruteForce(1, n-1, dimensions, matNames);

    cout << "Number of possible paranthesizations : " << result.size() << endl;
    for(const auto &res : result){
        cout << res.para << " -> " << res.cost << endl;
    }

    auto [optcost, optpara] = mcmTabulated(dimensions, matNames);
    cout << "Optimal cost using bottom up : " << optcost << endl;
    cout << "Optimal paranthesization : " << optpara << endl;
    return 0;
}