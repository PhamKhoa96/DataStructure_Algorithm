#include <stdio.h>

int main(){
    int LA[] = {1, 4, 3, 4, 5};
    int n =5; // Chieu dai cua mang
    int k = 4; // Gia tri phan tu can tim kiem
    int i;

    for (i = 0; i < n; i++){
        if (LA[i] == k){
            printf("Tim thay gia tri %d tai vi tri %d trong mang\n", k, i);
        }
    }

    return 0;
}