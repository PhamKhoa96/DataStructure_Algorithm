/*
	Override: định nghĩa lại
*/
#include <iostream>
using namespace std;

class Animal {
public:
	virtual void move() {                           // dùng keyword virtual đưa ra phương thức tổng quát để áp dụng cho các lớp con nhưng không thể áp dụng cụ thể được
		cout << "Animal is moving..." << endl;
	}
};

class Bird : public Animal {
public:
	void move() override {                          // cú pháp overide method từ lớp cha sang lớp con
		cout << "Bird is flying..." << endl;        // các hàm giống lớp cha trong lớp con thì phải có cùng kiểu và thứ tự các tham số, cũng như kiểu trả về y như trong lớp cha
	}
};

class Fish : public Animal {
public:
	void move() override {
		cout << "Fish is swimming..." << endl;
	}
};

class Cat : public Animal {
public:
	void move() override {
		cout << "Cat is running on the ground..." << endl;
	}
};

int main() {
	Animal* a;
    a = new Bird();
	a->move();          // tùy vào đối tượng tham chiếu thuộc class nào thì nó sẽ gọi hàm move của class đó
	
	a = new Fish();
	a->move();

	a = new Animal();
	a->move();

	a = new Cat();
	a->move();

	return 0;
}