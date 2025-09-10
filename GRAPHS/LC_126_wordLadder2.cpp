
/*
from word ladder 1, generate the wordladder
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> res;
unordered_map<string, int> levelMap;
void dfs(string currWord, vector<string> &wordList, string endWord){
    if(currWord == endWord){
        res.push_back(wordList);
        return;
    }
    int currentLevel = levelMap[currWord];
    for(int i = 0; i < currWord.length(); i++){
        char original = currWord[i];
        for(char c = 'a'; c <= 'z'; c++){
            if(c == original)
                continue;
            currWord[i] = c;
            if(levelMap.count(currWord) && levelMap[currWord] + 1 == currentLevel){
                wordList.push_back(currWord);
                dfs(currWord, wordList, endWord);
                wordList.pop_back();
            }
        }
        currWord[i] = original;
    }
}
vector<vector<string>> findLadders(vector<string> &wordList, string beginWord, string endWord){
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if(!wordSet.count(endWord))
        return {};

    queue<string> q;
    q.push(beginWord);
    wordSet.erase(beginWord);
    levelMap[beginWord] = 0;

    while(!q.empty()){
        string word = q.front();
        q.pop();
        int currentLevel = levelMap[word];

        for(int i = 0; i < word.length(); i++){

            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++){

                if(c == original)
                    continue;
                word[i] = c;
                if(wordSet.count(word)){
                    wordSet.erase(word);
                    levelMap[word] = currentLevel + 1;
                    q.push(word);
                }
            }
            word[i] = original;
        }
    }

    if(!levelMap.count(endWord))
        return {};
    vector<string> temp;
    temp.push_back(endWord);
    dfs(endWord, temp, beginWord);

    for(auto &vec : res)
        reverse(vec.begin(), vec.end());
    return res;
    
}
int main(){
    return 0;
}