biến con trỏ là biến lưu trữ địa chỉ của 1 ô nhớ

Thật ra viết (int* x;) sẽ làm ta dễ hiểu hơn là viết (int *x;)
 
2 cách viết này giống nhau và cùng có ý là: ta khởi tạo x là kiểu con trỏ int (con trỏ trỏ tới ô nhớ lưu trữ số nguyên)


VÌ
thứ nhất:ta thường gán x = &value, nên cách viết thứ nhất sẽ giúp ta đỡ hiểu nhầm hơn khi viết tắt 
từ
	int *x;
	x = &value;
sang
	int *x = &value; (ta có thể hiểu là: int* x=&value; để match với cách viết bên trên)

thứ hai: ta thường làm
int* p;
p = (int*) malloc(sizeof(int));          ------> vì output của hàm malloc (hay calloc) là con trỏ kiểu void (kiểu void*)       --------  khác với new, new thì trả vể con trỏ có kiểu dữ liệu cần cấp phát (đó là lý do mà khi dùng new ta phải khai báo kiểu dữ liệu)
					 ------> ta ép kiểu output của hàm malloc thành kiểu con trỏ int bằng cách thêm (int*) vào (mặc dù có thể không cần ép kiểu vẫn được nhưng ta làm vậy cho chắc ăn)