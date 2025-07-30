#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
int max(int, int);
tree *createnode(int);
tree *buildTree(int*, int);
tree *buildTreeHelper(int*, int*, int);
int maxSum(tree*);
int maxsumutil(tree*, int*);
int main(){
    int pre[] = {10, 2, 20, 1, 10, -25, 3, 4};
    tree *root = buildTree(pre, 8);
    printf("Max Sum: %d", maxSum(root));
    return 0;
}
int max(int a, int b){
    return (a > b)? a : b;  
}
int maxsumutil(tree *root, int *ans){
    if(root == NULL){
        return 0;
    }
    int left = maxsumutil(root->left, ans);
    int right = maxsumutil(root->right, ans);
    int max_single = max(max(left, right) + root->data, root->data);
    int max_top = max(max_single, left+right+root->data);
    *ans = max(*ans, max_top);
    return max_single;
}
int maxSum(tree *root){
    if(root == NULL){
        return 0;
    }
    int ans = INT_MIN;
    maxsumutil(root, &ans);
    return ans;
}
tree *buildTreeHelper(int *pre, int *idx, int size){
    if(*idx >= size || pre[*idx] == -1){
        (*idx)++;
        return NULL;
    }
    tree *root = createnode(pre[*idx]);
    (*idx)++;
    root->left = buildTreeHelper(pre, idx, size);
    root->right = buildTreeHelper(pre, idx, size);
    return root;
}
tree *buildTree(int *pre, int size){
    int idx = 0;
    return buildTreeHelper(pre, &idx, size);
}
tree *createnode(int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}