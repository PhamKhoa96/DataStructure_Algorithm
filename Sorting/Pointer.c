#include <stdio.h>

int main ()
{
   int  bien = 20;   /* phan khai bao bien thuc su */
   int  *contro = &bien;        /* phan khai bao bien con tro */

   //contro = &bien;  /* luu tru dia chi cua bien trong con tro */

   printf("Dia chi cua bien la: %x\n", &bien  );

   /* dia chi duoc luu tru trong bien con tro */
   printf("Dia chi duoc luu tru trong bien contro la: %x\n", contro );

   /* Truy cap gia tri boi su dung con tro */
   printf("Gia tri cua bien *contro la: %d\n", *contro );
   
   printf("\n===========================\n");
   printf("VietJack chuc cac ban hoc tot! \n");

   return 0;
}