#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void InsertAtTheNthPosition(int x, int position){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;

    if (position == 1){
        temp->next = head;
        head = temp;
    }
    else{
        struct Node* temp1;
        temp1 = head;
        for(int i = 0; i < position - 2; i++){
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

struct Node* DeleteAtTheNthPosition(int position_delete){
    struct Node* temp3 = (struct Node*) malloc(sizeof(struct Node)); // lưu giá trị bị xóa
    
    struct Node* temp4 = (struct Node*) malloc(sizeof(struct Node));;
    temp4 = head;

    if (position_delete == 1){
        head = temp4->next;
        return temp4;
    }
    else{
        for(int i = 0; i < position_delete -2; i++)
            temp4 = temp4->next;
        temp3 = temp4->next;
        temp4->next = temp3->next;
        return temp3;
    }
}


void Print(){
    printf("\nGia tri cac phan tu trong list la: ");
    
    struct Node* temp2;
    temp2 = head;
    while(temp2 != NULL){
        printf("%5d", temp2->data);
        temp2 = temp2->next;
    }
    
}

int main(){
    head = NULL;
    
    int n, i, x, position;
    printf("How many number will be inserted to linkedList?\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("\nPlease insert the %dth data:\n", i+1);
        scanf("%d", &x);
        printf("\nPlease insert the position of %dth data:\n", i+1);
        scanf("%d", &position);
        InsertAtTheNthPosition(x, position);
        Print();
    }

    int n_delete, position_delete;
    printf("\nHow many number will be deleted in linkedList?\n");
    scanf("%d", &n_delete);

    for (i = 0; i < n_delete; i++){
        printf("\nPlease insert the position of %dth data:\n", i+1);
        scanf("%d", &position_delete);
        struct Node* k = DeleteAtTheNthPosition(position_delete);
        printf("Gia tri bi xoa tai vi tri %dth la: %d", position_delete, k->data);
        Print();
    }

    return 0;
}