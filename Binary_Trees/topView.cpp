/*
Given a Binary Tree, find the top view of the tree
        1
    2       3
4       5       6
top view = 4, 2, 1, 3, 6
using the same concept as vertical traversal, except we store only one node per
column
*/
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

vector<int> TopTreeView(TreeNode *root){
    if(!root)
        return {};
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto curr_node = q.front();
        q.pop();
        if(!mp.count(curr_node.second))
            mp[curr_node.second] = curr_node.first->val;
        if(curr_node.first->left)
            q.push({curr_node.first->left, curr_node.second - 1});
        if(curr_node.first->right)
            q.push({curr_node.first->right, curr_node.second + 1});
    }
    vector<int> result;
    for(auto pair : mp)
        result.push_back(pair.second);
    return result;
}
int main(){
    return 0;
}