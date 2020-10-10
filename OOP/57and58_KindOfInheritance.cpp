/* CÁC LOẠI ACCESS MODIFIER INHERITANCE
khả năng truy cập giảm dần theo thứ tự : public -> protected -> private

từ lớp cha sang lớp con, nếu access modifier được định nghĩa là:
	public:        private trong lớp cha giữ nguyên trong lớp cha, không bị di chuyển xuống lớp con. public, protected trong lớp cha  bị hạ xuống thành public, protected trong lớp con
	protected:     private trong lớp cha giữ nguyên trong lớp cha, không bị di chuyển xuống lớp con. public, protected trong lớp cha  bị hạ xuống thành protected trong lớp con
	private:       private trong lớp cha giữ nguyên trong lớp cha, không bị di chuyển xuống lớp con. public, protected trong lớp cha  bị hạ xuống thành private trong lớp con

(lưu ý là trong tất cả các TH thì private trong lớp cha vẫn được giữ nguyên trong lớp cha, không bị di chuyển xuống lớp con. 
nghĩa là thành phần private của class nào thì class đó quản lý, ta chỉ có thể truy cập đến thành phần private của lớp đó thông qua thành phần public và protected của lớp đó)
*/

#include <iostream>
using namespace std;

class Father {
private:
	string name;
protected:
	string address;
public:
	string email;
	Father() {
		cout << this << endl;
	}
};

class Father2 : public Father{      

};

class Father3 : public Father2{     // ta có thể thực hiện kế thừa liên tiếp, kiểu: ông -> bố -> con -> cháu -> ...

};

class Children : private Father{      // access modifier là private nên 
private:
	string toy;
public:
	Children() {
		cout << this << endl;
	}
	Children(string);
	Children(string, string, string, string);
	void showInfo();
};

void Children::showInfo() {         // do đây là hàm public trong lớp con nên nó có thể truy cập đến tất cả các thành phần của lớp con
	toy = "Tedy";                   // ngoài ra, do access modifier là private nên public, protected trong lớp cha  bị hạ xuống thành private trong lớp con
	address = "New York";           // nên ta có thể truy cập được các thành phần public, protected trong lớp cha luôn
	email = "abc@xmail.com";
    // name = "Khoa";    bị lỗi vì private trong lớp cha giữ nguyên trong lớp cha, không bị di chuyển xuống lớp con. Nghĩa là thành phần private của class nào thì class đó quản lí, muốn truy cập thì phải thông qua các thành phần public hoặc protected của lớp đó
}

class X : public Children{
public:
    void show();
};

void X::show(){
    //cout << address << endl;       ta sẽ bị lỗi vì address lúc này khi từ class Father xuống class Children đã biến thành thành phần private của class Children. Cho nên con của Children là X không thể truy cập tới thành phần private của class Children được
}                                    // muốn truy cập được thì ta có thể sửa access modifier của Father xuống Children thành public hoặc protected

int main() {
	Children c;
	return 0;
}


/*
TÍNH CHẤT CỦA CÁC THÀNH PHẦN

public: ai cũng có thể truy cập
protected: chỉ trong class đó và class con của nó được truy cập
private: chỉ class đó được phép truy cập thông qua thành phần public của class đó (ngoại trừ TH dùng hàm bạn)
*/
