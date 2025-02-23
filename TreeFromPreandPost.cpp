#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
 Given the preorder and postorder traversals of the same tree, build the tree from it,

 Preorder - root, left, right
 Postorder - left, right, root
 construct the tree using the preorder, create hashmap containing the indices of each 
 node of the postorder traversal
 from left to mode index is the left subtree, index +1 to right is the right subtree
*/
typedef struct TreeNode{
    char node;
    struct TreeNode *left, *right;
    TreeNode(char x) : node(x), left(NULL), right(NULL){}; // constructor
}TreeNode;
TreeNode *prePostBuildHelper(vector<char> &preorder, vector<char> &postorder, int &preIdx, map<char, int> &postMap, int left, int right){
    if(preIdx >= preorder.size() || left > right) return NULL;
    TreeNode *root = new TreeNode(preorder[preIdx++]);
    if(left == right) return root;

    int idx = postMap[preorder[preIdx]];

    root->left = prePostBuildHelper(preorder, postorder, preIdx, postMap, left, idx);
    root->right = prePostBuildHelper(preorder, postorder, preIdx, postMap, idx+1, right-1);

    return root;
}
TreeNode *prePostBuild(vector<char> &preorder, vector<char> &postorder){
    map<char, int> postMap;
    for(int i = 0; i < postorder.size(); i++){
        postMap[postorder[i]] = i;
    }
    int preIdx = 0;
    return prePostBuildHelper(preorder, postorder, preIdx, postMap, 0, postorder.size()-1);
}
void inorder(TreeNode *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->node << " ";
    inorder(root->right);
}
int main(){
    vector<char> preorder = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
    vector<char> postorder = {'D', 'E', 'B', 'F', 'G', 'C', 'A'};
    TreeNode *root = prePostBuild(preorder, postorder);
    inorder(root);
    return 0;
}