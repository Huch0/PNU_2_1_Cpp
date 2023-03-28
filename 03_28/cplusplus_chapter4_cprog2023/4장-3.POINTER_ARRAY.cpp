//4장-3.POINTER_ARRAY.cpp   4.3 pointer 변수와 reference 변수
#include <iostream>
using namespace std;
#define NWEEK 5
int main(void)
{   //*week[N]와 working[N][]의 구조를 이해
    char *week[NWEEK] = {
		"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	//week[0] = "abcddddd";//동작한다 그 이유는?
	char working[NWEEK][10] = {"Mon", "Tue", "Wed", "Thu", "Fri"};//char *p[10] == char p[10][20]

	week[1] = "Sat"; //week[1]은 lvalue이다
	//working[0] = "null"; //lvalue가 아니다
	week[0] = working[4]; //week와 working의 호환
    cout<< "week[0] = "<< week[0] << endl <<"week[1] = "<< week[1]<<endl;
	cout<<"working[0] = "<<working[0]<<endl<<"working[1] = "<<working[1]<<endl;
	system("pause");
	return 0;
}