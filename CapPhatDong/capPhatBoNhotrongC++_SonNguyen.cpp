//youtube: https://www.youtube.com/watch?v=Y5Kp00nSeIM
#include <iostream>

using namespace std;

struct node{
    int data;
    node *pnext;
};

int main(){
    node a;
    a.data = 4;
    cout << a.data <<endl;
    
    node *b = new node; // do b là 1 con trỏ thì khi khởi tạo sẽ không có bộ nhớ sẵn, nên ta cấp phát bộ nhớ cho ô nhớ mà địa chỉ b trỏ tới
    b->data = 6;
    cout << b->data <<endl;

    return 0;
}