/*
Given a Binary Tree, find the bottom view of the tree
        1
    2       3
4       5       6
bottom view = 4, 5, 6
using the same concept as vertical traversal, except we store only one node per
column
just remove the condition for checking map from topview, you have bottom view
*/
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

vector<int> bottomTreeView(TreeNode *root){
    if(!root)
        return;
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        mp[curr.second] = curr.first->val;
        if(curr.first->left)
            q.push({curr.first->left, curr.second - 1});
        if(curr.first->right)
            q.push({curr.first->right, curr.second + 1});
    }
    vector<int> result;
    for(auto pair : mp)
        result.push_back(pair.second);
    return result;
}
int main(){
    return 0;
}