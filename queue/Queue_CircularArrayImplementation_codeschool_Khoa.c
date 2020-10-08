#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
int arr[MAXSIZE];
int front = -1;
int rear = -1;

bool isFull(){
    if ( front == (rear+1)%MAXSIZE )
        return true;
    else
        return false;
}

bool isEmpty(){
    if ((rear == front) && (front == -1))
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
        printf("\nQueue is full, can not Enqueue");
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
            printf("Queue is empty, can not Dequeue\n");
    }
}

void Print(){
    printf("\nfront = %d\n", front);
    printf("rear = %d\n", rear);

    if((front == rear) && (front == -1)){
        printf("Queue is empty\n");
        return;
    }
    else{
        if (front <= rear){
            for (int i = front; i <= rear; i++){
                printf("%5d", arr[i]);
            }
        }
        else{
            for (int i = front ; i <= MAXSIZE+rear ; i++)
                printf("%5d", arr[i%MAXSIZE]);
        }
        printf("\n");
    }  
}

void main(){
    EnQueue(6);EnQueue(5);EnQueue(1);EnQueue(7);EnQueue(8);
    Print();

    DeQueue();DeQueue();DeQueue();DeQueue();
    Print();

    DeQueue();      //Queue is empty
    Print();

    EnQueue(1);EnQueue(2);EnQueue(3);EnQueue(4);EnQueue(5);
    EnQueue(6);EnQueue(7);EnQueue(8);EnQueue(9);EnQueue(10);
    Print();

    EnQueue(11);    //Queue is full, can not Enqueue
    Print();

    DeQueue();DeQueue();DeQueue();
    Print();

    EnQueue(12);EnQueue(13);EnQueue(14);
    Print();

    EnQueue(11);    //Queue is full, can not Enqueue
    Print();
}