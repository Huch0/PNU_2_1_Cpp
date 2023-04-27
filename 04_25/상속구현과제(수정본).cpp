//7�� Ŭ���� ��� ����
#include <iostream>
#include <string>
using namespace std;
class Dept {
	string dname[10];
	string city;
	ostream& operator<<(Dept&);
};
class Person {
private:
	string pid;
	string pname;
	ostream& operator<<(Person&);

};
class Employee : protected Person {
private:
	string eno;
	Dept* dname;


	ostream& operator<<(Employee&);

};
class Student : private Person {
private: 
    string sid;
    Dept* dname;
};
class Coder : private Employee {
private:
	char* language;
	double workYears;
public:
	int operator > (Coder&);//
	Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
	ostream& operator<<(Coder&);

};
class PartTimeStudent : private Employee, private Student {
private:
    double salary;
    double grade;
};
int main() {
    while (1)
    {
        Coder *codings[10];
        PartTimeStudent* workStudents[10];

        int select;
        //������ ��뿡 ���� �Է��� new Coder("�̸�", ...)���� ���� �����Ͽ� �Է�
        //��ü ����� cout<<*codings[i]���� ����Ѵ�.
        cout << "\n���� 1: Coder ��ü 10�� �Է°� ���, 2. PartTimeStudent ��ü 10�� �Է°� ���, 3: Coder��ü ����(Dept �̸�> ���� ������ ����)�� ���,4. partTimeStudents ��ü ����(eno > sid ������ ����)�� ���, 5. ����" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder ��ü 10�� �Է°� ���

            break;
        case 2://2. PartTimeStudent ��ü 10�� �Է°� ���

            break;

        case 3://3: Coder��ü ����(Dept �̸��� ����)�� ���

            break;
        case 4://4. partTimeStudents ��ü ����(eno > sid)�� ���

            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}