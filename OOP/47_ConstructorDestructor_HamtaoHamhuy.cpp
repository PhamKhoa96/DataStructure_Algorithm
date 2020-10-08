/*
	Hàm khởi tạo, hàm hủy
*/
#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
	char ID[20];
	char name[100];
	int age;
	float mark;
	char address[100];

	Student() {                                         // hàm tạo (constructor) mặc định khi ra tạo ra Class, dùng để khởi tạo giá trị cho các thuộc tính
		cout << "Call non para constructor" << endl;
		this->name[0] = '\0';                           // có thể không cần dùng con trỏ this
		this->address[0] = '\0';
		this->ID[0] = '\0';
		this->age = 0;
		this->mark = 0;
	}

	Student(char* name) {                               // có thể tạo thêm constructor khác, nhưng nhớ là vẫn cùng tên Student
		cout << "Call 1 para constructor" << endl;      // lưu ý: truyền kí tự vào hàm thì phải sử dụng kiểu con trỏ
		strcpy_s(this->name, 99, name);                 // tối đa là 99 kí tự. name đầu tiên là thuộc tính, name thứ 2 là tham số bên ngoài truyền vào -> tác dụng của con trỏ this giúp phân biệt đâu là thuộc tính, đâu là tham số truyển từ ngoài vào. Hoặc 1 cách đơn giản ta có thể đặt tên tham số khác name, ví dụ name1
		this->address[0] = '\0';
		this->ID[0] = '\0';
		this->age = 0;
		this->mark = 0;
	}

	Student(char* name, int age) {
		cout << "Call 2 params constructor" << endl;
		strcpy_s(this->name, 99, name);
		this->address[0] = '\0';
		this->ID[0] = '\0';
		this->age = age;
		this->mark = 0;
	}

	Student(char* name, int age, char* id, char* address, float mark) {
		cout << "Call 5 params constructor" << endl;
		strcpy_s(this->name, 99, name);
		strcpy_s(this->ID, 19, id);
		strcpy_s(this->address, 99, address);
		this->age = age;
		this->mark = mark;
	}

	void showInfo() {                                                   //phương thức để hiển thị thông tin đối tượng
		cout << "============== Student Info ===========" << endl;
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
		cout << "Id: " << ID << endl;
		cout << "Age: " << age << endl;
		cout << "Mark: " << mark << endl;
		cout << "=======================================" << endl;
	}

	~Student() {                                // hàm hủy (destructor) thì chỉ có 1 hàm, dùng để thu hồi bộ nhớ
		cout << "Call destructor" << endl;
	}
};

int main() {
	char* name = new char[100];
	strcpy_s(name, 99, "Tran Van Hung");
	char* id = new char[20];
	strcpy_s(id, 19, "B21DCCN123");
	char* addr = new char[100];
	strcpy_s(addr, 99, "Hanoi");

	Student s; // goi ham tao 0 tham so
	Student s1(name); // goi ham tao 1 tham so
	Student s2(name, 20); // goi ham tao 2 tham so
	Student s3(name, 21, id, addr, 9.5);// goi ham tao 5 tham so

	s.showInfo();
	s1.showInfo();
	s2.showInfo();
	s3.showInfo();

	return 0;
}