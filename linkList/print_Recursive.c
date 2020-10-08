#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
//struct Node* temp2;


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

/*
không nên dùng cách set giá trị thẳng temp2=temp2->next

void Print(){
    printf("%5d\n", temp2->data);
    temp2 = temp2->next;
    if (temp2 != NULL){
        Print();
    }
}
*/

/*
Print_Reverse tự làm -> không nên dùng cách set giá trị thẳng temp2=temp2->next, vì khi đến lớp Print bên trong cùng, temp2 lúc này sẽ là NULL và temp2 sẽ mãi là NULL cho dù ta có đi từ lớp bên trong ra bên ngoài lại, cho nên lúc này temp2->data sẽ không có

void Print(){
    temp2 = temp2->next;
    if (temp2 != NULL){
        Print();
        printf("%5d\n", temp2->data);
    }
}
*/

void Print(struct Node* bien){
    printf("%5d", bien->data);
    if (bien->next != NULL)
        Print(bien->next);
}

void Print_Reverse(struct Node* bien){
    if (bien != NULL){
        Print_Reverse(bien->next);
        printf("%5d", bien->data);
    }
    //printf("%5d", bien->data);  // đặt ở đây là sai, nếu muốn đặt ở ngoài if thì làm như bên dưới, lý do là vì khi bien = NULL mà ta lấy bien->data ra thì chương trình sẽ không biết làm gì và khi đó nó sẽ dừng hẳn mà không thực hiện tiếp, xem test2.c để hình dung rõ hơn
                                  // trường hợp tương tự xảy ra khi 1 con trỏ nhưng không có data nhưng ta lại truy xuất data của nó ra, xem test3.c để hình dung rõ hơn
}

/*
void Print_Reverse(struct Node* bien){
    if (bien->next != NULL){
        Print_Reverse(bien->next);
    }
    printf("%5d", bien->data);
}

hoặc

void Print_Reverse(struct Node* bien){
    if (bien == NULL){
        return;
    }
    Print_Reverse(bien->next);
    printf("%5d", bien->data);
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
    }

    //temp2 = head;

    printf("\nGia tri cac phan tu trong list (forward) la: \n");
    Print(head);

    printf("\nGia tri cac phan tu trong list (backward) la: \n");
    Print_Reverse(head);

    return 0;
}