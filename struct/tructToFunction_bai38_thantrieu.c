#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *firstName;            //khi khai báo biến con trỏ firstName thì ý là con trỏ firstName được tạo ra để lưu địa chỉ của 1 nơi nào đó trong bộ nhớ
    char *lastName;             //nhưng nếu nơi này chưa được cấp phát bộ nhớ thì ta không thể điền nội dung vào nơi này 
                                //-> ta không thể truy cập vào nội dung tại địa chỉ mà con trỏ lưu trữ
                                //-> vì vậy ta phải cấp phát bộ nhớ tại nơi mà con trỏ trỏ tới để có thể lưu trữ nội dung tại đây -> dùng calloc, malloc
                                //và sau đó thì ta mới có thể truy cập nội dung tại địa chỉ mà con trỏ lưu giữ
                           
    int age;                    //khi khai báo biến bình thường thì HĐH sẽ tạo ra 1 vùng nhớ để lưu trữ nội dung của biến đó
                                //-> ta không cần phải cấp phát bộ nhớ cho biến này nữa
} Person;

void getPerson(Person *p){
    p->firstName = malloc(50*sizeof(char));     //Cấp phát bộ nhớ động cho nơi mà con trỏ p trỏ tới, thì khi đó tại nơi này ta mới lưu giá trị được
    p->lastName = malloc(50*sizeof(char));      //Cấp phát bộ nhớ động cho nơi mà con trỏ p trỏ tới, thì khi đó tại nơi này ta mới lưu giá trị được
    
    printf("\nEnter your firstName:");
    scanf("%s", p->firstName);                  // input của hàm scanf phải là 1 địa chỉ
                                                // p->firstName vừa là địa chỉ, vừa là nội dung
                                                /*  
                                                thứ nhất, nếu ta đứng nhìn từ firstName: là 1 địa chỉ vì đây là kiểu diaChiA->diachiB (bản chất ta lấy địa chỉ mà diaChiB lưu trữ từ diachiA))
                                                thứ hai, nếu ta đứng nhìn từ p: là 1 nội dung vì đây là kiểu diaChiA->NoiDungB (ta đang lấy nội dung mà diaChiA trỏ tới)
                                                */
                                                // hàm scanf sẽ đưa nội dung mà ta nhập vào để điền vô nội dung tại địa chỉ input
    printf("p->firstName trong scanf va printf deu GIONG NHAU vi p->firstName vua la dia chi vua la noi dung: %s", p->firstName);

    printf("\nEnter your lastName:");
    scanf("%s", p->lastName);

    printf("Enter your age: ");
    scanf("%d", &(p->age));                     // ta lấy địa chỉ tại biến age (đây là kiểu contro->Noidung và ta lấy địa chỉ của nội dung này:  &(contro->Noidung)   )
// hoặc scanf("%d", &p->age);                   // &(contro->Noidung) có thể được viết thành &contro->Noidung
    printf("&(p->age) trong scanf va printf KHAC NHAU vi p->age la noi dung va &(p->age) la dia chi: %d", &(p->age));
}

void showInfo(Person person){
	printf("\nPerson info: \nFirst Name: %s\nLast Name: %s\nAge: %d\n",
		person.firstName, person.lastName, person.age);                 // person.firstName là lấy ta nội dung tại địa chỉ mà con trỏ firstName lưu trữ  (kiểu person.ten_contro)
                                                                        // person.age là lấy nội dung tại biến age                                       (kiểu person.ten_bien)
                                                                        // ------> cả 2 đều là lấy nội dung
                                                                        // (nhưng nhớ, input của printf có thể là nội dung hoặc địa chỉ đều được) 
}

void modify(Person *p){
    p->firstName ="Nhan";               // lấy "nội dung firstName" mà "địa chỉ của con trỏ p lưu trữ" trỏ tới
}

void main(){
    Person person;
    getPerson(&person);

    printf("\n\nBefore modify: ");
    showInfo(person);

    modify(&person);

    printf("\nAfter modify: ");
    showInfo(person);

}