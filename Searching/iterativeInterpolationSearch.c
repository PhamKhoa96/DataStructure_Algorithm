#include <stdio.h>

int IterativeInterpolationSearch(int array[], int l, int r, int x){        //x la gia tri can tim, l: index ben trai, r: index ben phai
    
    while (l <= r){
        int m = l + (r-l) * (x - array[l]) / (array[r] - array[l]);

        if (array[m] == x)
            return m;
        if (array[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
}


int main(){
    int LA[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 
    int l = 0;
    int r = sizeof(LA) / sizeof(LA[0]) - 1;
    int x = 24;
    int value = IterativeInterpolationSearch(LA, l, r, x);
    printf("gia tri %d duoc tim thay o vi tri %d\n", x, value);
}
