#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}node;

node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int idx = -1;

node* buildTree(int nodes[]) {
    idx++;

    if(nodes[idx] == -1 ) {
        return NULL;
    }

    node* newNode = createNode(nodes[idx]);
    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);

    return newNode;
}

void preorder(node* root) {
    if(root ==  NULL) {
        return;
    }

    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) {
    if(root == NULL) {
        return;
    }
    
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}

int main() {
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root = buildTree(nodes); 
    inorder(root);

    return 0;
}