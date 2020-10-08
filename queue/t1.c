#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
int arr[MAXSIZE];
int front;
int rear;


bool isFull(){
    if ( front == (rear+1)%MAXSIZE )
        return true;
    else
        return false;
}

bool isEmpty(){
    if ((rear == front) && (front = -1))
        return true;
    else
        return false;
}

void EnQueue(int x){
    if (!isFull()){
        if (isEmpty()){
            rear += 1;
            front += 1;
            arr[rear] = x;
        }
        else{
            rear = (rear+1)%MAXSIZE;
            arr[rear] = x;
        }
    }
    else
        printf("\nQueue is full, can not Enqueue\n");
}

void DeQueue(){
    if ((front == rear) && (front != -1)){
        front = -1;
        rear = -1;
    }
    else{
        if (!isEmpty()){
            front = (front+1)%MAXSIZE;
        }      
        else
            printf("\nQueue is empty, can not Dequeue\n");
    }
}

void Print(){
    if((front == rear) && (front == -1)){
        printf("\nzzzzz: %d\n", front);
        return;
    }
    else{
        printf("\ntttttttt: %d\n", front);
        if (front <= rear){
        //if ((front <= rear) && (front =! -1)){
            printf("\nyyyyyy: %d\n", front);
            for (int i = front; i <= rear; i++){
                printf("\nhahaha: i = %d, front = %d, rear = %d\n", i, front, rear);
                printf("%5d", arr[i]);
            }
        }
        else{
            for (int i = (front+1)%MAXSIZE; i <= (rear+1)%MAXSIZE; i++)
                printf("%5d", arr[i]);
        }
        printf("\n");
    }
}

void main(){
    front = -1;
    rear = -1;

    EnQueue(6);
    EnQueue(5);
    EnQueue(1);
    EnQueue(7);
    EnQueue(8);
    printf("\nfront = %d\n", front);
    printf("\nrear = %d\n", rear);

    for (int i = front; i <= rear; i++){
        printf("\nhahaha: i = %d, front = %d, rear = %d\n", i, front, rear);
        printf("%5d", arr[i]);
    }

    //Print();

    DeQueue();
    DeQueue();
    DeQueue();

    printf("\nfront = %d\n", front);
    printf("\nrear = %d\n", rear);

    Print();

    DeQueue();

    printf("\nfront = %d\n", front);
    printf("\nrear = %d\n", rear);

    Print();



}
