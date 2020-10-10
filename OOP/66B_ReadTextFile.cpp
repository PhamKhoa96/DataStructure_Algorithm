/* 
	Đọc từ đầu đến cuối file
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main() {
    // cách 1: tạo mảng để nhận để lưu input vào, sau đó xuất mảng ra
    fstream ifs1("input.txt");
    size_t n;
    ifs1 >> n;
    int* a = new int(n);
    for (int i = 0; i < n; i++){
        ifs1 >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    ifs1.close();

    // cách 2: không cần dùng mảng để lưu tất cả các phần tử mà chỉ cần dùng 1 biến vừa lưu vừa xuất
    // nên dùng cách này
    fstream ifs2("input.txt");
    int number;
    while (!ifs2.eof()){            //khi chưa kết thúc file thì vẫn tiếp tục đọc
        ifs2 >> number;
        cout << number << " ";
    }
    cout << endl;
    ifs2.close();


	fstream ifs("input3.txt");
	string s;
	while (!ifs.eof()) {
		getline(ifs, s);        // đọc cả dòng và lưu vào biến s
		cout << s << "\n";
	}
	ifs.close();
	return 0;
}