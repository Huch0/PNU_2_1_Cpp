// 2장-6 swap2.cpp
#include <stdio.h>
#include <stdlib.h>
//prototype declaration
void swap(int *, int *);
void main(void){
    int a, b;
    a = 1; b = 2;
	printf("After swap(), a = %d, b = %d\n", a, b);
    swap(&a, &b);
	printf("After swap(), a = %d, b = %d\n\n", a, b);
	system("pause");
}
void swap(int *x, int *y){   
    int temp;
    //*x는 dereferencing을 나타냄
    temp = *x;
    *x = *y; 
    *y = temp;
}