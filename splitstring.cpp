#include <iostream>
#include <vector>
using namespace std;
vector <string> splitString(string sentence){
    vector <string> output;
    string temp = "";
    for(int i = 0; i <= sentence.length(); i++){
        if(i == sentence.length() || sentence[i] == ' '){
            if(!temp.empty()){
                output.push_back(temp);
                temp = "";
            }
        }
        else{
            temp += sentence[i];
        }
    }
    return output;
}
int main(){
    string sentence = "I am Nandu Mahesh";
    vector <string> split = splitString(sentence);
    for(auto i : split){
        cout << i << "\n";
    }
    return 0;
}