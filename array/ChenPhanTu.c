#include <stdio.h>

int main() {
    int LA[] ={1,2,3,4,5};
    int k = 3; // vi tri can chen
    int value = 100; // gia tri can chen
    int i, j;
    int n = 5; // kich thuoc cua mang ban dau

    printf("Mang truoc khi chen\n");
    for (i = 0; i < n; i++) {
        printf("LA[%d] = %d\n", i, LA[i]);
    }

    j = n;
    while (j >= k) {
        LA[j+1] = LA[j];
        j -= 1;
    }
    LA[k] = value;

    printf("Mang sau khi chen\n");
    for (i = 0; i < n +1; i++) {                //n+1 la kich thuoc cua mang sau khi chen
        printf("LA[%d] = %d\n", i, LA[i]);
    }

    return 0;
}