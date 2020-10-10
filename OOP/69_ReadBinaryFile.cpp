/*
	Đọc thông tin đối tượng từ file nhị phân
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
	char name[100];
	char address[100];
	char email[100];
	int age;

public:
	Person();
	Person(int, string, string, string);
	void showInfo();
	void setName(string name);
	void setAge(int age);
	void setEmail(string email);
	void setAddress(string address);
};

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
	ifstream ifs("PERSON.DAT", ios::binary);
	Person p;

	if (!ifs) {                                             // nếu không mở file được
		cout << "Loi doc du lieu" << endl;
	}
	else {
        // đọc từng đối tượng
		int index = 0;
		cout << "Nhap vi tri muon doc: (0->3)";
		cin >> index;
		index = (index >= 0 && index <= 3) ? index : 0;

		ifs.seekg(index * sizeof(Person));                  // seekg là seekg(et)        :dịch chuyển đến vị trí khác, do trong file có 1 đối tượng Person nên vị trí của thằng thứ i là i*sizeof(Person)
		ifs.read((char*)& p, sizeof(Person));               // tương tự khi write ta có thể dùng seekp(ut)  để xác định vị trí đối tượng cần write vào
		if (ifs.good()) {
			p.showInfo();
		}
        

        /* đọc hết tất cả
		while (!ifs.eof()) {                                // doc tu dau toi cuoi file
			ifs.read((char*)& p, sizeof(Person));           // đọc vào file binary và lưu vào p
			if (ifs.good()) {
				p.showInfo();
	    	}
		}
        */
	}

	return 0;
}