//2-6. arr3.cpp - double pointer 사용: 실습에제 2.6
#include <stdio.h>
#include <stdlib.h>
void main()
{
	int A[3][4] = { {11,12,13,14},{21,22,23,24},{31,32,33,34} };
	//int *p = A; // error 'int (*)[4]'으로 'int *'을 초기화할  수 없다.
	int* p = *A; // *A= int[4], A= int[3][4], p= int *

	//주석1
	//*
	printf("------ 2차원 배열-------\n");
	printf("A: %p\n",A );
	printf("*A: %p\n",*A );
	printf("*(A+1): %p\n",*(A+1) );
	printf("*(*A+0): %d\n",*(*A+0) );
	printf("*(*A+1): %d\n",*(*A+1) );//*A+1은 행이 증가
	printf("**(A+1): %d\n",**(A+1) );//A+1은 row가 증가
	printf("**A: %d\n",**A);


	printf("\n------ 단일 pointer -------\n");
	printf("p: %p, *A: %p\n",p, *A);
	printf("(*(p+(4*0)+0)): %d\n",*(p+(4*0)+0)); // p[0]
	printf("(*(p+(4*0)+1)): %d\n",*(p+(4*0)+1)); // p[1]
	printf("(*(p+(4*0)+2)): %d\n",*(p+(4*0)+2)); // p[2]
	printf("(*(p+(4*0)+3)): %d\n",*(p+(4*0)+3)); // p[3]
	printf("(*(p+(4*1)+0)): %d\n",*(p+(4*1)+0)); // p[4]
	printf("(*(p+(4*1)+1)): %d\n",*(p+(4*1)+1)); // p[5]

	printf("p[0]: %d\n",p[0]); // *A[0]
	printf("p[1]: %d\n",p[1]); // *A[1]
	printf("p[4]: %d\n",p[4]); // *A[4]
	printf("p[5]: %d\n",p[5]); // *A[5]
	//*/


	// 주석2 이중pointer 활용
	//*
	printf("\n------ 이중 pointer: test = &p -------\n");
	int **test;
	//*test = *A;//variable 'test'가 초기화없이 사용할 수 없다
	test = &p;//test[][]처럼 사용하기 위한 초기화 방법
	printf("A: %p, p: %p, *test : %p\n", A, p, *test);
	printf("**test: %d\n",**test);
	printf("*(*test+(4*0)+0): %d\n",*(*test+(4*0)+0));
	printf("*(*test+(4*0)+1): %d\n",*(*test+(4*0)+1));
	printf("*(*test+(4*0)+2): %d\n",*(*test+(4*0)+2));
	printf("*(*test+(4*0)+3): %d\n",*(*test+(4*0)+3));
	printf("*(*test+(4*1)+0): %d\n",*(*test+(4*1)+0));
	printf("*(*test+(4*1)+1): %d\n",*(*test+(4*1)+1));
	printf("test[0][0]: %d\n",test[0][0]);
	printf("test[0][4]: %d\n\n",test[0][4]);
	//*/
	//주석3
	printf("\n------ 이중 pointer: p2 = &pt  -------\n");
	int* pt;
		int ar2[3][2] = { {1,2},{3,4},{5,6} };
	int** p2;  // a pointer to a pointer   
	pt = &ar2[0][0];
	//pt = ar2[0]; // both pointer-to-int
	//pt = ar2; // int (*)[3] 형식의 값을 int * 형식의 값으로 치환할 수 없다
	p2 = &pt;         // both pointer-to-int *
	*p2 = ar2[0];     // both pointer-to-int *
	(*p2)++;
	printf("**p2 = %d\n\n", **p2);
	//p2 = ar2; // int (*)[2] 형식의 값을 int ** 형식의 값으로 치환할 수 없다
	//*/
	system("pause");
}