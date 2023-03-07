//2-8. increase.cpp
// 1차원 배열, 2차원 배열의 값을 증가시키는 함수 호출
#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 5
void increase(int *a, int size);
//void increase(int a[], int size);
void increaseArrayPtr(int* [], int);
void main(void)
{
	int a1[COL] = { 1,2,3,4,5 };
	int *end1;
	int *ap1;
	//a1 배열의 마지막 index 주소 저장
	end1 = a1 + COL - 1;
	//1번 주석 *******************************************
    //*
	printf("1번 주석\n\n");
	//a1 = a1 +1; //a1은 배열 주소를 나타내는 상수로서 증가 못함
	increase(a1, COL);
	printf("a1에 대한 increase() 호출 후\n");
	// for문에서 ap1++는 a1[0] -> a1[1] -> a1[2]로 만드는 연산이다.
	for (ap1 = a1; ap1 <= end1; ap1++) {
		// ap1에 저장된 주소에 해당하는 데이터 출력
		printf(" %d", *ap1);
	}
	printf("\n\n");

	//2번 주석 ***********************************************
	int a2[ROW][COL] = { {1,2,3,4,5}, {11,12,13,14,15}, {21,22,23,24,25} };

	//오류 *ap2는 정수형에 대한 pointer인데 a2는 2차원 배열이기 때문에 오류
	//int *ap2 = a2;//int (*)[5]의 값을 "int *"형식으로 초기화 못하는 오류   


	//ap2에 COL개의 열을 가지는 배열의 시작 주소를 저장
	int *ap2 = *a2;
	//int *ap2; ap2 = *a2;와 같은 연산이다. ap2는 0행의 시작주소를 가지게되고,
	// *ap2는 0행의 첫 원소 값을 가리키게 된다.

	int *end2 = *a2 + (ROW*COL) - 1;
	//*a2는 a2의 첫번째 행의 주소 값을 의미
	increase(*a2, ROW*COL);
	//increase(a2, ROW*COL);// int (*)[] 형식의 parameter가 int []와 호환되지 않는다
	printf("a2에 대한 increase() 호출 후\n");
	//for문에서 ap2++는 a2[0][0] -> a2[0][1] -> a2[0][2]로 만드는 연산이다.
	for (ap2 = *a2; ap2 <= end2; ap2++) {
		//ap2에 저장된 주소에 해당하는 데이터 출력
		printf(" %d", *ap2);
	}

	printf("\n");
	int a[2][3] = { 1,2,3,4,5,6 };
	int* b[2] = { a[0], a[1] };
	increaseArrayPtr(b, 2);
	printf("\n");
	//*/
	system("pause");
}
void increaseArrayPtr(int* x[], int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", *(x[i] + 1));
}
void increase(int a[], int size) {
	int *end;
	int *ap;
	end = a + size - 1;
	a = a + 1;//a는 a[] 모양이지마는 function에서는 pointer 변수로 간주된다.
	for (ap = a; ap <= end; ap++)
		*ap = *ap * 2;
	return;
}
/*
void increase(int *a, int size) {
	int *end;
	int *ap;
	end = a + size - 1;
	for (ap = a; ap <= end; ap++)
		*ap = *ap * 2;
	return;
}
*/