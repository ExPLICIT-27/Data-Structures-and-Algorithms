#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
}node;

node *invertTree(node *root){
    if(root){
        node *left = invertTree(root->left);
        node *right = invertTree(root->right);

        root->left = right;
        root->right = left;
    }
    return root;
}