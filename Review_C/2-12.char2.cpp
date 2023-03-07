//2-12. char2.cpp: 실습예제 2.12
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void){
    char *i = "monday";
    char *j;
    char *p[10];
    char *q[10];
    char r[10] = "sunday";
    char s[10];
	//1번 주석
    //*
    //*i = "good";
    j = i;
	//s = r;//s는 lvalue가 아니다 배열 이름으로 상수이다.
	//strcpy(i, "saturday");//runtime 오류 발생, *i는 상수 값 "monday"를 가짐, 변경 불가
	strcpy(r, "friday");
	*p = "wednesday";//p는 array of pointer
    *q = "thursday";
	//*/
    //2번 주석
    //*
    printf("i = %s, j = %s\n", i, j);
    printf("*p = %s, *q = %s\n", *p, *q);
    printf("r = %s\n", r);
	// i,j, *p 모두 문자열 상수를 가리키고 있으므로 변경 불가
    //strcpy(j, i);
	//strcpy(i, *p);
	strcpy(s, r);
	//strcpy(*p, i);
	//strcpy(*p, *q);
	//strcpy(*p, s);

    //------------------------------
	printf("\n\n*i->r[] 문자열 복사후\n");
    strcpy(r, i);
    printf("i = %s, r = %s\n", i, r);
    printf("strcmp(r, i) = %d (0->같다, 0아닌숫자->다르다)\n", strcmp(r, i));
   
    printf("\n\n*p[]->s[] 문자열 복사후\n");
    strcpy(s, *p);
    printf("s = %s, *p = %s\n", s, *p);
    printf("strcmp(s, *p) = %d (0->같다, 0아닌숫자->다르다)\n", strcmp(s, *p));

    printf("\n\nr[]->s[] 문자열 복사후\n");
    strcpy(s, r);
    printf("r = %s, s = %s\n", r, s);
    printf("strcmp(s,r) = %d (0->같다, 0아닌숫자->다르다)\n", strcmp(s, r));
    //*/
    system("pause");
}