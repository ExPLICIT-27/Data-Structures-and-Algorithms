#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node *createNode(int);
struct Node *buildTree(int*, int);
struct Node *buildTreeHelper(int*, int*, int);
void preorder(struct Node*); // root, left, right
void inorder(struct Node*); // left , root, right
void postorder(struct Node*); // left, right, root
void levelOrder(struct Node*); // level wise using queues;
int main(){
    int Preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int size = sizeof(Preorder)/sizeof(Preorder[0]);
    struct Node *root = buildTree(Preorder, size);
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelOrder(root);
    return 0;
}
void levelOrder(struct Node *root){
    struct Node *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    queue[rear++] = NULL;
    do{
        struct Node *currnode = queue[front++];
        if(currnode == NULL){
            printf("\n");
            if(front == rear){
                break;
            }
            else{
                queue[rear++] = NULL;
            }
        }
        else{
            printf("%d ", currnode->data);
            if(currnode->left != NULL){
                queue[rear++] = currnode->left;
                
            }
            if(currnode->right != NULL){
                queue[rear++] = currnode->right;
            }
        }
    }while(front != rear);
}
void postorder(struct Node *root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void inorder(struct Node *root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node *root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
struct Node *buildTreeHelper(int preorder[], int *index, int size){
    if(*index >= size || preorder[*index] == -1){
        (*index)++;
        return NULL;
    }
    struct Node *root = createNode(preorder[*index]);
    (*index)++;
    root->left = buildTreeHelper(preorder, index, size);
    root->right = buildTreeHelper(preorder, index, size);

    return root;
}
struct Node *buildTree(int preorder[], int size){
    int index = 0;
    return buildTreeHelper(preorder, &index, size);
}
struct Node *createNode(int value){
    if(value == -1){
        return NULL;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}