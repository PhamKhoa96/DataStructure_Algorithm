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

bool Search(struct BstNode* temp2, int searched_data){
    if (temp2 == NULL){
        return false;
    }
    else if(temp2->data == searched_data){
        return true;
    }
    else if (searched_data <= temp2->data){
        Search(temp2->leftChild, searched_data);
    }
    else{
        Search(temp2->rightChild, searched_data);
    }
}

int findMin_Recursive(struct BstNode* temp3){
    if (temp3 == NULL)
        return -1;
    else if (temp3->leftChild == NULL)
        return temp3->data;
    else                                    //nghĩa là : else if (temp3->leftChild->data <= temp3->data)
        return findMin_Recursive(temp3->leftChild);
}

int findMax_Recursive(struct BstNode* temp3){
    if (temp3 == NULL)
        return -1;
    else if (temp3->rightChild == NULL)
        return temp3->data;
    else                                    //nghĩa là : else if (temp3->rightChild->data > temp3->data)
        return findMax_Recursive(temp3->rightChild);
}

int findMin_Iterative(struct BstNode* temp4){
    if (temp4 == NULL)
        return -1;
    else{
        while (temp4->leftChild != NULL)
                temp4 = temp4->leftChild;
        return temp4->data;
    }
}

int findMax_Iterative(struct BstNode* temp4){
    if (temp4 == NULL)
        return -1;
    else{
        while (temp4->rightChild != NULL)
                temp4 = temp4->rightChild;
        return temp4->data;
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

    printf("\nGia tri nho nhat (tim bang Recursion) la: %d\n", findMin_Recursive(root));

    printf("\nGia tri lon nhat (tim bang Recursion) la: %d\n", findMax_Recursive(root));

    printf("\nGia tri nho nhat (tim bang Iterative) la: %d\n", findMin_Iterative(root));

    printf("\nGia tri lon nhat (tim bang Iterative) la: %d\n", findMax_Iterative(root));

}