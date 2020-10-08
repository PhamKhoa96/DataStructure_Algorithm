#include <stdio.h>

void main(){
    char *ptr;

    ptr = "hahahahah";

    printf("%s\n", ptr);
    printf("%d\n", *ptr); 
    printf("%d\n", &ptr);
}