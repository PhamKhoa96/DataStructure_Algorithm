/*
	Đa hình trong C++ : 1 object tạo ra có nhiều vai trò
	- Đa hình tại thời điểm biên dịch hay compile time polymorphism:
	  Thể hiện ở việc nạp chồng hàm, nạp chồng toán tử.

	- Đa hình tại thời điểm chương trình chạy hay runtime polymorphism:
	  Thể hiện ở việc ghi đè các phương thức của lớp cha.

	- Lesson 60: function overloading   (nạp chồng hàm)
	- Lesson 61: operator overloading   (nạp chồng toán tử)
	- Lesson 62: function overriding    (ghi đè)
*/

#include <iostream>
using namespace std;

class Caculator {
public:
	int sum(int a, int b) {
		return a + b;
	}

	float sum(float a, float b) {
		return a + b;
	}

	long sum(long a, long b) {
		return a + b;
	}

	float sum(int a, float b) {
		return a + b;
	}

	float sum(float a, int b) {
		return a + b;
	}

	int sum(int* a, size_t size) {
		int s = 0;
		for (size_t i = 0; i < size; i++)
		{
			s += a[i];
		}
		return s;
	}
};

class Payment {
public:

};

int main() {
	Caculator c;
	cout << c.sum(100, 200) << endl;            // truyền vào tham số loại nào thì nó sẽ biết gọi tới hàm tương ứng được khai báo trong class
	cout << c.sum(100, 25.25f) << endl;
	cout << c.sum(25.0f, 30.0f) << endl;
    int a[] = {1, 2, 3, 4, 5, 6};
    cout << c.sum(a, sizeof(a)/sizeof(int)) << endl;
	return 0;
}