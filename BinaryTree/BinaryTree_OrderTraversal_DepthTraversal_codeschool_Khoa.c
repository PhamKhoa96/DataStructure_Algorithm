#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode{
    char data;
    struct BstNode* leftChild;
    struct BstNode* rightChild;
};

struct BstNode* root;

struct BstNode* CreateNewNode(char x){
    struct BstNode* temp1 = (struct BstNode*)malloc(sizeof(struct BstNode));
    temp1->data = x;
    temp1->leftChild = NULL;
    temp1->rightChild = NULL;
    return temp1;
}

struct BstNode* Insert(struct BstNode* temp, char inserted_data){
    if (temp == NULL){
        temp = CreateNewNode(inserted_data);
    }
    else if (inserted_data <= temp->data){
        temp->leftChild = Insert(temp->leftChild, inserted_data);
    }
    else{
        temp->rightChild = Insert(temp->rightChild, inserted_data);
    }
    return temp;
}


void PreOrder_Traversal(struct BstNode* temp7){
    if (temp7 == NULL)
        return;
    else{
        printf("%5c", temp7->data);
        PreOrder_Traversal(temp7->leftChild);
        PreOrder_Traversal(temp7->rightChild);
    }
}

void InOrder_Traversal(struct BstNode* temp8){
    if (temp8 == NULL)
        return;
    else{
        InOrder_Traversal(temp8->leftChild);
        printf("%5c", temp8->data);
        InOrder_Traversal(temp8->rightChild);
    }
}

void PostOrder_Traversal(struct BstNode* temp9){
    if (temp9 == NULL)
        return;
    else{
        PostOrder_Traversal(temp9->leftChild);
        PostOrder_Traversal(temp9->rightChild);
        printf("%5c", temp9->data);
    }
}

void main(){
    root = NULL;
    /*
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');

    PreOrder_Traversal(root);
    printf("\n");
    InOrder_Traversal(root);
    printf("\n");
    PostOrder_Traversal(root);
}