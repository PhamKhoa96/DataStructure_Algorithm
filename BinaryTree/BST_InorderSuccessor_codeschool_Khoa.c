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

struct BstNode* FindMin(struct BstNode* temp7){
    if (temp7 == NULL)
        return NULL;
    else{
        while (temp7->leftChild != NULL)
            temp7 = temp7->leftChild;
        return temp7;
    }
}

void InOrder_traserval(struct BstNode* temp6){
    if (temp6 == NULL)
        return;
    else{
        InOrder_traserval(temp6->leftChild);
        printf("%5d",temp6->data);
        InOrder_traserval(temp6->rightChild);
    }
}

struct BstNode* InOrderSuccessor(struct BstNode* temp3, int x){
    struct BstNode* temp4 = Search(temp3, x);

    if (temp4->rightChild != NULL)
        return FindMin(temp4->rightChild);
    else{
        struct BstNode* temp5 = root;
        struct BstNode* ancestor;
        while (temp4 != temp5){
            if (temp5->data > temp4->data){
                ancestor = temp5;
                temp5 = temp5->leftChild;
            }
            else
                temp5 = temp5->rightChild;
        }
        return ancestor;
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

    if (Search(root, x) != NULL)
        printf("\nFounded\n");
    else
        printf("\nNot Founded\n");

    printf("\ninoder_traversal: "); InOrder_traserval(root);

    int value = 35;
    printf("\nsuccessor cua %d la: %d", value, InOrderSuccessor(root, value)->data);
}