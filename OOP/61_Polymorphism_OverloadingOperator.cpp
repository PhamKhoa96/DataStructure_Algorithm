/*
    tự định nghĩa ra kiểu toán tử riêng để sử dụng, và ta sử dụng toán tử này cho các Object tạo ra từ class ( kiểu như 2 class cộng nhau)

	Chồng toán tử: + - * / hai đa thức
	Những toán tử nào không thể nạp chồng?
	 . :: ?: sizeof
*/

#include <iostream>
using namespace std;

class PhanSo {
	int tu;
	int mau;
public:
	PhanSo() {
		tu = 0;
		mau = 1;
	}
	PhanSo(int a, int b) {
		tu = a;
		mau = (b == 0) ? 1 : b;
	}
	void showInfo() {
		cout << tu << "/" << mau << endl;
	}
	PhanSo operator + (PhanSo const&);                          // cách 1: sử dụng hàm thành phần (chỉ cần 1 tham số)            //kiểu trả về phải là kiểu của lớp chứa nó, ở đây là kiểu PhanSo
	PhanSo operator * (PhanSo const&);
	friend PhanSo operator - (PhanSo const&, PhanSo const&);    // cách 2: sử dụng hàm bạn (cần 2 tham số)
	friend PhanSo operator / (PhanSo const&, PhanSo const&);
};

PhanSo PhanSo::operator+(PhanSo const& b) {   // Cú pháp:    kieu_tra_ve Class::operator toán_tử ( 1 intput)     -> chỉ cần 1 input, nó sẽ tự động nạp chồng
	PhanSo s;
	s.tu = tu * b.mau + mau * b.tu;
	s.mau = mau * b.mau;
	return s;
}

PhanSo PhanSo::operator*(PhanSo const& b) {
	PhanSo s;
	s.tu = tu * b.tu;
	s.mau = mau * b.mau;
	return s;
}

PhanSo operator-(PhanSo const& a, PhanSo const& b) {        // Cú pháp:    kieu_tra_ve operator toán_tử ( 2 intput)     -> cần 2 input, do nó là hàm bạn
	PhanSo s;
	s.tu = a.tu * b.mau - a.mau * b.tu;
	s.mau = a.mau * b.mau;
	return s;
}

PhanSo operator/(PhanSo const& a, PhanSo const& b) {
	PhanSo s;
	s.tu = a.tu * b.mau;
	s.mau = a.mau * b.tu;
	return s;
}

int main() {

	PhanSo a(10, 3);
	PhanSo b(6, 9);
	PhanSo tong = a + b;
	PhanSo hieu = a - b;
	PhanSo tich = a * b;
	PhanSo thuong = a / b;

	tong.showInfo();
	hieu.showInfo();
	tich.showInfo();
	thuong.showInfo();

	return 0;
}