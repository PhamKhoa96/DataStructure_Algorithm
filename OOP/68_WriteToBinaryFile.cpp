/*
	Ghi thông tin đối tượng ra file nhị phân
    Read/Write trong file nhị phân nhanh hơn trong file text, ta có thể thao tác tại bất cứ vị trí nào mong muốn
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
	char name[100];         //binary file yêu cầu các dữ liệu phải được khai báo kích thước trước và có cùng kích thước
	char address[100];      // vì vậy ta phải dùng kiểu char chứ không được dùng string vì string không khai báo trước kích thước được
	char email[100];
	int age;

public:
	Person();
	Person(int, string, string, string);
	void showInfo();
	friend void writeToFile(Person, ofstream&);
	void setName(string name);
	void setAge(int age);
	void setEmail(string email);
	void setAddress(string address);
};

void writeToFile(Person p, ofstream& ofs) {
	if (ofs.good()) {                               // kiểm tra thao tác mở file để ghi có thực hiện được không, kiểu như nó sẽ kiểm tra có đủ bộ nhớ không
		ofs.write((char*)& p, sizeof(Person));      //cú pháp write vào file
	}
}

Person::Person() {
	age = 0;
}

Person::Person(int age, string name, string address, string email) {
	this->setAddress(address);
	this->setAge(age);
	this->setName(name);
	this->setEmail(email);
}

void Person::setAddress(string address) {
	size_t size = address.length();
	size = (size > 99) ? 99 : size;
	address.copy(this->address, size);
	this->address[size] = '\0';
}

void Person::setName(string name) {
	size_t size = name.length();
	size = (size > 99) ? 99 : size;
	name.copy(this->name, size);
	this->name[size] = '\0';
}

void Person::setEmail(string email) {
	size_t size = email.length();
	size = (size > 99) ? 99 : size;
	email.copy(this->email, size);
	this->email[size] = '\0';
}

void Person::setAge(int age) {
	this->age = (age < 0) ? 0 : age;
}

void Person::showInfo() {
	cout << "I am " << name << ", I'm " << age << " years old."
		<< "\nI live in " << address << ". My email address is "
		<< email << ".\nNice to meet you!\n";
	cout << endl;
}

int main() {
	Person p(20, "Trieu Van Than", "Ha Noi", "thantrieu@xmail.com");
	Person p1(20, "Tran Thu Huyen", "Ha Noi", "huyencute@xmail.com");
	Person p2(20, "Tran Thu Ngan", "Ha Noi", "heraffdas@xmail.com");
	Person p3(20, "Tran Thu Trang", "Ha Noi", "fadiffer@xmail.com");
    p.showInfo();
    p1.showInfo();
    p2.showInfo();
    p3.showInfo();

	ofstream ofs("PERSON.DAT", ios::binary);
	writeToFile(p, ofs);
	writeToFile(p1, ofs);
	writeToFile(p2, ofs);
	writeToFile(p3, ofs);

	ofs.close();
	
	return 0;
}