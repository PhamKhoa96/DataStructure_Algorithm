#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 5

int top = -1;
int arr[MAXSIZE];

void push(int x){
    if (top == MAXSIZE -1)
        printf("stack overflow, can not push anymore");
    else{
        top += 1;           //2 dòng này có thể viết lại thành arr[++top] = x;
        arr[top] = x;
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

    push(79);
    Print();

    pop();
    pop();
    Print();
    pop();
    pop();
    pop();

    pop();
    Print();

}