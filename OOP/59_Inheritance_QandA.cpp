/*
	Q&A: - Lớp con kế thừa lại những gì từ lớp cha?
		 - Khi tạo đối tượng lớp con thì nó có tạo đối tượng lớp cha không?
		 - Mối quan hệ giữa lớp cha-lớp con còn được diễn đạt như thế nào?
		 - Lớp cha còn có tên gọi nào khác?
		    + Parent, super, base class.
		 - Lớp con còn có tên gọi nào khác không?
		    + Sub class, delivered class, child class, heir class
*/

#include <iostream>
using namespace std;

class Father {
public:
	Father() {
		cout << this << endl;
	}
};

class Child : public Father {
public:
	Child() {
		cout << this << endl;
	}
};

int main() {
	Child child;        // khi tạo ra object từ lớp con thì có thông qua lớp cha -> in 2 địa chỉ giống nhau -> là 1 địa chỉ chỉ đến cùng 1 vùng nhớ

    Father father;      // khi tạo ra object từ lớp cha thì không cần thông qua lớp con -> in 1 địa chỉ
	return 0;
}

/*
kết quả cho thấy 2 địa chỉ in ra giống nhau
tức là lớp con tạo ra đối tượng và đối tượng này chứa những thuộc tính access modifier kế thừa
chứ lớp cha không tạo ra đối tượng mới
*/