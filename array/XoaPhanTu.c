#include <stdio.h>

int main(){
    int LA[] ={1,2,3,4,5};
    int i, j;
    int n = 5; //Do dai cua mang
    int k = 3; //Vi tri can xoa

    printf("Mang truoc khi xoa phan tu\n");
    for (i = 0; i < n; i++){
        printf("LA[%d] = %d\n", i, LA[i]);
    }

    j = k;
    while (j < n - 1){
        LA[j] = LA[j+1];
        j += 1;
    }

    printf("Mang sau khi xoa phan tu\n");
    for (i = 0; i < n - 1; i++){                //n-1 la kich thuoc cua mang sau khi xoa
        printf("LA[%d] = %d\n", i, LA[i]);
    }

    return 0;
}