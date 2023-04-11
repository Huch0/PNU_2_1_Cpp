//6-9. STRINGCLASS.CPP
//string.h는 컴파일러가 제공하는 코드임
#include <iostream>
#include <string>
using namespace std;
/*
실습 9
1)내용
 Character pointer를 return에 대한 연산자 overloading으로 member 변수를 복사하였을 경우와 String class에서 대입(=), 비교(==)에 대한 연산자 overloading 사용에 대한 결과를 출력을 통해서 알아보도록 하자.

2)방법
 가. String 타입 class로 어떻게 정의하였는지, 어떻게 사용하는 지를 출력을 통해서 알아보도록 하자.
 나. 주석 1을 해제하여 = 연산자 overloading을 이용했을 때 6-8.CHARACTERSTRING에서 string1 = string2과의 차이가 무엇인지 확인해보자.
*/
class String{
public:
    //default constructor
    String ( );
    //copy constructor
    String (String&);
    // create from C string 
    String (char *); 
    //destructor
    ~ String ( );
    //conversion to char *
    operator const char * () 
    //inline body of method
    {return string;} 
    //assignment
    String & operator = (const String *); 
    //equality
    int operator == (const String *) const; 
    //represent value as C string
    char * string; 
};

String & String:: operator = (const String * str){
    //code for assignment operator
    string = new char[strlen(str->string)+1];
    strcpy_s(string, strlen(str->string)+1,str->string);
	cout<<"operator =():: "<< string<<endl;
    return *this;
}

int String:: operator == (const String * str) const{
    //code for equality operator
    return strcmp(string, str->string);
}
String::String(){
	string = new char[10];}
String::String(String& str){
	string = new char[strlen(str.string)+1];
    strcpy_s(string,strlen(str.string)+1, str.string);
}
String::String(char * _string){
    string = new char[strlen(_string)+1];
    strcpy_s(string, strlen(_string)+1, _string);
}
String::~String(){
}

void main(){
    cout<<"string class"<<endl<<endl;
    //생성자를 통한 class member변수를 정의하고 확인
    //use String::String (const char*)
    String *s1 = new String("Good Night!"); 
    cout << "s1의 string은 " << s1->string << " 이다."<<endl<<endl;
    //Character pointer return operator overloading을 이용하여 member변수를 string copy 하고 copy 결과확인
    char str[15];
    //uses String::operator char *()
    strcpy_s(str, strlen(s1->operator const char *())+1, s1 -> operator const char *()); 
    cout << "str변수에 copy 된 문자열은 " << str << " 이다."<< endl<<endl;
	//strcpy(str, s1);//String * 형식의 parameter가 const char*와 호환된지 않는다
    // strcpy(str,s1)허용되지 않는 이유는 char * strcpy(char *dest, const char *str)
    // 형태이기 때문에 conversion constructor의 const와 상관없이 허용되지 않는다.
    strcpy(str,s1->operator const char *()); 
    //주석 1
    
    //Class =operator overloading을 이용하여 String class 대입을 하고 결과확인
    String *s2 = new String();
    // = 연산자 overloading을 이용하여 s2가 가리키는 값을 s1의 값으로 치환한다.
    s2 -> operator = (s1);    
    cout << "s2의 string은 " << s2->string << " 이다."<<endl<<endl;
    //Class 비교 operator overloading을 이용하여 두개의 class의 일치 여부를 확인
    cout << "s1과 s2를 ==연산자를 이용하여 비교" << endl;
    cout << "s1->operator ==(s2) : ";
    //uses String::operator == (const String *) const
    cout << s1->operator ==(s2) << endl; 
    cout << "((*s1)==(*s2)) : ";
    //s1->operator==(s2)와 같은 연산
    cout << ((*s1)==(*s2)) <<endl<< endl; 
    //0이면 equal, -1이면 nonequal
	String s3;
	s3 = s2;
    system("pause");
}