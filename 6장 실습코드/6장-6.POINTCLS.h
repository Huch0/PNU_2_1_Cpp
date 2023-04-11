// 6장-6.POINTCLS.h
using namespace std;//default copy constructor 사용시
//copy constructor를 사용시에는 std를 미사용하는 것이 필요 => 불필요함/version 개선됨
class PointerClass {
    int number;
    int * pointer;
public:
    // 생성자
	//*
	PointerClass(const PointerClass& pc);
    //*/
	PointerClass (int a, int b);
    // 소멸자
    ~PointerClass ();
    void Print ();
};