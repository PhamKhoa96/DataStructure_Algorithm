#include <stdio.h>
#include <stdlib.h>
/*
https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/
https://www.youtube.com/watch?v=Ttg4yNP_RQM&list=PLE1qPKuGSJaBq4VFzTYrhzCiPvCoI8JDv&index=60
/*
Giống nhau: 
- Cả 2 đều là hàm, đều trả ra con trỏ void
- Trả về: con trỏ trỏ tới vùng nhớ được cấp phát 
          hoặc NULL trong trường hợp không thực hiện được việc cấp phát bo965 nhớ

Khác nhau:
    Nội dung                        calloc                                          malloc
    - Khởi tạo giá trị              Có, giá trị = 0                                 Không, nó sẽ chứa các giá trị rác
    - Số lượng tham số đầu vào      2 (số lượng phần tử, kích thước của kiểu)       1 (kích thước vùng nhớ cần cấp phát)            
*/

void showInfo(int *a){
    for (size_t i = 0; i < 10; i++)
        printf("%13d", a[i]);
}

int main(){
    //malloc
    puts("\nUse malloc: ");
    int *a = (int*) malloc(10*sizeof(int));
    showInfo(a);
    free(a);            //Giả phóng bộ nhớ trong C là free(), trong C++ là delete()

    //calloc
    puts("\nUse calloc: ");
    a = (int*) calloc(10,sizeof(int));
    showInfo(a);
    free(a);

    return 0;
}