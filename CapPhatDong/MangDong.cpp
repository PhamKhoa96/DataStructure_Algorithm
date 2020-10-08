#include <iostream>
using namespace std;

int main(){
    int num_of_elements;
    cout << "Enter number of elements you want to create: ";
    cin >> num_of_elements;                         // Nhập bào số lượng phần tử của mảng trong quá trình run-time

    if(num_of_elements > 0){
        int *p_arr = new int[num_of_elements];     // Đối với mảng động thì ta xin cấp phát trong lúc chương trình đang chạy (run-time) vẫn được, còn với mảng tĩnh thì không, mảng tĩnh thì ta phải biết trước số lượng phần tử trong mảng để chương trình compile trước đó
        int i;

        cout << "gia tri khoi tao: " << endl;
        for (i = 0; i < num_of_elements; i++)
            cout << p_arr[i] << endl;

        cout << "dia chi vung nho: "  << endl;
        for (i = 0; i < num_of_elements; i++)
            cout << &p_arr[i] << endl;
    }

    return 0;
}