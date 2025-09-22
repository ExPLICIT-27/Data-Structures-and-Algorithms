#include <bits/stdc++.h>

using namespace std;

int main(){
    string add;
    cin >> add;
    string nums = "";
    for(char c : add){
        if(c != '+')
            nums += c;
    }
    sort(nums.begin(), nums.end());
    string out = "";
    for(char c : nums){
        out += to_string((c-'0')) + "+";
    }
    out.pop_back();
    cout << out;
}