#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

int arr[MAXSIZE]; 
int front = -1;
int rear = -1;

bool isEmpty(){
    if (front > rear || ((front == rear) && (rear == -1)) )
        return true;
    else
        return false;
}

bool isFull(){
    if (rear >= MAXSIZE - 1)
        return true;
    else
        return false;
}

void EnQueue(int x){
    if (isEmpty() == true){
        rear += 1;
        front += 1;
        arr[rear] = x;
    }
    else{
        if (isFull() == false){
            rear += 1;
            arr[rear] = x;
        }
        else
            printf("\nFull queue, can not enqueue\n\n");
    }
}

void DeQueue(){
    if (isEmpty() == false){
        if (front < rear)
            front += 1;
        else if (front == rear){
            front = -1;
            rear = -1;
        }
    }
    else
        printf("\nEmpty queue, can not dequeue\n\n");
}

void Print(){
    int i;
    for (i = front; i <= rear; i++ )
        printf("%5d", arr[i]);
    printf("\n");
}

int main() {
    EnQueue(1);
    EnQueue(5);
    EnQueue(1);
    EnQueue(7);
    EnQueue(1);

    Print();

    EnQueue(6);
    EnQueue(1);
    EnQueue(8);
    EnQueue(7);
    EnQueue(18);

    Print();

    EnQueue(4);

    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();

    Print();

    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();

    EnQueue(8);
    EnQueue(45);
    EnQueue(23);

    Print();

    return 0;
}