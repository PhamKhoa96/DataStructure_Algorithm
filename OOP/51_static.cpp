/*
	Các thành phần static: những gì mà các đối tượng được tạo ra có thể chia sẻ với nhau
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Student {
private:
	char ID[20];
	char name[100];
	int age;
	float mark;
	char address[100];
	static int count;               // nếu muốn truy cập đến các thành phần trong private (kể cả nó có là static hay không) thì phải thông qua các thành phần public

public:
	Student();
	Student(char*);
	Student(char*, int);
	Student(char*, int, char*, char*, float);
	void showInfo();

	void setID(char*);
	void setName(char*);
	void setAddress(char*);
	void setAge(int);
	void setMark(float);

	int getAge();
	float getMark();
	char* getName();
	char* getAddress();
	char* getID();

	static int getCount();              // các hàm là static thì chỉ có thể truy cập đến các thành phần static trong class. Còn với các method bình thường thì chúng có thể truy cập tới bất kì thành phần nào kể cả có là static hay không

	static void setCount(int c);
};

int Student::count = 0; //khai báo ở trong Class nhưng gán giá trị thì phải gán bên ngoài class

int Student::getCount() {         
	return count;                       // các hàm là static thì chỉ có thể truy cập đến các thành phần stactic
}                                       // các thành phần static là dùng chung nên không cần con trỏ this, vì con trỏ this ý chỉ con trỏ trỏ tới vùng nhớ của object hiện tại, nhưng vì các object dùng chung static nên không cẩn this

void Student::setCount(int c) {
	//age = c;                          // các hàm là static thì chỉ không thể truy cập đến các thành phần khác
}

Student::Student() {
	cout << "Call non para constructor" << endl;
	this->name[0] = '\0';
	this->address[0] = '\0';
	this->ID[0] = '\0';
	this->age = 0;
	this->mark = 0;
	count++;
}

Student::Student(char* name) {
	cout << "Call 1 para constructor" << endl;
	strcpy_s(this->name, 99, name);
	this->address[0] = '\0';
	this->ID[0] = '\0';
	this->age = 0;
	this->mark = 0;
	count++;
}

Student::Student(char* name, int age) {
	cout << "Call 2 params constructor" << endl;
	strcpy_s(this->name, 99, name);
	this->address[0] = '\0';
	this->ID[0] = '\0';
	this->age = age;
	this->mark = 0;
	count++;
}

Student::Student(char* name, int age, char* id, char* address, float mark) {
	cout << "Call 5 params constructor" << endl;
	strcpy_s(this->name, 99, name);
	strcpy_s(this->ID, 19, id);
	strcpy_s(this->address, 99, address);
	this->age = age;
	this->mark = mark;
	count++;
}

void Student::setID(char* id) {
	strcpy_s(this->ID, 19, id);
}

void Student::setName(char* name) {
	strcpy_s(this->name, 99, name);
}

void Student::setAddress(char* addr) {
	strcpy_s(this->address, 99, addr);
}

void Student::setAge(int age) {
	this->age = age;
}
void Student::setMark(float mark) {
	this->mark = mark;
}

int Student::getAge() {
	return this->age;
}

float Student::getMark() {
	return this->mark;
}

char* Student::getName() {
	return this->name;
}
char* Student::getAddress() {
	return this->address;
}

char* Student::getID() {
	return this->ID;
}

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

	Student s, s1, s2, s3, s4; // goi ham tao 0 tham so
	Student s5(name), s6(name, 20);
	Student s7(name);

	//cout << s7.count << endl;                 không thể truy cập như vầy vì count đc khai báo trong phần private, chúng ta phải thông qua các hàm trong public để lấy count ra
	//cout << Student::count << endl;           nếu như biến được khai báo trong public thì ghi như vầy được

	cout << s7.getCount() << endl;
	cout << Student::getCount() << endl;        // vì static là dữ liệu chung cho các đối tượng nên không nhất thiết cần đối tượng mà chỉ cần tên class là có thể truy cập được
	
	return 0;
}