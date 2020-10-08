#include <bits/stdc++.h>
using namespace std;

int congMot(int a) {
	a++;
	return a;
}

int congHai(int a) {
	a += 2;
	return a;
}

int main() {

	int a = 1;
	cout << a << endl;
	cout << congMot(a) << " " << congHai(a) << endl;
    cout << a << endl;

	return 0;
}