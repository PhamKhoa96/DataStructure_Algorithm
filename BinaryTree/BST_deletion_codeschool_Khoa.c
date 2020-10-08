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

struct BstNode* FindMax(struct BstNode* temp7){
    if (temp7 == NULL)
        return temp7;
    else{
        while (temp7->rightChild != NULL)
            temp7 = temp7->rightChild;
        return temp7;
    }
}


//Cách của mình, sai phần đầu, giống phần else so với bản gốc
struct BstNode* Delete(struct BstNode* temp3, int x){
    struct BstNode* temp4;
    temp4 = Search(temp3, x);

    if (temp4 == NULL){
        return temp3;
    }
    else{
        //Case 1: no child (leaf node)
        if (temp4->leftChild == NULL && temp4->rightChild == NULL){
            free(temp4);
            temp4 = NULL;
        }
        //Case 2: 1 child
        else if (temp4->leftChild != NULL && temp4->rightChild == NULL){
            struct BstNode* temp5 = temp4;
            temp4 = temp4->leftChild;
            free(temp5);
        }
        else if (temp4->leftChild == NULL && temp4->rightChild != NULL){
            struct BstNode* temp5 = temp4;
            temp4 = temp4->rightChild;
            free(temp5);
        }
        //Case3: 2 child
        else{
            struct BstNode* temp5 = FindMax(temp4->leftChild);
            temp4->data = temp5->data;
            Delete(temp4->leftChild, temp5->data);
            free(temp5);
        }
    }
    return temp3;
}


struct BstNode* Delete_codeschool(struct BstNode* temp3, int x){
    if (temp3 == NULL){
        return temp3;
    }
    else if (x < temp3->data)                          // !!!!!!!Quan trong, không được ghi dấu "=": data <= root->data, vì trường hợp dấu bằng chính là trường hợp else đó
        temp3->leftChild = Delete_codeschool(temp3->leftChild, x);      // !!!!!Chú ý:   temp3->leftChild = Delete_codeschool(temp3->leftChild, x);    chứ không phải   temp3 = Delete_codeschool(temp3->leftChild, x);
    else if (x > temp3->data) 
        temp3->rightChild = Delete_codeschool(temp3->rightChild, x);    // !!!!!Chú ý:   temp3->rightChild = Delete_codeschool(temp3->rightChild, x);    chứ không phải   temp3 = Delete_codeschool(temp3->rightChild, x);
    else{
        //Case 1: no child (leaf node)
        if (temp3->leftChild == NULL && temp3->rightChild == NULL){
            free(temp3);
            temp3 = NULL;
        }
        //Case 2: 1 child
        else if (temp3->leftChild != NULL && temp3->rightChild == NULL){
            struct BstNode* temp5 = temp3;
            temp3 = temp3->leftChild;
            free(temp5);
        }
        else if (temp3->leftChild == NULL && temp3->rightChild != NULL){
            struct BstNode* temp5 = temp3;
            temp3 = temp3->rightChild;
            free(temp5);
        }
        //Case3: 2 child
        else{
            struct BstNode* temp5 = FindMax(temp3->leftChild);
            temp3->data = temp5->data;
            temp3->leftChild = Delete_codeschool(temp3->leftChild, temp5->data);        //// !!!!!Chú ý:   temp3->leftChild = Delete_codeschool(temp3->leftChild, temp5->data);     chứ không phải    temp3 = Delete_codeschool(temp3->leftChild, temp5->data);
            free(temp5);
        }
    }
    return temp3;
}

//bản gốc
struct BstNode* Delete_codeschool_ver2(struct BstNode *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->leftChild = Delete_codeschool_ver2(root->leftChild,data);
	else if (data > root->data) root->rightChild = Delete_codeschool_ver2(root->rightChild,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->leftChild == NULL && root->rightChild == NULL) { 
			free(root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->leftChild == NULL) {
			struct BstNode *temp = root;
			root = root->rightChild;
			free(temp);
		}
		else if(root->rightChild == NULL) {
			struct BstNode *temp = root;
			root = root->leftChild;
			free(temp);
		}
		// case 3: 2 children
		else { 
			struct BstNode *temp = FindMax(root->leftChild);
			root->data = temp->data;
			root->leftChild = Delete_codeschool_ver2(root->leftChild,temp->data);
		}
	}
	return root;
}

void InOrderTraversal(struct BstNode* temp6){
    if (temp6 == NULL)
        return;
    else{
        InOrderTraversal(temp6->leftChild);
        printf("%5d", temp6->data);
        InOrderTraversal(temp6->rightChild);
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

    if (Search(root, x) == NULL)
        printf("\nNot Founded\n");
    else
        printf("\nFounded phan tu: %d\n", Search(root, x)->data);

    printf("\nTruoc khi xoa:");
    InOrderTraversal(root);

/*
    struct BstNode* root3;
    root3 = Delete_codeschool_ver2(root, 24);
    printf("\nSau khi xoa theo cach cua codeschool_ver2:");
    InOrderTraversal(root3);
*/
/*
    struct BstNode* root2;
    root2 = Delete_codeschool(root, 24);
    printf("\nSau khi xoa theo cach cua codeschool:");
    InOrderTraversal(root2);
*/

    struct BstNode* root1;
    root1 = Delete(root, 24);
    printf("\nSau khi xoa theo cach cua minh:");
    InOrderTraversal(root1);

}