/*
	Vector trong C++: kích thước vector sẽ tự co dãn để phù hợp với nhu cầu của ta -> linh hoạt hơn cấp phát động và mảng, linkedlist
	- size();
	* truy cap phan tu:
	- at(position);
	- front();
	- back();
	* sua doi vector:
	- push_back();
	- pop_back();
	- insert(position, value);
	- clear(); 
	- erase(position); or erase(from, to);
	- assign(size, value);
    - end() : chạy đến ngay sau phần tử cuối cùng
*/
#include <iostream>
#include <vector>
using namespace std;

void showInfo(vector<int> v) {
	for (auto i = v.begin(); i != v.end(); i++) {       // i ở đây là iterator
		cout << *i << endl;
	}
}

int main() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(80);
	v1.push_back(50);

	cout << "Size: " << v1.size() << endl;
	cout << "First element: " << v1.front() << endl;
	cout << "Last element: " << v1.back() << endl;
	cout << "element at position 2: " << v1.at(2) << endl;
    cout << "\n===========================\n";

	showInfo(v1);
	v1.insert(v1.begin()+2, 666);

	cout << "\n===========================\n";
	showInfo(v1);

	v1.assign(2, 0);            // gán vetor thành vetor chứa 2 phần tử có giá trị = 0
	cout << "\n===========================\n";
	showInfo(v1);

	return 0;
}