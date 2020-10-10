/*
	Đọc Nội dung file chứa thông tin các đối tượng (chứa cả số cả chữ)
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
	string name;
	string address;
	string email;
	int age;

public:
	Person();
	Person(int, string, string, string);
	void showInfo();
};

Person::Person() {
	age = 0;
	name = "";
	address = "";
	email = "";
}
Person::Person(int age, string name, string address, string email) {
	this->age = age;
	this->name = name;
	this->address = address;
	this->email = email;
}

void Person::showInfo() {
	cout << "I am " << name << ", I'm " << age << " years old."
		<< "\nI live in " << address << ". My email address is '"
		<< email << "'.\nNice to meet you!\n";
	cout << endl;
}

void showInfo(Person* ps, size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		ps[i].showInfo();
	}
}

int main() {
	fstream ifs("input2.txt");
	Person* persons = new Person[10];               // tạo ra mảng gồm 10 đối tượng Person
	string name;
	string email;
	string address;
	int age;
	size_t i = 0;
	while (!ifs.eof()) {
		ifs >> age;
		ifs.ignore();           // do đọc số xong rồi đến đọc cả dòng, thì phải cần có ignore 
		getline(ifs, address);  // vì dòng có cả dấu cách nên dùng getline()
		getline(ifs, name);
		getline(ifs, email);
		Person p(age, name, address, email);
		persons[i] = p;
		i++;
	}

	showInfo(persons, i);   // cách 1

    persons[0].showInfo();  // cách 2
    persons[1].showInfo();
    persons[2].showInfo();
    persons[3].showInfo();

	ifs.close();
	return 0;
}