#include <stdio.h>
#include <stdlib.h>

struct Person{
	char from[50];
	char to[50];
};

int main()
{
	struct Person myLetter;

    printf("%d", myLetter);    
	printf("\nAddress of myLetter: %d", &myLetter);
    printf("\nAddress of from field: %d", &myLetter.from);          //địa chỉ của trường dữ liệu đầu tiên trong một biến struct cũng là địa chỉ của biến struct đó (khá giống với mảng)
                                                                    //nhưng lưu ý trong mảng thì arr tương đương với &arr, nhưng trong struc thì myLetter KHÔNG tương đương &myLetter
    printf("\nAddress of to field: %d", &myLetter.to);
	
	return 0;
}