//2-7. arr4.cpp
//array of pointers의 초기화 사용
#include <stdio.h>
#include <stdlib.h>

void main(){

	int b[10]={1,2,3,4,5,6,7,8,9,10};
	int *q[5];

	//q = b; //q는 lvalue가 아니다. q는 배열이며 각 원소가 pointer이다.
	//q 변수 타입: int*[6], b 변수 타입: int[10]

	// 주소값
	q[0] = b; // q[0] 변수 타입: int *, b 변수 타입: int[]
	q[1] = b+2;
	q[2] = b+4;
	q[3] = b+6;
	q[4] = b+8;
	//q[3][2] = b; //'int *'에서 'int'로 변환할 수 없다.
	q[3][2] = 55;

	printf("b: %p, q[0]: %p, q[1]: %p, q[2]: %p, q[3]: %p\n", b, q[0], q[1], q[2], q[3]);

	printf("*q[0]: %d\n", *q[0]);
	printf("*q[1]: %d\n", *q[1]); 
	printf("*q[2]: %d\n", *q[2]);
	printf("*q[3]: %d\n", *q[3]);
	printf("*q[4]: %d\n", *q[4]);
	printf("q[3][2]: %d, q[4][0]: %d\n", q[3][2], q[4][0]);//같은 값이 인쇄되는 이유를 이해하는 것 필요
	system("pause");
}