#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
int max(int, int);
int MaxSubtreeSum(tree *);
int maxsumutil(tree *, int);
tree *levelorderbuild(tree*, int*, int, int);
tree *createnode(int);
int main(){
    int level[] = {1, 2, 3, 4, 5, 6, 7};
    int level2[] = {1, -2, 3, 4, 5, -6, 2};
    tree *root = levelorderbuild(root, level, 0, 7);
    tree *root1 = levelorderbuild(root1, level2, 0, 7);
    printf("%d\n", MaxSubtreeSum(root));
    printf("%d", MaxSubtreeSum(root1));
    return 0;
}
tree *createnode(int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
tree *levelorderbuild(tree *root, int *level, int i, int size){
    if(i < size){
        root = createnode(level[i]);
        root->left = levelorderbuild(root, level, 2*i+1, size);
        root->right = levelorderbuild(root, level, 2*i+2, size);
        return root;
    }
    return NULL;
}
int MaxSubtreeSum(tree *root){
    if(root == NULL){
        return 0;
    }
    int ans = INT_MIN;
    return maxsumutil(root, ans);
}
int maxsumutil(tree *root, int ans){
    if(root == NULL){
        return 0;
    }
    int currsum = root->data + maxsumutil(root->left, ans) + maxsumutil(root->right, ans);
    return max(currsum, ans);
}
int max(int a, int b){
    return (a > b)? a : b;
}