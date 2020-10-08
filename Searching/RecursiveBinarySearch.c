#include <stdio.h>

int RecursiveBinarySearch(int array[], int l, int r, int x){        //x la gia tri can tim, l: index ben trai, r: index ben phai
    
    while (l <= r){
        int m = l + (r-l)/2;

        if (array[m] == x)
            return m;
        if (array[m] > x)
            return RecursiveBinarySearch(array, l, m - 1, x);
        else
            return RecursiveBinarySearch(array, m + 1, r, x);
    }
}


int main(){
    int LA[] = {1,2,3,4,5,6};
    int l = 0;
    int r = sizeof(LA) / sizeof(LA[0]) - 1;
    int x = 6;
    int value = RecursiveBinarySearch(LA, l, r, x);
    printf("gia tri %d duoc tim thay o vi tri %d\n", x, value);
}
