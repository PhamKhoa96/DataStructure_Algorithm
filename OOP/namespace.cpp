/*
	Name space in c++:
	- cú pháp tổng quát:
		namespace name {
			...
		}
	- cho phép nhiều namespace có cùng tên đối tượng mong muốn
	- nhiều namespace có cùng tên vẫn được coi là hợp lệ (nó sẽ gom tất cả code của các namespace cùng tên này lại với nhau)
	- namespace chỉ được khai báo ở phạm vi toàn cục (không thể khai báo namespace ở class, function,...)
	- namespace không chứa các access modifiers
	- namespace có thể lồng nhau
	- sau ngoặc đóng của namespace } không cần có ;
*/

#include <iostream>
#include "NameSpaceExample.h"
using namespace std;            //có cái này ta mới dùng được cin, cout
using namespace example1;

namespace space1 {
	namespace s1 {
		int x;
		int a;

		void sayHello();

		class X {

		};
	}

	namespace s2 {          
		int x;
		int a;

		void sayHello() {                   // giữa các namespace khác nhau, ta có thể dùng trùng tên biến, hàm, class, ... 
			cout << "Hello" << endl;
		}

		class X {

		};
	}
}

void space1::s1::sayHello() {
	cout << "Hi!" << endl;
}

namespace space2 {
	const int X = 100;

	void sayHello();
}

void space2::sayHello() {
	cout << "Hi there!" << endl;
}

int main() {
    space1::s1::x = 255;
    cout << "space1::s1::x = " << space1::s1::x << endl;

    space1::s2::x = 240;
    cout << "space1::s2::x = " << space1::s2::x << endl;

    space1::s1::sayHello();
    space2::sayHello();

    //tạo ra 1 đối tượng thuộc class NameSpaceExample nằm trong namespace example1 và cấp phát động cho nó
	NameSpaceExample* ex = new NameSpaceExample();
    // nếu phía trên ta không ghi:      using namespace example1;    thì bên dưới này ta phải ghi đầy đủ là:
    // example1::NameSpaceExample* ex = new example1::NameSpaceExample();
    
	return 0;
}