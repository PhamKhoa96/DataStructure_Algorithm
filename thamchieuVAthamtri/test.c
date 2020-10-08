#include <stdio.h>

void Swap(int a, int b){
    int c = a;
    a = b;
    b = c;
}

void Replace(int LA[], int x){
    LA[2] = x;
}

void InMang(int LA[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("LA[%d] = %d\n", i, LA[i]);
}

int main(){
    int a = 2, b = 4;
    printf("%d---%d\n",a ,b);
    Swap(a,b);
    printf("%d---%d\n",a ,b);

    /*
    Mặc dù nhìn có vẻ là truyền tham trị như bên trên, nhưng ta thấy mảng sau khi replace thì nó đã thay đổi, tại sao lại như vậy?
    Vì bản chất mảng là 1 con trỏ, nghĩa là khi truyền mảng vào hàm thì có nghĩa là ta đang truyền địa chỉ của mảng vào hàm -> đây là truyền tham chiếu chứ không phải tham trị
    Và khi tương tác với các LA[i], chính là ta đang tương tác với nội dung tại địa chỉ đó
    */
    int LA[] = {1,2,3,4,5,6};
    int x = 100;
    int n = 5;
    printf("Mang truoc khi replace\n");
    InMang(LA, n);
    Replace(LA, x);
    printf("Mang sau khi replace\n");
    InMang(LA, n);

    return 0;
}