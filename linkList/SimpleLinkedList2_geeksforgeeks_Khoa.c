#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void DuyetLinkedList(struct Node *x){
    while (x != NULL){
        printf("\nDATA: %d", x->data);
        x = x->next;            // nếu ta dùng đệ quy thì sẽ bị lặp vô tận: DuyetLinkedList(x->next);
    } 
}

int main(){
    //struct Node *head = NULL, *second = NULL, *third = NULL;
	struct Node* head = NULL; 
	struct Node* second = NULL; 
	struct Node* third = NULL; 

    // Cap phat do nho
    head = (struct Node*)calloc(1, sizeof(struct Node));
    second = (struct Node*)calloc(1, sizeof(struct Node));
    third = (struct Node*)calloc(1,sizeof(struct Node));

    /* lưu ý: ta cấp phát cho head, second, third chứ không phải là head->next, head->next, third->next
    head->next = (struct Node*)calloc(1, sizeof(struct Node));
    second->next = (struct Node*)calloc(1, sizeof(struct Node));
    third->next = (struct Node*)calloc(1,sizeof(struct Node));
    */

    // link lại
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Tao du lieu
    head->data = 1;
    second->data = 2;
    third->data = 3;

    //Duyệt LinkList
    DuyetLinkedList(head);

    printf("\n\n%d\n", head);
    printf("%d\n", second);
    printf("%d\n", third);

    return 0;
}