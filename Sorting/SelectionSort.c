#include <stdio.h>

void Swap(int *a, int *b){
    int temp1;
    temp1 = *a;
    *a = *b;
    *b = temp1;
}

void SelectionSort(int LA[], int n){
    int j, i;
    int temp, vitri;
    for (j = 0; j < n - 1; j++){
        temp = LA[j];
        for (i = j + 1; i < n; i++){
            if (LA[i] < temp){
                vitri = i;
                temp = LA[i];
            }
        }
        Swap(&LA[j], &LA[vitri]);      
    }
}

void InMang(int LA[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("LA[%d] = %d\n", i, LA[i]);
}

void main(){
    int LA[] = {64, 25, 12, 22, 11};
    int n = sizeof(LA) / sizeof(LA[0]);
    printf("Mang truoc khi sap xep\n");
    InMang(LA, n);

    SelectionSort(LA, n);

    printf("Mang sau khi sap xep\n");
    InMang(LA, n);
}