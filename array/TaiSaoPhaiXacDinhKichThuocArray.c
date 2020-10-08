#include <stdio.h>

int main() {
    int A[] ={1,2,3,4,5};
    int B[]={10,20,30,40,50};   

    B[11] = 100;  //ta thay đổi B nhưng giá trị trong array A bị thay đổi luôn
    B[12] = 200;
    B[13] = 300;

    int n=5; 

    int i;


    for (i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }


    printf("\n\n\n");


    for (i = 0; i < n; i++) {              
        printf("B[%d] = %d\n", i, B[i]);
    }

    return 0;
}