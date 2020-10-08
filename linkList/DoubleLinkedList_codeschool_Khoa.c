#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

void InsertAtHead(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;

    if(head == NULL){
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}

void InsertAtTail(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;

    if (head == NULL){
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else{
        struct Node* temp2;
        temp2 = head;
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
        temp->next = NULL;
    }
}

void Print(){
    struct Node* temp1;
    temp1 = head;
    while(temp1 != NULL){
        printf("%5d", temp1->data);
        temp1 = temp1->next;
    }
}

void Print_Reverse(){
    struct Node* temp4;
    temp4 = head;
    while (temp4->next != NULL){
        temp4 = temp4->next;
    }

    while(temp4 != NULL){
        printf("%5d", temp4->data);
        temp4 = temp4->prev;
    }
}

int main(){
    head = NULL;

    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);
    InsertAtHead(4);
    InsertAtHead(5);  
    Print();
    printf("\n");   

    InsertAtTail(7);
    InsertAtTail(8);
    InsertAtTail(1);
    InsertAtTail(2);
    InsertAtTail(4);
    Print();
    printf("\n");

    Print_Reverse();
    
    return 0;
}