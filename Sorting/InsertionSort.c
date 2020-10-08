#include <stdio.h>

void InsertionSort(int LA[], int n){
    int j, i;
    for (j = 1; j < n; j++){
        i = j;
        while (LA[i] < LA[i-1]){
            int temp = LA[i];
            LA[i] = LA[i-1];
            LA[i-1] = temp;
            i -= 1;
        }
    }
}

void InMang(int LA[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("LA[%d] = %d\n", i, LA[i]);
}

void main(){
    int LA[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(LA) / sizeof(LA[0]);
    printf("Mang truoc khi sap xep\n");
    InMang(LA, n);

    InsertionSort(LA, n);

    printf("Mang sau khi sap xep\n");
    InMang(LA, n);
}