#include <stdio.h>

int main(){
    int LA[] = {1, 2, 3, 4, 5};
    int n =5; // Chieu dai cua mang
    int value = 100; // Gia tri phan tu can tim kiem
    int k = 3; // Vi tri phan tu can update
    int i;

    for (i = 0; i < n; i++){
        if (i == k){
            printf("Thay gia tri %d tai vi tri %d trong mang thanh gia tri %d\n", LA[i], i, value);
        }
    }

    return 0;
}