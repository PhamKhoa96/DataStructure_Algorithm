#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 5

int top = -1;
int arr[MAXSIZE];
int j = 1;

int* Create_NewArr(){
    int* newArr = (int*)malloc(((j+1)*MAXSIZE)*sizeof(int));
    for (int k = 0; k < j*MAXSIZE; k++)
        newArr[k] = arr[k];
    return newArr;
}

void push(int value){
    if (top + 1 >= j*MAXSIZE){
        printf("\nstack overflow, can not push anymore, copy to new array (size = %d*MAXSIZE):", j+1);
        int* arr = Create_NewArr();
        top += 1;
        arr[top] = value;
        printf("\narr[top] = %d", arr[top]);
        j += 1;
    }
    else{
        top += 1;           //2 dòng này có thể viết lại thành arr[++top] = x;
        arr[top] = value;
    }
}

bool isEmpty(){
    if (top == -1)
        return true;
    else
        return false;    
}

void pop(){
    if (isEmpty())
        printf("Empty stack, Can not pop any more");
    else if ((top+1)%MAXSIZE == 0){
        top -= 1;
        j -= 1;
    }
    else
        top -= 1;
}

void Print(){
    int i;
    for (i = 0; i <= top; i++)
        printf("%5d", arr[i]);
    printf("\n");
}

void main(){
    push(3);
    push(24);
    push(5);
    push(77);
    push(78);
    push(79);                       //!!!!TẠI SAO giá trị 79 lại biến thành 0 trong arr????
    push(100);
    push(45);
    push(45);
    printf("\ntop = %d\n",top);
    printf("j = %d\n",j);
    Print();

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    printf("\ntop = %d\n",top);
    printf("j = %d\n",j);
    Print();

    push(3);
    push(24);

    printf("\ntop = %d\n",top);
    printf("j = %d\n",j);
    Print();
    push(217);                                  //!!!!TẠI SAO giá trị 217 lại biến thành 0 trong arr????
/*    push(77);
    push(78);
    push(79);
    push(100);*/
    printf("\ntop = %d\n",top);
    printf("j = %d\n",j);
    Print();

}