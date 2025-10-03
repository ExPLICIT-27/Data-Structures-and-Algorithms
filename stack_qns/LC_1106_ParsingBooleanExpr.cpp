/*
use a stack and simulate
*/
#include <bits/stdc++.h>

using namespace std;


bool parseBoolExpr(string expression) {
    string stk = "";
    unordered_set<char> st = {'|', '&', '!', 't', 'f'};
    unordered_set<char> ops  = {'|', '&', '!'};
    for(char c : expression){
        if(st.count(c))// only required exprs are ones in 'st'
            stk += c;
        else if(c == ',' || c == '(') // ignore them, they dont make any difference
            continue;
        else{
            bool hast = false, hasf = false;// has a false and has a true (for immediate checking of | and &)
            while(!stk.empty() && !ops.count(stk.back())){ // pop till you encounter an operator
                if(stk.back() == 't')
                    hast = true;
                if(stk.back() == 'f')
                    hasf = true;
                stk.pop_back();
            }
            char op = stk.back();
            stk.pop_back();
            if(op == '!'){
                if(hast)
                    stk += 'f';
                else
                    stk += 't';
            }
            else if(op == '&'){
                if(hasf)
                    stk += 'f';
                else
                    stk += 't';
            }
            else{
                if(hast)
                    stk += 't';
                else
                    stk += 'f';
            }
        }
    }
    return stk.back() == 't';
}
int main(){
    return 0;
}