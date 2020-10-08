#include <stdio.h>
#include <stdlib.h>

void main(){
    int* arr = (int*)malloc(sizeof(int));
    printf("Size of array: %d", sizeof(arr));

    int arr1[] = {1};
    printf("\nSize of array1: %d", sizeof(arr1));

    int* ptr;
    printf("\nSize of ptr: %d", sizeof(ptr));
}