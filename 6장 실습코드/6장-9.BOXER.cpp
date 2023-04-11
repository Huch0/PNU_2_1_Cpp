// 6장-9.BOXER.CPP
#include <iostream>
#include <string.h>
using namespace std;
class Boxer{
    char * name;

public:
    // 하나의 parameter를 갖는 일반 생성자
    Boxer (char * n){
        name = new char [20];
        strcpy (name, n);
        cout<<"*** Usual constructor called ***" <<endl;
    }
    // 복사 생성자
    Boxer (const Boxer& b){
        name = new char [20];
        strcpy (name, b.name);
        cout << "*** Copy constructor called ***" << endl;
    }
    // 소멸자
    ~Boxer (){
        delete name;
    }
    char *GetName (){
        return name;
    }
    void SetName (char * n){
        strcpy (name, n);
    }
};

void main(){
    // class Boxer의 두 개의 객체를 정의한다.
    Boxer ChampionOfTheSixties ("Cassius Clay");
    //Boxer TheBestEver = ChampionOfTheSixties; //copy constructor
    //*
    Boxer TheBestEver("Bobby"); 
    TheBestEver = ChampionOfTheSixties;
    //*/
    // 첫 번째 boxer 이름을 변경한다.
    ChampionOfTheSixties.SetName ("Mohammed Ali");
    // 두 번째 boxer 이름을 출력한다.
    cout << "The best boxer is " << TheBestEver.GetName () << endl;
	system("pause");
}