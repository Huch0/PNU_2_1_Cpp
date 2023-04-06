//5장-6-1.Letters.h   5.5 class 데이터와 class 함수
using namespace std;
// class Letters의 정의
class Letters {
private:
    // private 데이터:
    char ch;//private data member can be accessed within member functions
    static int num;
public:
    Letters (char c);
    ~Letters ();
    char Value ();
    static int Number (){//static 함수는 cpp file에 정의할 수 없다
		//cout << ch;//오류 확인 필요
        return num;
    }
};