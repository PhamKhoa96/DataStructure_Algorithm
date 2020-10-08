#include <stdio.h>

void Swap(int *xp, int *yp) 
{ 
    int temp = *xp;
    *xp = *yp; 
    *yp = temp; 
} 

void BubbleSort(int LA[], int n){
    int j, i;
    for (j = n; j >= 0; j-- ){
        for (i = 0; i < j - 1; i++)
            if (LA[i] > LA[i+1])
                Swap(&LA[i], &LA[i+1]);
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
    printf("%d\n", n);
    InMang(LA, n);

    BubbleSort(LA, n);

    printf("Mang sau khi sap xep\n");
    InMang(LA, n);
}