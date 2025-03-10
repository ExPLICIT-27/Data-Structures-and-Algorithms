/*
Given a string print out the longest palindromic subsequence
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// naive brute force : logic
// start two pointers ; one from the front and one from the back, if the value of the string at the current front idx
// is equal to the value of the string at the last idx, then add it to the result and move on,
// else keep front, move back ; keep back move front, take the string of maximum length obtained from 
// both the cases
string NaiveBruteforce(int i, int j, string &inpStr){
    string resStr = "";
    if(i > j){
        return resStr;
    }
    if(i == j){
        return resStr + inpStr[i];
    }
    if(inpStr[i] == inpStr[j]){
        return inpStr[i] + NaiveBruteforce(i + 1, j - 1, inpStr) + inpStr[j];
    }
    else{
        string moveFront = NaiveBruteforce(i + 1, j, inpStr);
        string moveBack = NaiveBruteforce(i, j - 1, inpStr);
        return (moveFront.length() > moveBack.length())? moveFront : moveBack;
    }
}
int main(){
    string str = "characterisation";
    cout << NaiveBruteforce(0, str.length() - 1, str) << endl;
    return 0;
}