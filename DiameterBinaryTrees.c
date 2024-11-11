#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left, *right;
};
struct TreeInfo{
    int height, diameter;
};
struct TreeInfo *makeInfo(int, int);
int max(int, int);
int diameter(struct Node*);
struct TreeInfo *diameterOptimised(struct Node *);
struct Node *createNode(int);
struct Node *createTree(int*, int);
struct Node *createTreeHelper(int*, int*, int);
int HeightNodes(struct Node*);
int main(){
    int preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int size = sizeof(preorder)/sizeof(preorder[0]);
    struct Node *root = createTree(preorder, size);
    printf("Diamter of Tree: %d", diameter(root));
    struct TreeInfo *info = diameterOptimised(root);
    printf("\nOptimised result: %d", info->diameter);
    return 0;
}
struct TreeInfo *makeInfo(int height, int diameter){
    struct TreeInfo *info = (struct TreeInfo*)malloc(sizeof(struct TreeInfo));
    info->diameter = diameter;
    info->height = height;
    return info;
}
int max(int a, int b){
    return (a > b)? a : b;
}
// o(n^2)
int diameter(struct Node *root){
    if(root == NULL){
        return 0;
    }
    int diam1 = diameter(root->left);
    int diam2 = diameter(root->right);
    int diam3 = 1 + HeightNodes(root->left) + HeightNodes(root->right);
    return max(diam3, max(diam2, diam1));
}
// O(n)
struct TreeInfo *diameterOptimised(struct Node *root){
    if(root == 0){
        return makeInfo(0, 0);
    }
    struct TreeInfo *left = diameterOptimised(root->left);
    struct TreeInfo *right = diameterOptimised(root->right);
    int height = max(left->height, right->height) + 1;

    int diam1 = left->diameter;
    int diam2 = right->diameter;
    int diam3 = 1 + left->height + right->height;

    struct TreeInfo *result = makeInfo(height, max(diam3, max(diam1, diam2)));
    return result;
}
int HeightNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }
    int left = HeightNodes(root->left);
    int right = HeightNodes(root->right);
    int max = (left > right)? left : right;
    return (1 + max);
}
struct Node *createTreeHelper(int *input, int *index, int size){
    if(*index >= size || input[*index] == -1){
        (*index)++;
        return NULL;
    }
    struct Node *root = createNode(input[*index]);
    (*index)++;
    root->left = createTreeHelper(input, index, size);
    root->right = createTreeHelper(input, index, size);
    return root;
}
struct Node *createTree(int *input, int size){
    int index = 0;
    return createTreeHelper(input, &index, size);
}
struct Node *createNode(int val){
    if(val == -1){
        return NULL;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL, newNode->right = NULL;
    return newNode;
}