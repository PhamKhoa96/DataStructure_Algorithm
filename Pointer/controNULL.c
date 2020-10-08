#include <stdio.h>

void main(){
    int *ptr1;
    int b = 6;
    ptr1 = &b;

    printf("Dia chi cua bien con tro ptr1: %d\n", ptr1);
    printf("Gia tri cua bien con tro ptr1: %d\n", *ptr1);

    int *ptr2 = NULL;
    printf("Dia chi cua bien con tro ptr2: %d\n", ptr2);
    printf("Gia tri cua bien con tro ptr2: %d\n", *ptr2);  
}