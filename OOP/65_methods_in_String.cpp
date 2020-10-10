  
/*
	Các phương thức thường sử dụng của lớp string
	- append(stringToAppend): string                    (nối 1 string với 1 string khác, string gốc ban đầu cũng sẽ biến thành string mới)
	- compare(otherString): int                         (trả về 0 khi giống nhau, khác 0 khi khác nhau)
	- clear(): void                                     (xóa chuỗi, kiểm tra độ dài chuỗi sẽ thấy = 0 sau khi xóa)
	- c_str(): const char*                              (chuyển string đang mảng kí tự)
	- empty(): bool                                     (kiểm tra string có rỗng không)
	- erase(from, numberCharacterToDelete): string      (xóa bỏ số kí tự từ vị trí cho trước)
	- find(stringToFind): int                           (tìm chuỗi có nằm trong chuỗi gốc không, trả về vị trí đầu tiên mà chuỗi cần tìm xuất hiện trong chuỗi gốc)
	- find_first_of(stringToFind): int                  
	- find_last_of(stringToFind): int
	- insert(position, stringToInsert): string
	- substr(from, lengthOfSubString): string           (trích xuất chuỗi)
	- ...
*/

#include <iostream>
using namespace std;

int main() {
	string s = "3.1415926535";
	string f = "";
	int pos = s.find(".");
	f = s.substr(pos + 1);
	cout << f << endl;

	return 0;
}