/*
	Hàm khởi tạo, hàm hủy
*/
#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:     //inaccessible                 // tính đóng gói là tất cả các thông tin được gói gọn trong 1 lớp -> các thuộc tính thường được để trong private
	char ID[20];                            // bên ngoài mà muốn truy cập các thuộc tính này thì phải thông qua các thành phần public
	char name[100];
	int age;
	float mark;
	char address[100];

public:     //accessible
	Student(); 
	Student(char*);    //khi đã đưa ra ngoài thì hàm bên trong không cần khai tham số nữa, mà chỉ cần khai báo kiểu truyền vào -> các hàm như vậy còn gọi là hàm nguyên mẫu
	Student(char*, int );
	Student(char*, int, char*, char*, float );

	void showInfo();

	~Student() {                                // hàm hủy (destructor) thì chỉ có 1 hàm, dùng để thu hồi bộ nhớ
		cout << "Call destructor" << endl;
	}
};

// đưa các constructor và method ra ngoài
Student::Student(){                             //hàm Student nằm trong Class Student. Ta đưa hàm constructor ra ngoài        
	cout << "Call non para constructor" << endl;
	this->name[0] = '\0';                           
	this->address[0] = '\0';
	this->ID[0] = '\0';
	this->age = 0;
	this->mark = 0;
}

Student::Student(char* name){                               
    cout << "Call 1 para constructor" << endl;      
    strcpy_s(this->name, 99, name);                 
    this->address[0] = '\0';
    this->ID[0] = '\0';
    this->age = 0;
    this->mark = 0;
}

Student::Student(char* name, int age) {
    cout << "Call 2 params constructor" << endl;
    strcpy_s(this->name, 99, name);
    this->address[0] = '\0';
    this->ID[0] = '\0';
    this->age = age;
    this->mark = 0;
}

Student::Student(char* name, int age, char* id, char* address, float mark) {
    cout << "Call 5 params constructor" << endl;
    strcpy_s(this->name, 99, name);
    strcpy_s(this->ID, 19, id);
    strcpy_s(this->address, 99, address);
    this->age = age;
    this->mark = mark;
}

//đối với method thì nhớ đưa kiểu ra phía đầu
void Student::showInfo() {                                                  
    cout << "============== Student Info ===========" << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Id: " << ID << endl;
    cout << "Age: " << age << endl;
    cout << "Mark: " << mark << endl;
    cout << "=======================================" << endl;
}

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