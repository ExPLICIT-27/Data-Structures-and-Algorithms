#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
tree *createnode(int);
tree *insert(tree*, int);
tree *search(tree*, int);
int main(){
    int nodes;
    printf("\nEnter number of nodes: ");
    scanf(" %d", &nodes);
    tree *root = NULL;
    while(nodes--){
        int temp;
        printf("\nEnter value: ");
        scanf(" %d", &temp);
        root = insert(root, temp);
    }
    int target;
    printf("\nEnter target: ");
    scanf(" %d", &target);
    printf((search(root, target) != NULL)? "Found" : "Not found");
    return 0;
}
tree *search(tree *root, int target){
    if(root == NULL || root->data == target){
        return root;
    }
    if(root->data < target){
        return search(root->right, target);
    }
    return search(root->left, target);
}
tree *insert(tree *root, int val){
    if(root == NULL){
        return createnode(val);
    }
    if(root->data == val){
        return root;
    }
    else if(root->data > val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}
tree *createnode(int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}