/*
	Lớp string và các phương thức của nó
	- hàm tạo
	- getline();
	- length();
	- push_back();      đẩy thêm kí tự vào cuối chuỗi
	- pop_back();       lấy kí tự cuối ra khỏi chuỗi
	
*/

#include<iostream>
#include <string>
using namespace std;

int main() {
	string name1 = "Than Trieu";
	
	for (size_t i = 0; i < name1.length(); i++)
	{
		cout << name1[i] << endl;      // cách 1: lấy như mảng
		cout << name1.at(i) << endl;    // cách 2: dùng method at();
	}


	string name;
	name = "Than Trieu";
	name = "Thu Tran";
	name = "Hoa Nguyen";
	string address("Ha Noi");
	string address1(address);
	string nX(100, 'X');
    cout << endl;
	cout << nX << endl;
	cout << "nX co " << nX.length() << " ki tu";

	string fullName;
	cout << "\n\nEnter your full name: ";
	getline(cin, fullName);                 // đọc cả dòng từ bàn phím
    fullName.pop_back();
    fullName.pop_back();
	cout << "Hello " << fullName << "!" << endl;
}