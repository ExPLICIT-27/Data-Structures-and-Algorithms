/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree
*/

#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};
vector<vector<int>> vorder(TreeNode *root){
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode*, pair<int, int>>> q;

    q.push({root, {0, 0}});
    while(!q.empty()){
        auto curr_node = q.front();
        q.pop();
        int x = curr_node.second.first, y = curr_node.second.second;
        mp[x][y].insert(curr_node.first->val);

        if(curr_node.first->left)
            q.push({curr_node.first->left, {x - 1, y + 1}});
        if(curr_node.first->right)
            q.push({curr_node.first->right,{x + 1, y + 1}});
    }

    vector<vector<int>> result;
    for(auto col : mp){
        vector<int> temp;
        for(auto row : col.second)
            temp.insert(temp.end(), row.second.begin(), row.second.end());
        result.push_back(temp);
    }
    return result;
}
int main(){
    return 0;
}