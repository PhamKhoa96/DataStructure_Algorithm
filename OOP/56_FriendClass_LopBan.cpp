  
/*
	Lớp bạn trong C++
*/

#include <iostream>
using namespace std;

class A;

class B {
public:
	void showA(A);
	void setAData(A&);
};

class A {
	int data;
	
public:
	A() {
		data = 100;
	}
	void show();
	friend class B;     //cho phép B làm bạn của A -> và B được quyền truy cập các thành phần của A
                        // cũng giống như function, khai báo friend class có thể đặt ở bất kì đâu trong class
};

void B::showA(A a) {
	cout << a.data << endl;
}

void A::show() {
	cout << data << endl;
}

void B::setAData(A& a) {
	a.data = 255;
}

int main() {

	A a;

	B b;
	b.showA(a); // hien thi du lieu goc
    a.show();

	b.setAData(a); // thay doi du lieu data cua doi tuong a thông qua doi tuong b
	b.showA(a);
    a.show();    // <- dữ liệu của a đã bị b thay đổi

	return 0;
}