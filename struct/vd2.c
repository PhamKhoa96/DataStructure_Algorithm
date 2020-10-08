#include <stdio.h>
#include <string.h>
 
struct Books
{
   char  tieude[50];
   char  tacgia[50];
   char  chude[100];
   int   id;
};

void inthongtinsach( struct Books book )
{
   printf( "Tieu de sach: %s\n", book.tieude);
   printf( "Tac gia: %s\n", book.tacgia);
   printf( "Chu de: %s\n", book.chude);
   printf( "Book ID: %d\n", book.id);
}

/* khai bao ham */
int main( )
{
   struct Books Book1;        /* Khai bao Book1 la cua kieu Book */
   struct Books Book2;        /* Khai bao Book2 la cua kieu Book */
 
   /* thong tin chi tiet quyen sach thu nhat */
   strcpy( Book1.tieude, "Lap trinh C");
   strcpy( Book1.tacgia, "Pham Van At"); 
   strcpy( Book1.chude, "Ngon ngu lap trinh C");
   Book1.id = 1234567;

   /* thong tin chi tiet quyen sach thu hai */
   strcpy( Book2.tieude, "Toi thay hoa vang tren co xanh");
   strcpy( Book2.tacgia, "Nguyen Nhat Anh");
   strcpy( Book2.chude, "Van hoc");
   Book2.id = 6677028;
 
   /* hien thi thong tin Book1 */
   inthongtinsach( Book1 );

   /* hien thi thong tin Book2 */
   inthongtinsach( Book2 );
   
   printf("\n===========================\n");
   printf("VietJack chuc cac ban hoc tot! \n");

   return 0;
}
