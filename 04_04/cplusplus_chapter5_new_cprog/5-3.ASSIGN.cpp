//5-3.ASSIGN.CPP [Folk,Zoellick, Riccardi, 1998]  5.3.5 객체를 생성하고 사용하는 방법 
#include<iostream>
#include<string>
using namespace std;
/*
 1) 내용
  객체의 member 변수를 변경하는 방법들을 비교를 통해 알아보는 것이다.
 2) 방법
  가. 1번 주석을 통해 여러가지 생성자들에 대해 이해하자.
  나. 2번 주석을 통해서 compiler가 제공하는 = 연산을 사용하였을 경우 member변수 값 변화를 보자.
  다. 3번 주석을 통해서 재정의한 '=' 연산자를 이용하였을 때 member변수 값 변화를 보자.
*/
class String{
public:
    String (); //default 생성자
    String (const String&); //복사 생성자
    String & operator = (const String &); //assignment
     String (char* ); //생성자 overloading
    ~String ();  //소멸자 
//    char* getString() { return string; }
private:
    char * string;
};	

String::String(){
    cout<<"[default 생성자 호출]"<<endl;
	string = new char [10];
}

String::String(char* _string){
    cout<<"[parameter가 있는 생성자 호출]"<<endl;
    string = new char[strlen(_string)+1];
    strcpy_s(string, strlen(_string)+1, _string);
}

String::String(const String& str){
    cout<<"[복사 생성자 호출]"<<endl;
    string = new char[strlen(str.string)+1];
    strcpy_s(string,strlen(str.string)+1, str.string);
}
//주석 3번
/* compiler가 제공하는 assignment 연산자 사용시 문제가 무엇인지를 파악하는 것이 필요
String & String:: operator = (const String & str){
    cout<<"[재정의한 assign 함수호출]"<<endl;
    string = new char[strlen(str.string)+1];
    strcpy_s(string, strlen(str.string)+1,str.string);
    return *this;
}
*/
String::~String(){ 
    cout<<"[소멸자 호출]"<<endl;
    delete []string;
}

void main(){
    //1번 주석 
    //*
    String s1;
    cout << "\ts1의string은" << s1.getString() << "이다." <<endl;

    String s2("Programming");
    cout << " s2의 string은 " << &s2.string << "이다." <<endl<<endl;

    String s3(s2); 
    cout << " s3의 string은 " << &s3.string << "이다." <<endl<<endl;
    //*/

    //2번 주석
   //*
    s1 = s2; 
    cout << " s1의 string은 " << s1.string << "이다." <<endl<<endl;	
	cout << " s2의 string은 " << s2.string << "이다." << endl << endl;
    cout<<"[s2, s3의 string member변수의 값을 변경함]"<<endl;
    char *str1 = "Database";
    char *str2 = "FileSystem";
    strcpy_s (s2.string, strlen(str1)+1, str1);
    strcpy_s (s3.string, strlen(str2)+1, str2);
    cout << " s1의 string은 " << s1.string << "이다." <<endl;
    cout << " s2의 string은 " << s2.string << "이다." <<endl;
    cout << " s3의 string은 " << s3.string << "이다." <<endl<<endl;
    //*/
	system("pause");
}