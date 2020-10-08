/*
	****** struct trong ngon ngu C *****
	-dinh nghia
	-khai bao bien struct
	-cach truy cap du lieu thanh phan
	-cac toan tu hop le voi kieu struct
	-vi du minh hoa
*/
#include<stdio.h>

//dinh nghia struct ten la Person
struct Person{
	char *firstName;    //dung kieu con tro de luu duoc nhieu ki tu
	char *lastName;     //dung kieu con tro de luu duoc nhieu ki tu
	int age;
}/* p1, p2, *ptr, px[] */;

int main(){
	
	struct Person person, *personPtr;

    //Gán giá trị cho biến kiểu gián tiếp
	person.firstName = "Hoa";		//lúc đầu firstName chỉ là một biến con trỏ, ta không thể ghi nội dung cho nơi mà cho con trỏ này trỏ tới được khi chưa cấp phát bộ nhớ cho nơi đó
									//nhưng khi ta làm động tác gán giá trị này, thì nơi mà con trỏ firstName trỏ tới được cấp phát bộ nhớ để ghi nội dung, và nội dung này là "Hoa"
	person.lastName = "Nguyen";
	person.age= 20;
  
	// bien thuong: .
	printf("\nPerson info: \nFirst Name: %s\nLast Name: %s\nAge: %d",
		person.firstName, person.lastName, person.age);
		
	// bien con tro struct: ->
	personPtr = &person;
	printf("\n\nPerson info, display using pointer: "
		"\nFirst Name: %s\nLast Name: %s\nAge: %d",
		personPtr->firstName, personPtr->lastName, personPtr->age);			//personPtr->firstName và personPtr->lastName vừa là địa chỉ vừa là nội dung
																			//personPtr->age là nội dung

    //Gán giá trị cho biến kiểu trực tiếp
    struct Person person2={ "Dang", "Khoa", 25};
    printf("\nPerson2 info: \nFirst Name: %s\nLast Name: %s\nAge: %d",
	person2.firstName, person2.lastName, person2.age);


	int size = sizeof(person);
	
	printf("\n\nkich thuoc bien person= %d", size);// lay kich thuoc bien struct
	return 0;
}