#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node* head;

    head = NULL;

    printf("Pham");
    printf("%d", head->data);
    printf("Khoa");

    return 0;
}