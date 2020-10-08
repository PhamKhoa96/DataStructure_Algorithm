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

void Reverse_Iterative(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    struct Node* previous;;
    struct Node* current;
    struct Node* after;

    previous = temp;
    current = temp->next;
    after = current->next;

    current->next = previous;
    previous->next = NULL;
    while(after != NULL){
        current->next = previous;

        previous = current;
        current = after;
        after = after->next;       
    }
    current->next = previous;
    head = current;
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
    printf("How many number will be insert to linkedList?\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("\nPlease insert the %dth data:\n", i+1);
        scanf("%d", &x);
        printf("\nPlease insert the position of %dth data:\n", i+1);
        scanf("%d", &position);
        InsertAtTheNthPosition(x, position);
        Print();
    }

    printf("\n\nSau khi reverse la: ");
    Reverse_Iterative();
    Print();

    return 0;
}