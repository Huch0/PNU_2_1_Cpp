#include <iostream>
//º¹¼Ò¼ö¿¡ ´ëÇÑ »çÄ¢¿¬»êÀÌ °¡´ÉÇÏµµ·Ï ±¸ÇöÇÑ´Ù. main() ÇÔ¼ö´Â ¼öÁ¤ÇÏ¸é ¾ÈµÈ´Ù
using namespace std;
class ComplexNumber {
private:
	float real;
	float imaginary;
public:

	friend ostream& operator<<(ostream& stream, const ComplexNumber& p);
	
};

ostream& operator<<(ostream& stream, const ComplexNumber& p) {
	stream << p.real << " + " << p.imaginary << "i";
	return stream;
}

int main(void) {
	while (1)
	{
		ComplexNumber a(1, 1), b(2, 2), c(3, 3), d(4, 4);
		int select;	
		cout << "\nSelect command 1: µ¡¼À, 2: »¬¼À, 3. °ö¼À, 4: ³ª´°¼À, 5. ¿¬¼âµ¡¼À, 6. quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << endl << "µ¡¼À d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.add(b.add(c));
			cout << "d = " << d << endl;
			break;
		case 2:
			cout << endl << "»¬¼À d = a - b - c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.subtract(b.subtract(c));
			cout << "d = " << d << endl;
			break;

		case 3:
			cout << endl << "°ö¼À d = a * b * c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.multiply(b.multiply(c));
			cout << "d = " << d << endl;
			//e = a - b - c - d;
			break;
		case 4:
			cout << endl << "³ª´°¼À d = a / b / c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.divide(b.divide(c));
			cout << "d = " << d << endl;
			cout << a;
			break;
		case 5:
			cout << endl << "cascading µ¡¼À d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a + b + c;
			cout << "d = " << d << endl;
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 1;
}