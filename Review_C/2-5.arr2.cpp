//2-5. arr2.cpp: 실습 예제 2.5
#include <stdio.h>
#include <stdlib.h>
//배열 이름에 대하여 pointer 표현식을 사용하여 접근
void main()
{
    //1차원 배열 선언 및 초기화
    int a1[5] = {5, 4, 3, 2, 1}; 
    //2차원 배열 선언 및 초기화
    int a2[3][5] = {{0, 5, 10, 15, 20},{1, 6, 11, 16, 21},{2, 7, 12, 17, 22}};  

    //1번 주석
   
    printf("1번 주석\n");
    printf("\n일반적인 배열 접근 방법과 pointer를 이용한 배열 접근 방법 비교\n");
    printf("\n1차원 배열\n");
    printf("a1[0] = %d\n", a1[0]);
    printf("*(a1) = %d\n\n", *(a1));
    printf("a1[1] = %d\n", a1[1]);
    printf("*(a1+1) = %d\n\n", *(a1+1));
    printf("\n2차원 배열\n");
    printf("a2[0][0]) = %d\n",a2[0][0]);
    printf("(*a2)[0] = %d\n\n",(*a2)[0]);//(*a2)와 같은 pointer 표현식에 [0]와 같은 배열 표현식
    printf("a2[1][3] = %d\n",a2[1][3]);
    printf("(*a2+1)[3] = %d\n\n",(*(a2+1))[3]);
    printf("a2[1][2] = %d\n",a2[1][2]);
    printf("*(*(a2+1)+2) = %d\n\n",*(*(a2+1)+2));
    printf("a2[0][0] = %d\n",a2[0][0]);
    printf("**(a2+0) = %d\n\n",**(a2+0));
    printf("\npointer 주소의 증가와 값의 증가\n");
    printf("*(a1+1)+1 = %d\n",*(a1+1)+1);
    printf("*(*(a2+1)+1)+1 = %d\n",*(*(a2+1)+1)+1);  
    printf("\n\n");   
    //*/
	system("pause");
}
