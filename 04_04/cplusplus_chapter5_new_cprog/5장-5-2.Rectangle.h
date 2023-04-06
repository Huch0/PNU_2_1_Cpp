//5장-5-2.Rectangle.h    5.4 C++ class와 추상 데이터 타입
using namespace std;
// Horowitz, E., Sahni S., Mehta D. [2007] 자료구조에서 발췌하여 코드를 추가함
class Rectangle{
public:
//	Rectangle(int x = 0, int y = 0, int h = 0, int b = 0);
	//Rectangle();
	Rectangle(int x, int y, int h, int b);
	~Rectangle();
	int Height();
	int Base();
	int Perimeter ();
	int Area();
	int operator==(const Rectangle& s);
	//os<<r;은 operator<<(os, r)을 호출하는 것과 같다 
	friend ostream& operator<< (ostream& os, Rectangle& r);
private:
	int x_pos, y_pos, height, base;
};
