#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

void Add(Node** root, int data);
void Search(Node* root, int data);
void Delete(Node** root, int data);
Node* CreateNode(int data);

int main(void){

    Node* root = NULL;

    Add(&root, 5);


}

Node* CreateNode(int data){
    Node* newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


void Add(Node** root, int data){

    if((*root) == NULL){
        *root = CreateNode(data);
    }
    else if( (*root)->data <= data){
        Add(&((*root)->left), data);
    }
    else if( (*root)->data >= data){
        Add(&((*root)->right), data);
    }

}


void Search(Node * root, int data){

    if(root == NULL){
        printf("Not found.\n");
    }
    else if(root->data == data){
        printf("Found.\n");
    }
    else if(root->data <= data){
        Search(root->right, data);
    }
    else if(root->data >= data){
        Search(root->left, data);
    }

}