/*
width would be defined as the maximum distance between any 2 nodes at any level
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
int maxwidthOfTree(TreeNode *root){
    if(!root)
        return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int result = 0;
    while(!q.empty()){
        int midx = q.front().second;
        int size = q.size();
        int first, last;
        for(int i = 0; i < size; i++){
            int curr_idx = q.front().second - midx;
            TreeNode *node = q.front().first;
            q.pop();
            if(node->left)
                q.push({node->left, 2*curr_idx + 1});
            if(node->right)
                q.push({node->right, 2*curr_idx + 2});
            if(i == 0) first = curr_idx;
            if(i == size - 1) last = curr_idx;
        }
        result = max(result, last - first + 1);
    }
    return result;
}
int main(){
    return 0;
}