#include <stdio.h>

int LinearSearch(int array[], int k, int n){          //k: gia tri phan tu can tim, n: so phan tu cua mang
    int i;
    for (i = 0; i < n; i++){
        if (array[i] == k)
            return i;
    }
    return -1;
}

int main(){
    int LA[] ={1,2,3,4,5};
    int n = 5;
    int k = 3;

    int vitri = LinearSearch(LA, k, n);
    (vitri != -1) ? printf("tim thay gia tri %d tai vi tri %d\n", k, vitri)
                  : printf("khong tim thay gia tri");
}