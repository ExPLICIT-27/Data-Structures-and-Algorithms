// 1190. Reverse Substrings Between Each Pair of Parentheses
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

 

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
// Example 3:

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

// Constraints:

// 1 <= s.length <= 2000
// s only contains lower case English characters and parentheses.
// It is guaranteed that all parentheses are balanced.
#include <iostream>
#include <vector>
using namespace std;
// my O(n^2) solution
void change(vector <string> &arr, int start, int end){
    string temp = "";
    while(start < end){
        temp = "";
        temp += arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}
string reverseParas(string s){
    vector <string> result;
    vector <int> stack;
    for(int i = 0; i < s.length(); i++){
        string temp = "";
        temp += s[i];
        result.push_back(temp);
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            stack.push_back(i);
        }
        if(s[i] == ')'){
            int start = stack[stack.size() - 1];
            stack.pop_back();
            int end = i;
            change(result, start, i);

        }
    }
    string answer = "";
    for(int i = 0; i < result.size(); i++){
        if(result[i] != ")" && result[i] != "("){
            answer += result[i];
        }
    }
    return answer;
}
// WormHole teleportation technique : O(n) solution, it is absolutely
// brilliant : look it up on editorial leetcode
// Basically when you encounter a parentheses go to (teleport to)
// its pair and travel in the reverse direction , keep doing so 
// till you go beyond the string
string wormhole(string s){
    vector <int> pairs(s.length(), 0);
    vector <int> parentheses;
    // Forming wormhole pairs : connection between the spaces
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            parentheses.push_back(i);
        }
        if(s[i] == ')'){
            int j = parentheses[parentheses.size()-1];
            parentheses.pop_back();
            pairs[i] = j;
            pairs[j] = i;
        }
    }
    string result = "";
    int direction = 1;
    int index = 0;
    while(index < s.length()){
        if(s[index] == ')' || s[index] == '('){
            index = pairs[index];
            direction *= -1;
        }
        else{
            result += s[index];
        }
        index += direction;
    }
    return result;
}
int main(){
    string qn = "(ed(et(oc))el)";
    cout << wormhole(qn);
    return 0;
}