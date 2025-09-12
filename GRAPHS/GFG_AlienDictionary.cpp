/*
Solution to GFG alien dictionary
Algorithm
- map characters to numbers
- map numbers to characters
- construct a directed graph using the given lexicographically sorted array, (note : if it isnt lexicographically sorted, return "" (impossible to get an answer))
- If the entire graph can be sorted topologically, that is the answer
*/

#include <bits/stdc++.h>

using namespace std;

// main function
string findOrder(vector<string> &words){
    // map chars to node numbers and vice versa
    unordered_map<char, int> charToNode;
    unordered_map<int, char> nodeToChar;
    int node = 0;
    for(string str : words){
        for(char c : str){
            if(!charToNode.count(c)){
                charToNode[c] = node;
                nodeToChar[node++] = c;
            }
        }
    }

    // construct the directed graph and apply Kahn's algorithm

    int V = node;
    vector<vector<int>> G(V);
    vector<int> indegree(V, 0);

    for(int i = 1; i < words.size(); i++){
        int j = 0;
        int size = min(words[i].length(), words[i - 1].length());

        while(j < size && words[i][j] == words[i - 1][j])
            j++;
        
        // if the order is not lexicographically sorted, return ""
        if(j == size && words[i - 1].length() > words[i].length())
            return "";
    
        // if no common characters, no conclusion can be derived
        if(j == size)
            continue;
        else{
            G[charToNode[words[i - 1][j]]].push_back(charToNode[words[i][j]]);
            indegree[charToNode[words[i][j]]]++;
        }
    }

    // find the disconnected nodes and push them to the queue for Kahn's algo
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(!indegree[i])
            q.push(i);
    }

    // perform bfs and built result
    string result = "";
    while(!q.empty()){
        int u = q.front();
        result += nodeToChar[u];
        q.pop();

        for(int v : G[u]){
            indegree[v]--;
            if(!indegree[v])
                q.push(v);
        }
    }

    return result.length() == nodeToChar.size() ? result : "";
}
int main(){
    return 0;
}