/*
	****** struct trong ngon ngu C *****
	-su dung keyword typedef
*/
#include<stdio.h>
#include<stdlib.h>

/*Cách 1:
struct Person{
	char *firstName;
	char *lastName;
	int age;
};
typedef struct Person biet_danh

biet_danh person1
*/

//Cách 2:
typedef struct {
	char *firstName;
	char *lastName;
	int age;
} biet_danh /* p1, p2, *ptr, px[] */;

int main(){
	biet_danh person={
		"Hoa", "Nguyen", 20
	};
	
	biet_danh *ptr, x[100], hhh;
	
	// gan gia tri cho bien thanh phan cua struct
//	person.firstName= "Hoa";
//	person.lastName= "Nguyen";
//	person.age= 20;

	
	printf("\nPerson info: \nFirst Name: %s\nLast Name: %s\nAge: %d",
		person.firstName, person.lastName, person.age);		
	
	return 0;
}