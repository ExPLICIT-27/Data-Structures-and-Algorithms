#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/*
        LOGIC :
        consider the n length string represented by n bit binary number,
        if we consider all possible binary numbers of length n, and add the set bit
        to the subsequence, we get the result.
        Eg: "ABC"
        000 - ""
        001 - "C"
        010 - "B"
        011 - "BC"
        100 - "A"
        101 - "AC"
        110 - "AB"
        111 - "ABC"

        to obtain this, for n length str, 
        2^n subsequences,
        iterate from i 0 to 2^n-1
        iterate from j 0 to n
        calc 2^j (1 << j == 1*2^j)
        i is the bin number, 
        j loop iterates over each bit of i and checks whether it is set
        if set, then  i & (1 << j) != 0


*/
void genSubSeq(string &str){
    int n = pow(2, str.length());

    for(int i = 0; i < n; i++){
        string Subseq = "";
        for(int j = 0; j < str.length(); j++){
            if(i & (1 << j)){
                Subseq += str[j];
            }
        }
        cout << Subseq << endl;
    }
}
int main(){
    string s = "ABC";
    genSubSeq(s);
    return 0;
}