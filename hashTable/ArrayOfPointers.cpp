#include <stdio.h>


#define SIZE 20

struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE]; // khi tạo ra 1 mảng con trỏ, nếu các con trỏ này chưa trỏ tới đâu thì mặc định các con trỏ này sẽ trỏ tới NULL

void display(){
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

int main(){

    display();

    return 0;
}