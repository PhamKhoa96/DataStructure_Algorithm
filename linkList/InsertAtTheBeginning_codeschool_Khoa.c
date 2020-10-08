//Inserting a node at beginning: https://www.youtube.com/watch?v=cAZ8CyDY56s

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void InsertAtTheBeginning(int x){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print(){
    printf("Gia tri cac phan tu trong linklist la:");
    struct Node* temp1;
    temp1 = head;

    while (temp1 != NULL){
        printf("%5d", temp1->data);
        temp1 = temp1->next;
    }
}

int main(){

    head = NULL;

    int n, i, x;
    printf("How many number will be insert into linkedList?\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("\nPlease insert the %dth data: \n", i+1);
        scanf("%d", &x);
        InsertAtTheBeginning(x);
        printf("list: ");
        Print();
    }

    return 0;
}