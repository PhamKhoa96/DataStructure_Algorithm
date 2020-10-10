/*
	auto keyword: có từ phiên bản C++11 trở lên
    khi được gán auto thì chương trình sẽ tự suy luận kiểu của biến nếu được ta gán giá trị
*/
#include <iostream>
using namespace std;

auto showInfo() {
	// ..
}

auto isOk(int x) {          // tự suy luận ra kiểu trả về là boolean
	if (x < 5) {
		return true;
	}
	return false;
}

int main() {
	auto x = 0;             // tự suy luận là kiểu int
	auto y = 1.25f;         // tự suy luận là kiểu float
	auto z = 2.56;          // tự suy luận là kiểu double

    cout << "Kieu cua bien z: " << typeid(z).name() << endl; 
    cout << "Kieu tra ve cua ham isOk: " << typeid(isOk(6)).name() << endl;  
	cout << "Kieu tra ve cua ham showInfo: " << typeid(showInfo()).name() << endl;       

	return 0;
}