//2-4. pointer_array.cpp: 실습예제 2.4
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // ******************배열 pointer******************
    //1차원 배열 선언 및 초기화
    int a1[4] = {11,12,13,14};
    //2차원 배열 선언 및 초기화
    int a2[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};  

    // 1차원 배열에 대한 pointer 선언
    int *ap1 = a1;  
    //4개의 열을 가지는 배열을 가리키는 array to pointer 선언
    int (*ap2)[4];
    ap2 = a2; 
    //*ap2 = a2; // *ap2는 배열 [5]을 가리키는 배열 이름 상수로 간주, lvalue가 아니다.
    //*ap2 = *a2; // 왼쪽 피연산자는 l-value이어야 합니다.
	*ap2[0] = 100;//*ap2는 lvalue가 아니지마는 *ap2[0]은 lvalue이다

    // int *ap3; ap3 = *a2;와 같은 연산이다. ap3은 row 0의 시작주소를 갖는다.
    int *ap3 = *a2; //다음 row
    int *p = (*a2+1); //다음 column
	//int *q[3] = a2; //q는 array이므로 초기화하기 위한 {..}이 필요하다.
    int (*q)[4] = a2; //q는 pointer to array이므로 배열 상수 이름으로 초기화 가능
	
	//1번 주석
    //*
	printf("a2 = %p, ap3 = %p, p = %p\n", a2, ap3, p);
    //pointer-o-array를 이용한 접근
    //배열명과 pointer-to-array로 access하는 것이 같다.

    printf("\n\n 배열명과 pointer를 사용한 접근:\n"); 
    printf("a1[0] : %d\n",a1[0]);
    // 배열의 주소를 가지고 있는 pointer로 선언된 변수 ap1를 배열 형태와 같이 
    //   사용하여 0번 째에 해당하는 배열 원소의 값을 가져올 수 있다.
    printf("ap1[0] : %d\n",ap1[0]); 
    printf("*a1 : %d\n",*a1);//a1++는 허용되지 않는다
    printf("*ap1 : %d\n",*ap1++); //ap1++는 가능
	printf("*ap1++ : %d\n",*ap1);

	printf("\n Array a2[][]에 대한 연산\n");
    printf("a2[0][0] : %d\n",a2[0][0]);
    printf("ap2[0][0] : %d\n",ap2[0][0]);
    printf("**a2 : %d\n",**a2);
    printf("**ap2 : %d\n",**ap2);
    printf("ap3[1] : %d\n",ap3[1]);
    printf("*p : %d\n",*p);
    printf("*(p+1) : %d\n",*(p+1));
    printf("*q : %p\n",*q);
    printf("*q[0] : %d\n",*q[0]);
    //*/

	//2번 주석
    //*
    printf("\n\n2번 주석\n\n");
	printf("a1 = %p, ap1 = %p\n", a1, ap1);
	printf("a2 = %p, ap2 = %p, ap3 = %p\n", a2, ap2, ap3);
    printf("ap1++  ap2++  ap3++ 실행 전\n");
    printf("*ap1 = %d\n",*ap1); 
    printf("**ap2 = %d\n",**ap2);
    printf("*ap3 = %d\n",*ap3);
    ap1++;
    ap2++;//다음 row?
    ap3++; // 다음 column으로 이동?
    printf("\nap1++  ap2++  ap3++ 실행 후\n");
	printf("a1 = %p, ap1 = %p\n", a1, ap1);
	printf("a2 = %p, ap2 = %p, ap3 = %p\n", a2, ap2, ap3);
    printf("*ap1 = %d\n",*ap1);
    printf("**ap2 = %d\n",**ap2);
    printf("*ap3 = %d\n",*ap3);
    //*/
	system("pause");
}