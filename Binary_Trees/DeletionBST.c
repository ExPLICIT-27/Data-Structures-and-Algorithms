#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
tree *findSucessor(tree*);
tree *deleteNode(tree*, int);
void inorder(tree*);
tree *createnode(int);
tree *insert(tree*, int);
int main(){
    int nodes[] = {10, 5, 15, 12, 18};
    tree *root = NULL;
    for(int i = 0; i < 5; i++){
        root = insert(root, nodes[i]);
    }
    root = deleteNode(root, 15);
    inorder(root);
    return 0;
}
void inorder(tree *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
tree *findSucessor(tree *root){
    root = root->right;
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}
tree *deleteNode(tree *root, int target){
    if(root == NULL){
        return root;
    }
    else if(root->data < target){
        root->right =  deleteNode(root->right, target);
    }
    else if(root->data > target){
        root->left = deleteNode(root->left, target);
    }
    else{
        if(root->left == NULL){
            tree *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            tree *temp = root->left;
            free(root);
            return temp;
        }
        tree *temp = findSucessor(root);
        root->data = temp->data;
        root->right =  deleteNode(root->right, temp->data);
    }
    return root;
}
tree *insert(tree *root, int val){
    if(root == NULL){
        return createnode(val);
    }
    if(root->data == val){
        return root;
    }
    else if(root->data < val){
        root->right = insert(root->right, val);
    }
    else{
        root->left = insert(root->left, val);
    }
    return root;
}
tree *createnode(int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}