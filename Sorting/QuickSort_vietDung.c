#include <stdio.h>

void Swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition (int LA[], int low, int high){
    int pivot = LA[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++){    // CHÚ Ý: j chạy từ low chứ không phải từ 0
    // j: để duyệt hết mảng
        if (LA[j] <= pivot){
            // i: lưu lại index của phần tử lớn nhất mà nhỏ hơn pivot cho tới hiện tại  (nghĩa là cận dưới lớn nhất tại thời điểm đang xét so với pivot )
            i++;
            Swap(&LA[j], &LA[i]);
        }
    }
    Swap(&LA[i+1], &LA[high]);

    return i+1;
}

void QuickSort(int LA[], int low, int high){
    if (low < high){
        int k = Partition(LA, low, high);

        QuickSort(LA, low, k - 1);
        QuickSort(LA, k + 1, high);
    }

}

void InMang(int LA[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("LA[%d] = %d\n", i, LA[i]);
}

void main(){
    int LA[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(LA) / sizeof(LA[0]);
    printf("Mang truoc khi sap xep\n");
    InMang(LA, n);

    QuickSort(LA, 0, n - 1);

    printf("Mang sau khi sap xep\n");
    InMang(LA, n);
}