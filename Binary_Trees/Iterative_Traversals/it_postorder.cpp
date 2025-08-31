#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        *left = *right = NULL;
    }
};
// 2 stack solution
vector<int> iterative_postorder(TreeNode *root){
    vector<int> result;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
        if(st2.top()->left != NULL)
            st1.push(st2.top()->left);
        if(st2.top()->right != NULL)
            st1.push(st2.top()->right);
    }
    while(!st2.empty()){
        result.push_back(st2.top()->val);
        st2.pop();
    }

    return result;
}
//1 stack solution : not expected but what i can do
vector<int> iterative_onest(TreeNode *root){
    vector<int> result;
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty()){
        TreeNode *root = st.top();
        result.push_back(root->val);
        if(root->left)
            st.push(root->left);
        if(root->right)
            st.push(root->right);
    }
    reverse(result.begin(), result.end());
    return result;
}
int main(){
    return 0;
}