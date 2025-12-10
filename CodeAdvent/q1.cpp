#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int main(){

    ifstream file("test.txt");

    if(!file.is_open()){
        cout << "Failure to open file";
        return 1;
    }


    string line;
    int curr = 50;
    long long ans = 0;
    while(getline(file, line)){
        char dir = line[0];
        int cnt = stoi(line.substr(1));
        if(dir == 'L'){
            int dist = (curr == 0)? 100 : curr;

            if(cnt >= dist){
                ans++;
                ans += (cnt - dist)/100;
            }
            curr = ((curr - cnt)%100 + 100)%100;
            
        }
        else{
            int dist = 100 - curr;
            if(cnt >= dist){
                ans++;
                ans += (cnt - dist)/100;
            }
            
            curr = (curr + cnt)%100;
        
        }
        
    }
    cout << "mine : " << ans << endl;


    return 0;
}