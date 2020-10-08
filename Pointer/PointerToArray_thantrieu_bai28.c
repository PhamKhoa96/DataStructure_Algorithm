#include <stdio.h>

int main(){
    int arr[] = {1,2,3,4,5,6};
    int *ptr = arr;                                 // ban thân tên mảng là 1 con trỏ, nên không cần dấu &

    printf("\nDia chi cua mang: %x", &arr);
    printf("\nDia chi cua mang: %x", arr);          // ban thân tên mảng là 1 con trỏ, nên không cần dấu & vẫn được
                                                    // nghĩa là arr tương đương với &arr
                                                    // nhưng lưu ý: arr[i] chỉ nội dung của phần tử thứ i trong mảng
                                                    //              nên arr[i] không tương đương &arr[i]                
    printf("\nDia chi cua arr[0]: %x", &arr[0]);    // địa chỉ của mảng cũng là địa chỉ của phần tử đầu tiên trong mảng

    printf("\nGia tri cua ptr: %x", ptr);           // Gía trị của con trỏ là địa chỉ của biến arr mà con trỏ trỏ tới 
    printf("\nGia tri tai dia chi ma con tro tro toi: %x", *ptr);     // lấy nội dung tại địa chỉ mà con trỏ trỏ tới thì ta thêm dấu *

    printf("\n");

    // các phần tử liền kề nhau trong mảng cũng được lưu ở các địa chỉ liền kề nhau
    int i;
    for (i = 0; i <= 5; i++)
        printf("%5d", arr[i]);

    printf("\n");

    for (i = 0; i <= 5; i++)
        printf("%5d", *(ptr+i));   

    printf("\n");

    for (; ptr <= &arr[5]; ptr++)       // (ptr++) hay (ptr+1) tương đương với ptr + 1*số_byte_của_kiểu_dữ_liệu_của_biến_mà_con_trỏ_trỏ_tới
        printf("%5d", *ptr);            // tương tự: (ptr+n) tương đương với ptr + n*số_byte_của_kiểu_dữ_liệu_của_biến_mà_con_trỏ_trỏ_tới

    return 0;
}