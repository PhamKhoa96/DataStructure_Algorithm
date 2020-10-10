  
/*
	Kế thừa trong C++
    - Cho phép tái sử dụng lại các Class
        VD: class B được tạo có 1 phần thông tin nằm trong class A -> class B có thể kế thừa từ class A
    - Method từ lớp cha có thể sử dụng ở lớp con nếu như method đó là public hoặc protected
    - Các thành phần private trong lớp cha thì không thể truy cập từ lớp con mà phải thông qua tính đóng gói (nghĩa là thông qua các thành phần public trong lớp cha)

    - Lớp con: Ngoài các thông tin chung từ lớp cha thì nó còn có các thông tin đặc trưng khác
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
	string firstName;
	string lastName;
	string id;
public:
	Person();
	Person(string id);
	Person(string id, string first, string last);
	string getId();
	string getFirstName();
	string getLastName();
	string fullName();
};

Person::Person() {
	firstName = "";
	lastName = "";
	id = "";
}

Person::Person(string id) {
	Person();
	this->id = id;
}

Person::Person(string id, string first, string last) {
	this->id = id;
	this->lastName = last;
	this->firstName = first;
}

string Person::fullName() {
	return this->firstName + " " + this->lastName;
}

string Person::getId() {
	return id;
}

string Person::getFirstName() {
	return firstName;
}

string Person::getLastName() {
	return lastName;
}

class Student : public Person {                     // cú pháp kế thừa, class Student kế thừa từ class Person
	string studentID;                               // 1 class con có thể có nhiều class cha. (trong JAVA thì chỉ có thể có 1 lớp cha), VD:    class Student : public Person, private Human    (tính đa kế thừa)
	float mark;
	float fee;

public:
	Student();
	Student(string, float, float);
	Student(string, string, string, string, float, float);
	void study(string);
	void payFee(float);
	void doExamp(string);
	void showInfo();
};

Student::Student(string id, string first, string last, 
	string sId, float mark, float fee) : Person(id, first, last) {          // Person(id, first, last) là constructor của class cha
	this->studentID = sId;                                                  // nghĩa là khởi tạo các giá trị cho lớp cha thông qua constructor của lớp con luôn
	this->mark = mark;
	this->fee = fee;
}

void Student::showInfo() {                                      
	cout << "ID: " << getId() << endl;                      // có thể dùng hàm của lớp cha (truy cập đến các thuộc tính của class cha thông qua các thành phần public)
	cout << "Full name: " << fullName() << endl;            // có thể dùng hàm của lớp cha (truy cập đến các thuộc tính của class cha thông qua các thành phần public)
	cout << "Student ID: " << studentID << endl;
	cout << "Mark: " << mark << endl;
    //cout << "FirstName: " << firstName << endl;                ta không thể truy cập trực tiếp đến thành phần của lớp cha như thế này được
}

class Employee : public Person {
	string eID;
	float sallary;
	string role;

public:
	Employee();
	Employee(string, float, string);
	void doHisWork();
	void goToWorkSpace();
	bool getPayment();
};



int main() {
	Student s("12345485", "Than", "Trieu", "B20DCCN123", 3.36f, 20.5f);
	s.showInfo();
    
    cout << "First name la: " << s.getFirstName() << endl;   //ta có thể gọi tới các hàm của lớp cha từ đối tượng tạo ra từ lớp con
	return 0;
}