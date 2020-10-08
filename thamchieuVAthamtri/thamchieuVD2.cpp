#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
	int c = b;
	b = a;
	a = c;
}

int main() {

	int a = 1, b = 2;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b;

	return 0;
}