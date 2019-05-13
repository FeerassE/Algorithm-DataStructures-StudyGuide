

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>



typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
} BstNode;


void Insert(BstNode**, int);
BstNode * GetNewNode(int);
bool Search(BstNode* root, int data);

int main(void){
    BstNode* root = NULL;
    Insert(&root, 15);
    Insert(&root, 10);
    Insert(&root, 20);
    Insert(&root, 25);
    Insert(&root, 5);
    Insert(&root, 11);

    Search(root, 25);

    return 0;
}

BstNode* GetNewNode(int data){
    printf("GetNewNode: I am here.\n");
    BstNode* newNode = malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL; 
    return newNode;
}

void Insert(BstNode** root, int data){
    printf("Insert: I am here.\n");
    if(*root == NULL){
        printf("Insert: root is null, getting new node\n");
        *root = GetNewNode(data);
    }
    else if (data <= (*root)->data){
        Insert( &((*root)->left), data);
    }
    else if (data >= (*root)->data){
        Insert( &((*root)->right), data);
    }
}


bool Search(BstNode* root, int data) {
    printf("Search: I am here.\n");
    if(root == NULL) return false;
    else if(root->data == data){
        printf("found: %d\n", data);
        return true;
    } 
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}