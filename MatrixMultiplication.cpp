#include <iostream>
#include <vector>

using namespace std;
// pad to power of two, remove padding
vector<vector<int>> AddMatrices(const vector <vector<int>>&, const vector <vector<int>>&);
vector<vector<int>> MultiplyDivideAndConquer(vector <vector<int>> &, vector <vector<int>> &);
int main(){
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<vector<int>> B = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    vector<vector<int>> C = MultiplyDivideAndConquer(A, B);
    for(int i = 0; i < C.size(); i++){
        for(int j = 0; j < C.size(); j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<vector<int>> AddMatrices(const vector <vector<int>> &A, const vector <vector<int>> &B){
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
vector<vector<int>> MultiplyDivideAndConquer(vector <vector<int>> &A, vector <vector<int>> &B){
    int n = A.size();
    if(n == 1){
        return vector<vector<int>>{{A[0][0]*B[0][0]}};
    }

    int mid = n/2;

    vector<vector<int>> A11(mid, vector<int>(mid, 0)), A12(mid, vector<int>(mid, 0)),A21(mid, vector<int>(mid, 0)), A22(mid, vector<int>(mid, 0));
    vector<vector<int>> B11(mid, vector<int>(mid, 0)), B12(mid, vector<int>(mid, 0)),B21(mid, vector<int>(mid, 0)), B22(mid, vector<int>(mid, 0));

    for(int i = 0; i < mid; i++){
        for(int j = 0; j < mid; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];

        }
    }
    vector<vector<int>>C11 = AddMatrices(MultiplyDivideAndConquer(A11, B11), MultiplyDivideAndConquer(A12, B21));
    vector<vector<int>>C12 = AddMatrices(MultiplyDivideAndConquer(A11, B12), MultiplyDivideAndConquer(A12, B22));
    vector<vector<int>>C21 = AddMatrices(MultiplyDivideAndConquer(A21, B11), MultiplyDivideAndConquer(A22, B21));
    vector<vector<int>>C22 = AddMatrices(MultiplyDivideAndConquer(A21, B12), MultiplyDivideAndConquer(A22, B22));

    vector<vector<int>> C(n, vector<int>(n, 0));
    for(int i = 0; i < mid; i++){
        for(int j = 0; j < mid; j++){
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    return C;
}