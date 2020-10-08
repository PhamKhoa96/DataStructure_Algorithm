#include<iostream> 
using namespace std; 

/*
https://www.geeksforgeeks.org/malloc-vs-new/
https://www.youtube.com/watch?v=UjjFY0neCiI&list=PLE1qPKuGSJaBq4VFzTYrhzCiPvCoI8JDv&index=61
*/
/*
  new (chỉ có trong C++)            malloc
 1. Gọi hàm khởi tạo                Không gọi hàm khởi tạo
 2. Là một toán tử                  Là một hàm
 3. Có thể overrride                Không thể override
 4. Cấp phát bộ nhớ từ vùng         Cấp phát bộ nhớ từ heap
    nhớ trống     
 5. Việc tính toán lượng bộ         Việc tính toán bộ nhớ cần cấp phát thực
    nhớ cần cấp phát được thực      hiện thủ công   -> ta phải input giá trị bộ nhớ
    hiện tự động bở compiler  
 6. Trả về chính xác kiểu dữ        Trả về void*   (con trỏ kiểu void)
    liệu cần cấp phát
 7. Khi cấp phát thất bại xảy       Cấp phát thất bại trả về NULL
    ra ngoại lệ (exception error)
*/


int main() 
{ 
    // Initialization with new() 
    int *n = new int(10);  //-> gọi hàm khởi tạo để khởi tạo giá trị được lưu trong ô nhớ mà contro n trỏ tới là 10
    cout << "value: "<< *n <<endl; 
 
    return 0; 
} 