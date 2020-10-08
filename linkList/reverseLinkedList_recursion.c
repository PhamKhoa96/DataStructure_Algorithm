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


void Print(){
    printf("\nGia tri cac phan tu trong list la: ");
    
    struct Node* temp2;
    temp2 = head;
    while(temp2 != NULL){
        printf("%5d", temp2->data);
        temp2 = temp2->next;
    }
}

/*
struct Node* before;
struct Node* current;
struct Node* after;

void reverse(struct Node* bien){
    if (before != head)
        before = head;
    
    
    after = bien->next;
    if (after != NULL){ 
        reverse(after->next);
        after->next = bien;
        bien->next = before;
    }
    else{
        head = bien;
    }
}
*/

/*
void reverse(struct Node* p){
    if(p->next = NULL){
        head = p;
        return;
    }
    reverse(p->next);
    struct Node* q;
    q = p->next;
    q->next = p;
    p->next = NULL;
}
*/
/*
struct Node* reverse(){
    if(head->next = NULL){
        return head;
    }
    struct Node* p1; 
    p1 = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return p1;
}
*/

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

    reverse(head);

    Print();

    return 0;
}