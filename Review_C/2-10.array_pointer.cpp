//2-10. array_pointer.cpp - function pointer를 array로 선언: 실습예제 2.10
#include <stdio.h>
#include <stdlib.h>
//두 정수의 합을 구하는 함수
int plus(int i, int j) {return i+j;}	
//두 정수의 차를 구하는 함수
int minus(int i, int j) {return i-j;}	

//주석 3
/*
//두 정수의 곱을 구하는 함수
int multiply(int i, int j) { } 
//두 정수의 나누기를 구하는 함수
int division(int i, int j) { } 
*/

int main (){
    int x = 10, y = 5;
    //함수 pointer 선언
    int (*p)(int, int)=0;
    
    printf("1. 실습결과\n");
    printf("-----------\n");
    printf("*p가 가리키는 주소가 없는 경우 출력 결과\n");
    printf("*p 출력 값: %p\n", *p);

    //함수 pointer에 plus()함수 주소값 reference
    p = &plus; 
    printf("*p가 plus()함수의 주소값 reference 후 출력 결과\n");
    printf("*p 출력 값: %p\n", *p);

    //주석 1
    
    // plus()함수 주소값을 reference
    printf("(*p)(x, y) 출력 값: %d\n", (*p)(x, y)); 
    // plus()함수 주소값을 reference
    printf("p(x, y) 출력 값: %d\n", p(x, y)); 
    // plus()함수 주소값을 reference
    printf("(*******p)(x, y) 출력 값: %d\n\n", (*******p)(x, y));
    printf("\n\n\n");
	
    //주석 2
   
    //함수 pointer 배열 초기화
    int (*ap[2])(int, int) = {plus, minus};
    printf("*ap[2])(int, int) 함수 pointer 배열 선언 후 출력 결과\n");
    // plus() 실행
    printf("ap[0](x,y)출력 값: %d\n", ap[0](x, y)); 
    // plus() 실행
    printf("(*****ap[0])(x,y)출력 값: %d\n",(*****ap[0])(x, y));
    //minus() 실행
    printf("(*ap[1])(x,y)출력 값: %d\n\n", (*ap[1])(x, y)); 
    
	system("pause");
}