#include <iostream>
using namespace std;

int main(){
    int num_of_elements;
    cout << "Enter number of elements you want to create: ";
    cin >> num_of_elements;                         // Nhập bào số lượng phần tử của mảng trong quá trình run-time
    
    
    if(num_of_elements > 0){
        int arr[num_of_elements];                   // đáng lý ra là không được, nhưng theo chuẩn mới thì vẫn làm được y như mảng động, tham khảo thêm Variable Length Array (VLA) và Fixed Length Array (FLA) để biết thêm

        int i;

        cout << "gia tri khoi tao: " << endl;
        for (i = 0; i < num_of_elements; i++)
            cout << arr[i] << endl;

        cout << "dia chi vung nho: "  << endl;
        for (i = 0; i < num_of_elements; i++)
            cout << &arr[i] << endl;
    }

    return 0;
}