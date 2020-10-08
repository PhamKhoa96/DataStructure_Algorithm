#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode{
    int data;
    struct BstNode* leftChild;
    struct BstNode* rightChild;
};

struct BstNode* root;

struct BstNode* CreateNewNode(int x){
    struct BstNode* temp1 = (struct BstNode*)malloc(sizeof(struct BstNode));
    temp1->data = x;
    temp1->leftChild = NULL;
    temp1->rightChild = NULL;
    return temp1;
}

struct BstNode* Insert(struct BstNode* temp, int inserted_data){
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

struct BstNode* Search(struct BstNode* temp2, int searched_data){
    if (temp2 == NULL){
        return temp2;
    }
    else if(temp2->data == searched_data){
        return temp2;
    }
    else if (searched_data < temp2->data){
        return Search(temp2->leftChild, searched_data);
    }
    else{
        return Search(temp2->rightChild, searched_data);
    }
}

struct BstNode* InOrderSuccessor(struct BstNode* temp3, int x){
    struct BstNode* temp4 = Search(temp3, x);

    if (temp4->rightChild != NULL)
        return FindMin(temp4->rightChild);
    else{
        struct Node* temp5 
    }

}

void main(){
    root = NULL;

    root = Insert(root, 35);root = Insert(root, 23);root = Insert(root, 56);root = Insert(root, 33);
    root = Insert(root, 3);root = Insert(root, 2);root = Insert(root, 24);root = Insert(root, 93);
    root = Insert(root, 21);root = Insert(root, 13);root = Insert(root, 18);root = Insert(root, 7);

    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);

    if (Search(root, x) == true)
        printf("\nFounded\n");
    else
        printf("\nNot Founded\n");
}