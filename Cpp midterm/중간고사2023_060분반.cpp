//�й� : 202055623
//�̸� : ��ġ��
//������ȣ : 209409060
#include <string>
#include <iostream>
using namespace std;

class Dept {
private:
	string danme; //include string ��밡�� 
	char* city;

public:
	friend istream& operator >>(istream& istream, Dept& d);
	friend ostream& operator <<(ostream& ostream, Dept& d);

	Dept() {
		this->city = new char[1];
		this->city = "\0";

	}
	Dept(Dept* other) {
		this->danme = other->danme;
		this->city = new char[strlen(other->city) + 1];
		strcpy(this->city, other->city);
	}
	~Dept() {
		delete this->city;
	}
};

istream& operator >>(istream& istream, Dept& d) {
	string danme;
	istream >> danme;

	d.danme = danme;

	//cout << "fds" << endl;

	char city[20];
	istream >> city;

	d.city = new char[strlen(city) + 1];
	strcpy(d.city, city);

	return istream;
}

ostream& operator <<(ostream& ostream, Dept& d) {
	ostream << "danme : " << d.danme;
	ostream << " city : ";
	for (int i = 0; d.city[i] != '\0'; i++) {
		ostream << d.city[i];
	}

	ostream << endl;

	return ostream;
}

class Employee {
private:
	char* ename;
	Dept* dept;

public:
	friend istream& operator >>(istream& istream, Employee& e);
	friend ostream& operator <<(ostream& ostream, Employee& e);

	Employee() {
		this->ename = new char[1];
		this->ename = "\0";
		this->dept = new Dept();
	}
	Employee(Employee* other) {
		this->ename = new char[strlen(other->ename) + 1];
		strcpy(this->ename, other->ename);

		this->dept = new Dept(other->dept);
	}
	~Employee() {
		delete this->ename;
		delete this->dept;
	}

	int Employee::operator>(Employee& other);
	int isEqual(string& s);
};
istream& operator >>(istream& istream, Employee& e) {
	char name[20];
	istream >> name;

	e.ename = new char[strlen(name) + 1];
	strcpy(e.ename, name);

	//cout << e.ename;

	istream >> *e.dept;

	return istream;
}
ostream& operator <<(ostream& ostream, Employee& e) {
	ostream << "ename : ";
	for (int i = 0; e.ename[i] != '\0'; i++) {
		ostream << e.ename[i];
	}
	ostream << " dept : " << *e.dept << endl;

	return ostream;
}

int Employee::operator>(Employee& other) {
	if (strcmp(this->ename, other.ename) == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Employee::isEqual(string& s) {
	if (this->ename == s)
		return 1;
	else
		return 0;
}

int main() {

	Employee* guests[5];
	while (1)
	{

		int select;
		cout << "\n���� 1: �Է�, 2. ���, 3: ����, 4. ���İ�� ���, 5. �˻�, 6. ���� =>";
		cin >> select;
		switch (select) {
		case 1: {
			for (int i = 0; i < 5; i++) {
				Employee* e = new Employee();
				cin >> *e;
				guests[i] = e;
			}
			break;
		}
		case 2: {
			for (int i = 0; i < 5; i++) {
				Employee e = guests[i];
				cout << e;
			}
			break;
		}
		case 3: {
			cout << "���� ����" << endl;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5 - i - 1; j++) {
					//cout << *(guests[j]) << *(guests[j + 1]) << endl;
					if (*(guests[j]) > *(guests[j + 1])) {
						Employee* tmp = guests[j];
						guests[j] = guests[j + 1];
						guests[j + 1] = tmp;
						//cout << "check" << endl;
					}

				}
			}

			break;
		}
		case 4: {
			for (int i = 0; i < 5; i++) {
				Employee e = guests[i];
				cout << e;
			}
		}
		case 5: {
			string ename;
			cin >> ename;

			for (int i = 0; i < 5; i++) {
				if (guests[i]->isEqual(ename)) {
					cout << *(guests[i]);
				}
			}
			//cout << e;
			break;
		}
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 1;
}