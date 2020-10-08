#include <stdio.h>

void Merge(int arr[], int l, int m, int r){
    int Left  = m - l;
    int Right = r - m;
    int u, v;

    // Lưu 2 half vào 2 mang
    int LeftArr[Left], RightArr[Right];
    for (u = 0; u < Left; u++)
        LeftArr[u] = arr[l+u];
    for (v = 0; v < Right; v++)
        RightArr[v] = arr[m+v];

    // vừa gộp 2 half lại vừa sắp xếp
    int i = 0, j = 0;
    int k = l;
    while( i < Left && j < Right){
        if (LeftArr[i] <= RightArr[j]){
            arr[k] = LeftArr[i];
            i++;
            k++;
        }
        if (RightArr[j] < LeftArr[i]){
            arr[k] = RightArr[j];
            j++;
            k++;
        }
    }
    // Đưa các phần tử còn lại vào mảng nếu chưa gộp lại hết
    while (i < Left){
        arr[k] = LeftArr[i];
        i++;
        k++;
    }
    while (j < Right){
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r-l)/2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}

void InMang(int LA[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("LA[%d] = %d\n", i, LA[i]);
}

int main(){
    int LA[] = {6,5,4,3,2,1};
    int n = sizeof(LA) / sizeof(LA[0]);

    printf("Mang truoc khi sap xep\n");
    InMang(LA, n);

    MergeSort(LA, 0, n);

    printf("Mang sau khi sap xep\n");
    InMang(LA, n);
    
    return 0;
}