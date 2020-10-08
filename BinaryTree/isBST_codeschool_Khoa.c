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

// Check xem có phải BST không

// Cách 1: so sánh tất cả các node ở cây con bên trái có nhỏ hơn hoặc bằng node đang xét không 
// và tất cả các node ở cây con bên phải có lớn hơn node đang xét không
// time-complexity: O(n^2)
bool isLesser(struct BstNode* temp4, int data){
    if (temp4 == NULL)
        return true;
    if (temp4->data <= data
        && isLesser(temp4->leftChild, data)         //3 ĐK này có thể thay thế bằng  FindMin(temp4) <= data
        && isLesser(temp4->rightChild, data))
        return true;
    else
        return false;
}

bool isGreater(struct BstNode* temp4, int data){
    if (temp4 == NULL)
        return true;
    if (temp4->data > data
        && isGreater(temp4->leftChild, data)        //3 ĐK này có thể thay thế bằng  FindMax(temp4) > data 
        && isGreater(temp4->rightChild, data))    
        return true;
    else
        return false;
}

bool isBST(struct BstNode* temp3){
    if (temp3 == NULL)
        return true;
    if (isLesser(temp3->leftChild, temp3->data) &&                           
        isGreater(temp3->rightChild, temp3->data)){                            
            return (isBST(temp3->leftChild) && isBST(temp3->rightChild));
        }
    else
        return false;
}

// Cách 2: define range cho từng node và xem node đó có nằm trong range đó không
// time-complexity: O(n)
bool isBST_2(struct BstNode* temp5, int minValue, int maxValue){
    if (temp5 == NULL)
        return true;
    if (temp5->data >= minValue 
        && temp5->data < maxValue
        && isBST_2(temp5->leftChild, minValue, temp5->data)
        && isBST_2(temp5->rightChild, temp5->data, maxValue))
        return true;
    else
        return false;
}

//Cách 3: Duyệt cây theo in-Oder-Traversal và xem giá trị các node có là 1 dãy tăng dần không

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

    // Cách 1:
    if (isBST(root) == true)
        printf("\nBST\n");
    else
        printf("\nNot BST\n");

    //Cách 2:
    if (isBST_2(root, INT_MIN, INT_MAX) == true)
        printf("\nBST\n");
    else
        printf("\nNot BST\n");

    //Cách 3:
}