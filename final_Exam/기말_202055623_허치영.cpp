/*
* 클래스 상속, template, 예외처리 구현 - 23.6.13 기말코딩시험 060분반 
*/
#include <iostream>
#include <ctime>
using namespace std;

class ExceptionError {
public:
	virtual void Print() = 0;
};
class OverflowException : public ExceptionError {
public:
	void Print() {
		cout << "overflow 예외 발생" << endl;
	}
};
class RowRecordsOverflowException : public OverflowException {
public:
	void Print() {
		cout << "Row Records overflow 예외 발생" << endl;
	}
};
class TableRecordsOverflowException : public OverflowException {
public:
	void Print() {
		cout << "Table Records overflow 예외 발생" << endl;
	}
};
class EmptyException : public ExceptionError {
public:
	void Print() {
		cout << "empty 예외 발생" << endl;
	}
};
class NotFoundException : public ExceptionError {
public:
	void Print() {
		cout << "Not found  예외 발생" << endl;
	}
};
class NotFoundRecordTableException : public NotFoundException {
public:
	void Print() {
		cout << "Not found record table 예외 발생" << endl;
	}
};
class NotFoundRowRecordsException : public NotFoundException {
public:
	void Print() {
		cout << "Not found record 예외 발생" << endl;
	}
};
class NotFoundUpdateRecordException : public NotFoundRecordTableException {
public:
	void Print() {
		NotFoundRecordTableException::Print();
		cout << "Not found update 예외 발생" << endl;
	}
};
class NotFoundDeleteRecordException : public NotFoundRecordTableException {
public:
	void Print() {
		NotFoundRecordTableException::Print();
		cout << "Not found delete 예외 발생" << endl;
	}
};
class Person {
	string pid;
	string pname;
public:
	Person() {
	}

	Person(string pid, string pname): pid(pid), pname(pname) {
	}

	string GetPid() { return this->pid; }
	void SetPid(string str) { this->pid = str; }
	string GetName() { return this->pname; }
	void SetName(string str) { this->pname = str; }

	friend ostream& operator<<(ostream& s, Person& p) {
		s << "| " << p.pid << " | " << p.pname << " |";
		return s;
	}

	virtual void Print() {
	}

	virtual bool Equals(Person* p) {
		if ((this->pid == p->pid) && (this->pname == p->pname))
			return true;
		else
			return false;
	}
	virtual string GetKey() { return this->pid; }
};

class Employee : public Person {
private:
	string eid;
	string role;
public:
	Employee() : Person() {
	}

	Employee(string pid, string pname, string eid, string role) :Person(pid, pname), eid(eid), role(role) {
	}

	void Print() override;
	bool Equals(Person* p) override;
	virtual string GetKey();

	string GetEid() { return this->eid; }
	void SetEid(string str) { this->eid = str; }
	string GeRole() { return this->role; }
	void SetRode(string str) { this->role = str; }

	friend ostream& operator<<(ostream& s, Employee& e) {
		s << (Person&)(e);
		s << " " << e.eid << " | " << e.role << " |";
		return s;
	}
};

bool Employee::Equals(Person* p) {
	;
	if (__super::Equals(p) && (this->eid == ((Employee*)p)->eid) && (this->role == ((Employee*)p)->role))
		return true;
	else
		return false;
}


void Employee::Print() {

}

string Employee::GetKey() {
	return this->role;
}


class Student : public Person {
private:
	string sid;
	string major;
public:
	Student() :Person() {
	}

	Student(string pid, string pname, string sid, string major) : Person(pid, pname), sid(sid), major(major) {
	}

	void Print() override;
	bool Equals(Person* p) override;
	virtual string GetKey();

	string GetSid() { return sid; }
	void SetSid(string str) { sid = str; }
	string GetMajor() { return major; }
	void SetMajor(string str) { major = str; }

	friend ostream& operator<<(ostream& s, Student& stdnt) {
		s << (Person&)(stdnt);
		s << "| " << stdnt.sid << " | " << stdnt.major << " |";
		return s;
	}
};

bool Student::Equals(Person* p) {
	;
	if (__super::Equals(p) && (this->sid == ((Student*)p)->sid) && (this->major == ((Student*)p)->major))
		return true;
	else
		return false;
}

void Student::Print() {
}

string Student::GetKey() {
	return this->major;
}

class WorkStudent : public Student {
private:
	string wid;
	string job;
public:
	WorkStudent()
	{
	}

	WorkStudent(string pid, string pname, string sid, string major, string wid, string job)\
		: Student(pid, pname, sid, major), wid(wid), job(job)
	{
	}

	void Print() override;
	bool Equals(Person* p) override;
	virtual string GetKey();

	string GetWid() { return wid; }
	void SetWid(string str) { wid = str; }
	string GetJob() { return job; }
	void SetJob(string str) { job = str; }

	friend ostream& operator<<(ostream& s, WorkStudent& w) {
		s << (Student &)(w);
		s << "| " << w.wid << " | " << w.job << " |";
		return s;
	}

};

bool WorkStudent::Equals(Person* p) {
	;
	if (__super::Equals(p) && (this->wid == ((WorkStudent*)p)->wid) && (this->job == ((WorkStudent*)p)->job))
		return true;
	else
		return false;
}

void WorkStudent::Print() {

}

string WorkStudent::GetKey() {
	return this->job;
}



template <class T>
class RowRecords {
public:
	//RowRecords();
	RowRecords(int maxKeys = 5, int unique = 1);// unique = 1은 중복이 없다
	~RowRecords();
	void Clear(); // RowRecords의 모든 레코드를 삭제한다
	int Insert(const T& record);
	int Remove(const string key);
	int Update(const string key, const T&);
	T& Search(const string key) const;
	void Print() const;
	int GetNumKeys()const { return NumKeys; }
	int GetMaxKeys()const { return MaxKeys; }
	int Find(const string key) const;

	int Init(const int maxKeys, const int unique);

protected:
	int MaxKeys; //5개
	int NumKeys; //현재 포인터, 5개가 다차면 ++
	string* Keys;
	T* Records;

	int Unique; // if true, each key value must be unique

};

template <class T>
RowRecords<T>::RowRecords(int maxKeys, int unique) : NumKeys(0), Keys(0), Records(0) {
	Init(maxKeys, unique);
}

template <class T>
int RowRecords<T>::Init(const int maxKeys, const int unique) {
	Unique = unique != 0;
	MaxKeys = maxKeys;
	Keys = new string[maxKeys];
	Records = new T[maxKeys];

	return 0;
}
template <class T>
RowRecords<T>::~RowRecords() {
	delete Keys;
	delete Records;
}
template <class T>
void RowRecords<T>::Clear() {
	NumKeys = 0;
}
template <class T>
int RowRecords<T>::Insert(const T& record) {

	// 레코드에 정렬없이 중복체크만 해서 뒤에다 붙이면 됨.

	if (NumKeys == MaxKeys) {
		throw RowRecordsOverflowException();
	}

	string key = ((Person)record).GetKey();
	//string key = record.GetKey();

	int index = Find(key);
	if (Unique && index >= 0) //주어진 key가 이미 존재함
		return 0;

	Keys[NumKeys] = key;
	Records[NumKeys] = record;
	NumKeys++;

	return 1;
}

template <class T>
int RowRecords<T>::Remove(const string key) {
	int index = Find(key);
	if (index < 0)
		throw NotFoundRowRecordsException();

	for (int i = index; i < NumKeys - 1; i++) {
		Keys[i] = Keys[i + 1];
		Records[i] = Records[i + 1];
	}
	NumKeys--;
	Keys[NumKeys] = "";
	//Records[NumKeys] = NULL;

	return 1;
}

template <class T>
int RowRecords<T>::Update(const string key, const T& record) {
	int index = Find(key);
	if (index < 0)
		throw NotFoundRowRecordsException();

	Keys[index] = ((Person)record).GetKey();
	Records[index] = record;

	return 1;
}

template <class T>
T& RowRecords<T>::Search(const string key) const {
	int index = Find(key);
	if (index != -1)
		return Records[index];

	throw NotFoundRowRecordsException();
}
template <class T>
void RowRecords<T>::Print() const {
	for (int i = 0; i < NumKeys; i++) {
		if (Keys[i] != "")
			cout << "\tKey[" << i << "] " << Keys[i] << ", Records = " << Records[i] << endl;
	}
}
template <class T>
int RowRecords<T>::Find(const string key) const {
	for (int i = 0; i < NumKeys; i++) {
		if (Keys[i] == key)
			return i;
	}

	return -1;
}

template <class T>
class RecordTable {
public:
	T& Read(string  key);//read by key
	int Append(const T& record);
	int Update(string key, const T& record);
	int Delete(string key);
	void Print() const;
	RecordTable(int keySize, int maxKeys = 5, int maxRecords = 10);
	~RecordTable();
protected:
	int MaxKeys;	// 5개
	int MaxRecords;	// 10개 
	int NumRecords;	// 현재 위치 포인터
	RowRecords<T>* data;
};

template <class T>
RecordTable<T>::RecordTable(int keySize, int maxKeys = 5, int maxRecords = 10) : MaxKeys(maxKeys), MaxRecords(maxRecords) {
	NumRecords = 0;
	data = new RowRecords<T>[maxRecords];
}
template <class T>
RecordTable<T>::~RecordTable() {
	delete data;
}
template <class T>
T& RecordTable<T>::Read(string key) {
	for (int i = 0; i < NumRecords; i++) {
		int result = data[i].Find(key);//data[i]는 row records이고 여기에 key가 있는지를 조사
		if (result > 0)
			return data[i].Search(key);//Search(key)를 사용하여 row records에서 해당 레코드를 가져온다
	}
	throw NotFoundRecordTableException();
}
template <class T>
int RecordTable<T>::Append(const T& record) {
	int i = NumRecords;
	//NumRecords에 있는 row records가 append할 수 있는지를 조사한다.
	if (data[i].GetNumKeys() == data[i].GetMaxKeys())
	{
		i = ++NumRecords;
	}
	int result = data[i].Insert(record);
	return result;
}
template <class T>
int RecordTable<T>::Update(string key, const T& record) {
	for (int i = 0; i <= NumRecords; i++) {
		int result = data[i].Find(key);
		if (result > 0) {
			data[i].Update(key, record);
			return 1;
		}
	}
	return 0;
}
template <class T>
int RecordTable<T>::Delete(string key) {
	for (int i = 0; i <= NumRecords; i++) {
		int result = data[i].Find(key); //data[i]는 RowRecords이고 여기에 key가 있는지를 조사
		if (result > 0) {
			data[i].Remove(key);
			return 1;
		}
	}

	return 0;
}


template <class T>
void RecordTable<T>::Print() const {
	for (int i = 0; i <= NumRecords; i++) {
		data[i].Print();
	}
}

int main() {
	Employee* members[30];//Employee 선언으로 변경하는 문제 해결 필요 
	WorkStudent* workers[20];
	RecordTable<Employee> etable(10, 5);//10개의 record sets, 각 set은 5개의 records
	RecordTable<WorkStudent> wtable(10, 5);
	int select;
	Employee* e = nullptr;
	WorkStudent* ws = nullptr;
	int result;
	while (1)
	{
		cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 업데이트, 6. 종료" << endl;
		cin >> select;
		switch (select) {
		case 1://table에 객체 30개 입력
			members[0] = new Employee("p1", "hong", "E1", "Coding");
			members[1] = new Employee("p2", "hee", "E2", "Coding");
			members[2] = new Employee("p3", "kim", "E3", "Test");
			members[3] = new Employee("p4", "lee", "E4", "Test");
			members[4] = new Employee("p5", "ko", "E5", "Design");
			members[5] = new Employee("p6", "choi", "E6", "Design");
			members[6] = new Employee("p7", "han", "E7", "Sales");
			members[7] = new Employee("p8", "na", "E8", "Sales");
			members[8] = new Employee("p9", "you", "E9", "Account");
			members[9] = new Employee("p10", "song", "E10", "Production");
			workers[0] = new WorkStudent("p11", "hong", "s11", "coding", "W11", "hong");
			workers[1] = new WorkStudent("p12", "ong", "s12", "coding", "W12", "ong");
			workers[2] = new WorkStudent("p13", "dong", "s13", "coding", "W13", "dong");
			workers[3] = new WorkStudent("p14", "fong", "s14", "coding", "W14", "fong");
			workers[4] = new WorkStudent("p15", "tong", "s15", "coding", "W15", "tong");
			workers[5] = new WorkStudent("p16", "nong", "s16", "coding", "W16", "nong");
			workers[6] = new WorkStudent("p17", "mong", "s17", "coding", "W17", "mong");
			workers[7] = new WorkStudent("p18", "kong", "s18", "coding", "W18", "kong");
			workers[8] = new WorkStudent("p19", "long", "s19", "coding", "W19", "long");
			workers[9] = new WorkStudent("p20", "pong", "s20", "coding", "W20", "pong");
			workers[10] = new WorkStudent("p21", "lim", "s21", "coding", "W21", "lim");
			workers[11] = new WorkStudent("p22", "mim", "s22", "coding", "W22", "mim");
			workers[12] = new WorkStudent("p23", "bim", "s23", "coding", "W23", "bim");
			workers[13] = new WorkStudent("p24", "dim", "s24", "coding", "W24", "dim");
			workers[14] = new WorkStudent("p25", "rim", "s25", "coding", "W25", "rim");
			workers[15] = new WorkStudent("p26", "qim", "s26", "coding", "W26", "qim");
			workers[16] = new WorkStudent("p21", "fim", "s21", "coding", "W21", "fim");
			workers[17] = new WorkStudent("p21", "him", "s21", "coding", "W21", "him");
			workers[18] = new WorkStudent("p27", "jim", "s27", "coding", "W27", "jim");
			workers[19] = new WorkStudent("p27", "jjj", "s27", "coding", "W27", "jjj");

			try {

				for (int i = 0; i < 10; i++)
				{
					etable.Append(*members[i]);

				}
				for (int i = 0; i < 20; i++)
				{
					wtable.Append(*workers[i]);

				}
			}
			catch (ExceptionError & ee) {
				ee.Print();
			}
			break;
		case 2:
			// table의 모든 객체 출력하기
			//table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.
			
			//구분하기 쉽게 출력하는 코드 추가했습니다.
			cout << "etable : " << endl;
			etable.Print();

			cout << "wtable : " << endl;
			wtable.Print();
			break;
		case 3:
			// table에서 객체 찾기
			try {
				e = &etable.Read("p4");
				ws = &wtable.Read("p14");
				
				// 찾은 객체 출력하는 코드 추가했습니다.
				cout << "p4 : " << *e << endl;
				cout << "p14 : " << *ws << endl;
			}
			catch (ExceptionError& ee) {
				ee.Print();
			}
			break;
		case 4:
			//table에서 객체 삭제하기
			try {
				result = etable.Delete("p10");
				result = wtable.Delete("p27");
			}
			catch (ExceptionError & ee) {
				ee.Print();
			}
			break;
		case 5:
			try {
				e = new Employee("p99", "song2", "E99", "update");
				result = etable.Update("p8", *e);

				//ws에 동적할당하는 코드가 없어서 추가했습니다.
				ws = new WorkStudent("p99", "hong", "s99", "coding", "W99", "update");
				result = wtable.Update("p22", *ws);
			}
			catch (ExceptionError & ee) {
				ee.Print();
			}
			break;
		default:
			exit(0);
		}
	}
	system("pause");
	return 1;
}