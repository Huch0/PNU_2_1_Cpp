//6-8. CHARACTERSTRING.CPP
//6-9 String Class를 공부하기 위하여 만든 코드임
#include <iostream>
using namespace std;
#define STRING "Show anything."
#define N 4
#define LEN 10
/*
실습 8
1)내용
 C++에서 문자열 사용을 위해 별도로 제공되는 type이 없기 때문에 char type으로 문자열을 다루는 것을 출력을 통해서 결과를 확인하도록 하자.
2)방법
 가. 실행시 변수가 가리키는 곳이 어딘지를 생각해보자.
*/
int main(){
	int i;
    char a[] = STRING;//a는 local variable로서 stack 영역에 존재
	char *b = STRING; //b는 local variable이나 STRING이 data 영역의 data segment로서 b++시에 코드 영역을 침범할 수 있어 주의 필요
	char *c;

	char *d[N] = {"trout", "salmon", "saury", "eel"};
	char e[N][LEN] = {"carp", "mackerel", "cod", "squid"};


	printf("a = %p\n", a);
	printf("b = %p\n", b);
	printf("address of STRING = %p\n", STRING);

	cout<<" a[] = ";
	for (i = 0; i < 14; i++)
		putchar(*(a+i));
	putchar('\n');
	cout<<"*b = ";
	for (i = 0; i < 14; i++)
		putchar(*(b+i));
	putchar('\n');
	c = b;
	cout << "*(b++) = ";
	while (*(b) != '\0')
		putchar(*(b++));
	putchar('\n');
	cout<<"After executing *(b++):: ";
	printf("b = %p\n", b);
	printf("*b = %s\n", b);
	
	printf("c = %p\n", c);
	for (i =0; i < N; i++) {
		printf("d[%d] = %s\n", i, d[i]);
		printf("e[%d] = %s\n", i, e[i]);
	}
	system("pause");
}