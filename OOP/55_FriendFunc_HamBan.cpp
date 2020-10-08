/*
	Hàm bạn trong C++ : giúp ta truy cập đến các giá trị private của class, nhưng nó không thuộc class như các method ở public
                        hàm bạn có thể là hàm của 1 class hoặc nhiều class dùng chung
                        hàm bạn có ý nghĩa 1 chiều
                        X là bạn của Y thì X có quyền truy cập dữ liệu của Y nhưng không có điều ngược lại
    Hàm bạn có thể là hàm bình thường
    hoặc có thể là 1 method của lớp khác

    Hạn chế sử dụng Friend func, chỉ sử dụng khi cần thiết, nếu không ta sẽ phá vỡ tính Encapsulation 
    sử dụng khi, VD: muốn test dữ liệu trong 1 class,...
*/

#include <iostream>
using namespace std;

class A;                // khai báo class A trước để class B biết class A là cái gì, nếu không sẽ lỗi vì ta khai báo A sau B mà ta đã sử dụng class A trong B

class B {
public:
	void showA(A);      // do Class A đã được khai báo bên dưới nên sẽ không lỗi
                        // class B dùng hàm friend trong class A, nên B có thể truy cập các thuộc tính của A
};

class A {
	friend void setData(A&);         //có thể đặt hàm bạn ở bất kì vị trí nào trong class
	int data;                        //nhận tham chiếu từ bên ngoài

public:
	A() {       //constructor
		this->data = 100;
	}
	void show();
	friend void B::showA(A);
};

void B::showA(A a) {
	cout << a.data << endl;
}

void A::show() {
	cout << data << endl;
}

void setData(A& a) {                // ta cần phải tạo đối tượng a thì mới truy cập được vào dữ liệu của class thông qua đối tượng đó
	a.data = 255;                   // lưu ý là cần phải truyền tham chiếu vào vì hàm này không phải là 1 method của A mà nó là hàm bên ngoài, và trong A nó chỉ được khai báo là hàm bạn
}

int main() {

	A a;
	setData(a);
    a.show();

	B b;
	b.showA(a);                     // class B dùng hàm friend trong class A, nên B có thể truy cập các thuộc tính của A

	return 0;
}