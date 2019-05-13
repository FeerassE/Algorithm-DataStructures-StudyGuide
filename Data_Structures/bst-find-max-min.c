

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;


Node* CreateNode(Node* root, int data);
Node* Insert(Node* root, int data);
int FindMin(Node* root);

int main(void){
    Node* root = NULL;

    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 4);
    root = Insert(root, 7);
    root = Insert(root, 15);
    root = Insert(root, 12);
}

Node* Insert(Node* root, int data){
    if(root == NULL){
        return CreateNode(root, data);
    }
    else if(data <= root->data){
        return Insert(root->left, data);
    }
    else {
        return Insert(root->right, data);
    }
}

Node* CreateNode(Node* root, int data){
        Node * newNode = malloc(sizeof(Node));

        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
}

int FindMin(Node* root) {
    if(root == NULL){
        printf("Error: no min found.\n");
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    else{
        return FindMin(root->left);
   }
}


int FindMax(Node* root){
    if(root == NULL){
        printf("Error: tree empty.\n");
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    else{
        return FindMax(root->right);
    }
}