// 2¿Â-5 swap.cpp
#include <stdio.h>
#include <stdlib.h>
// prototype declaration
//void swap(int, int);
void swap(int&, int&);
void main(void){
    int a, b;
    a = 1;b = 2;
	printf("Before swap(), a = %d, b = %d\n", a, b);
    swap(a, b);
	printf("After swap(), a = %d, b = %d\n\n", a, b);
	system("pause");
}
/* 
void swap(int x, int y){ //call by value
    int temp;
    temp = x;
    x = y;
    y = temp;
}
*/
void swap(int &x, int &y) {//call by reference
	int temp;
	temp = x;
	x = y;
	y = temp;
}