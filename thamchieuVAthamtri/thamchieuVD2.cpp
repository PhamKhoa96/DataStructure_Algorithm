#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {				// đây là cách ghi theo kiểu của C++, nhưng không áp dụng được cho C
	int c = b;
	b = a;
	a = c;
}

int main() {

	int a = 1, b = 2;
	cout << a << " " << b << endl;
	swap(a, b);							// đây là cách ghi theo kiểu của C++, nhưng không áp dụng được cho C
	cout << a << " " << b;

	return 0;
}