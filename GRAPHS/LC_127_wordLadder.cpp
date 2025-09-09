
#include <bits/stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // for faster checking
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if(!wordSet.count(endWord))
        return 0;

    // bfs setup
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    wordSet.erase(beginWord); // using wordset itself as visited arr
    
    // perform bfs
    while(!q.empty()){
        auto [word, dist] = q.front();
        q.pop();
        for(int i = 0; i < word.length(); i++){
            char original = word[i];
            for(int j = 0; j < 26; j++){
                char replace = 'a' + j;
                if(replace == original)
                    continue;
                word[i] = replace;

                if(word == endWord)
                    return dist + 1;
                if(wordSet.count(word)){
                    q.push({word, dist + 1});
                    wordSet.erase(word);
                }
            }
            word[i] = original;
        }
    }

    return 0;
}
int main(){
    return 0;
}