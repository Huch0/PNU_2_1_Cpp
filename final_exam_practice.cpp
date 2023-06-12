/*
* 클래스 상속, template, 예외처리 구현
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
		cout << "overflow 예외 발생"<< endl;
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
class NotFoundRecordException : public EmptyException {
public:
	void Print() {
		cout << "Not found record 예외 발생" << endl;
	}
};
class Person {
	string pid;
	string pname;
public:
	string GetName() { return pname; }
	void SetName(char* str) { pname = str; }
};

class Employee : public Person {
private:
	string eno;
	string role;
public:
	Employee() :Person() {}

	virtual void Print();
	virtual bool Equals(Employee* p);
};
bool Employee::Equals(Employee* p) {

}
void Employee::Print() {

}


class Student {
private:
	string sid;
	string major;
public:
	void Print();
};
void Student::Print() {


}
class WorkStudent : public Student {
private:
	string job;
public:
	void Print();
};
template <class T>
class RowRecords {
public:
	RowRecords(int maxKeys = 5, int unique = 1);// unique = 1은 중복이 없다
	~RowRecords();
	void Clear(); // RowRecords의 모든 레코드를 삭제한다
	int Insert(const string key, T& record);
	int Remove(const string key, const T&);
	T& Search(const string key) const;
	void Print(ostream&) const;
	int numKeys()const { return NumKeys; }
	int Find(const string key) const;
protected:
	int MaxKeys;
	int NumKeys;
	string * Keys;
	T* Records;

	int Init(const int maxKeys, const int unique);
	int Unique; // if true, each key value must be unique

};

template <class T>
RowRecords<T>::RowRecords(int maxKeys, int unique) : NumKeys(0), Keys(0), Records(0) {
	Init(unique);
}
template <class T>
int RowRecords<T>::Init(const int maxKeys, const int unique) {
	Unique = unique != 0; // unique가 0이 아니면 True
	MaxKeys = maxKeys; // maxKeys 지정
	Keys = new String[maxKeys]; // maxKeys크기 String 배열 동적 할당
	Records = new T[maxKeys];  // maxKeys 크기 T 배열 동적 할당
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
int RowRecords<T>::Insert(const string key, T & record) {
	int i;
	int index = Find(key);
	if (Unique && index >= 0) return 0; //주어진 key가 이미 존재하면 return 0
	if (NumKeys == MaxKeys) throw OverflowInsert(); // 이미 Records가 가득 차있다면 throw OverflowException 인데 오타인듯?
	for (i = NumKeys - 1; i >= 0; i--) { //배열을 뒤에서부터 돌면서 새로운 key가 들어갈 위치를 찾음
		if (key > Keys[i])break; //insert into location i+1
		Keys[i + 1] = Keys[i];
		T[i + 1] = T[i];
	}
	//내 생각엔 
	// 1. 새로운 key가 들어갈 위치 i를 string 비교를 통해 찾음. 
	// 2. i + 1  ~ NumKeys - 1 의 Keys와 Records 요소들을 한칸씩 뒤로 밀어야 됨.
	// 3. Key[i] = key, Records[i] = record , NumKeys++

	Keys[i + 1] = key; // Keys[i]
	T[i + 1] = record; // Records[i + 1] 인데 잘못쓴듯?
	NumKeys++;
	return 1;
}
template <class T>
int RowRecords<T>::Remove(const string key, const T& record) {
	int index = Find(key, record); // 지우고자 하는 key에 해당하는 index
	if (index < 0) return 0; //key not in index, 지우고자 하는 key 가 없으면 return 0
	for (int i = index; i < NumKeys; i++) { // index 부터 끝까지 Keys와 Records 배열을 한칸씩 땡김
		Keys[i] = Keys[i + 1];
		T[i] = T[i + 1];
	}
	NumKeys--;
	return 1;
}

template <class T>
T& RowRecords<T>::Search(const string key) const{
	int index = Find(key); // 찾고자 하는 key에 해당하는 index
	if (index != -1) return Records[index]; // index를 찾으면 Records[index] 리턴
	throw EmptyException(); // 내생각엔 throw NotFoundRecordException() 을 해야됨
}
template <class T>
// 현재 RowRecords의 상태를 출력하는 함수 
void RowRecords<T>::Print(ostream & stream) const{
	stream << "max keys = " << MaxKeys << " num keys = " << NumKeys << endl;
	for (int i = 0; i < NumKeys; i++) {
		stream << "\tKey[" << i << "] " << Keys[i] << " Records = " << Records[i] << endl;
	}
}
template <class T>
// Keys 배열을 돌면서 일치하는 key를 찾음.
// 해당 key의 index를 return
// 못찾으면 -1 return
int RowRecords<T>::Find(const string key) const{
	for (int i = 0; i < NumKeys; i++) {
		if (Keys[i] < key) continue;
		if (Keys[i] == key) {  //찾고자 하는 key 와 일치하면
			if (record == Records[i]) // record의 정체를 모르겠음.
				return i; 
		}
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
	void Print(ostream&) const;
	RecordTable(int keySize, int maxKeys = 5, int maxRecords = 10);
	~RecordTable();
protected:
	int MaxKeys;
	int MaxRecords;
	int NumRecords;
	RowRecords<T>* data;
};
template <class T>
RecordTable<T>::RecordTable(int keySize, int maxKeys = 5, int maxRecords = 10): MaxKeys(maxKeys), MaxRecords(maxRecords) {
	NumRecords = 0;
	for (int i = 0; i < MaxRecords; i++) {
		data[i] = new RowRecords<T>(maxKeys);
	}

}
template <class T>
RecordTable<T>::~RecordTable() {
	for (int i = 0; i < MaxRecords; i++) {
		delete data[i];
	}
}
template <class T>
// 각 rowRecords를 돌면서 key 와 일치하는 index를 찾음.
// index를 찾으면 해당 RowRecords에서 key에 해당하는 <T> 객체를 return.
// 못찾으면 throw NotFoundRecord() 
T& RecordTable<T>::Read(string key) {
	for (int i = 0; i < NumRecords; i++) {
		int result = data[i].Find(key);//data[i]는 row records이고 여기에 key가 있는지를 조사
		if (result > 0)
			return data[i].Search(key);//Search(key)를 사용하여 row records에서 해당 레코드를 가져온다

	}
	throw NotFoundRecord();
}
template <class T>
// RecordTable에 T 객체를 append함.
// 인자로 key를 안받는데 Person의 pid, Student의 sid를 key로 하려고 .Key()라는 메소드를 쓴건지는 모르겠음.
// NumRecords의 (현재 가리키고 있는) RowRecords 객체가 가득찼는지 확인, 가득찼으면 NumRecords +1;
// 가득차지 않은 NumRecords에 Insert(key, record)
// RowRecords<T>::Insert는 key도 인자로 받기 때문에 나중에 key관련 코드를 추가해야됨.
// Insert() 결과를 리턴
int RecordTable<T>::Append(const T & record) {
	string key = record.Key();
	int i = NumRecords;
	//NumRecords에 있는 row records가 append할 수 있는지를 조사한다.
	if (data[i].numKeys() == MaxKeys)
	{
		i = ++NumRecords;
	}
	int result = data[i].Insert(record);
	return result;

}
template <class T>
// 0 ~ NumRecords - 1 만큼 돌면서 key에 해당하는 데이터가 저장되어있는지 확인.
// 찾았으면 그 RowRecords에서 Remove(key) 이후 
// Insert(key, record)
int RecordTable<T>::Update(string key, const T& record) {
	for (int i = 0; i < NumRecords; i++) {
		int result = data[i].Find(key);//data[i]는 row records이고 여기에 key가 있는지를 조사
		if (result > 0) {
			data[i].Remove(key, Search(key));
			data[i].Insert(key, record);
			return 1;
		}
		

	}
	return 0;
}
template <class T>
// key에 해당하는 RowRecords와 index를 찾은다음.
// 그 부분에서 data[i].Remove(key)를 수행.
int RecordTable<T>::Delete(string key) {
}
template <class T>

template <class T>
// 0 ~ NumRecords - 1 까지 돌면서 
// data[i].Print() 수행
void RecordTable<T>::Print(ostream& os) const {
}

int main() {
	Employee* members[30];//Employee 선언으로 변경하는 문제 해결 필요 
	WorkStudent* workers[20];
	RecordTable<Employee> etable(10, 5);//10개의 record sets, 각 set은 5개의 records
	RecordTable<WorkStudent> wtable(10, 5);
	int select;
	Employee* e; WorkStudent* ws;
	int result;
	while (1)
	{
		cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 종료" << endl;
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
			workers[0] = new WorkStudent("s011", "coding", "hong");
			workers[1] = new WorkStudent("s012", "coding", "ong");
			workers[2] = new WorkStudent("s013", "coding", "dong");
			workers[3] = new WorkStudent("s014", "coding", "fong");
			workers[4] = new WorkStudent("s015", "coding", "tong");
			workers[5] = new WorkStudent("s016", "coding", "nong");
			workers[6] = new WorkStudent("s017", "coding", "mong");
			workers[7] = new WorkStudent("s018", "coding", "kong");
			workers[8] = new WorkStudent("s019", "coding", "long");
			workers[9] = new WorkStudent("s020", "coding", "pong");
			workers[10] = new WorkStudent("s021", "coding", "lim");
			workers[11] = new WorkStudent("s022", "coding", "mim");
			workers[12] = new WorkStudent("s023", "coding", "bim");
			workers[13] = new WorkStudent("s024", "coding", "dim");
			workers[14] = new WorkStudent("s025", "coding", "rim");
			workers[15] = new WorkStudent("s026", "coding", "qim");
			workers[16] = new WorkStudent("s021", "coding", "fim");
			workers[17] = new WorkStudent("s021", "coding", "him");
			workers[18] = new WorkStudent("s027", "coding", "jim");
			workers[19] = new WorkStudent("s027", "coding", "jjj");


			for (int i = 0; i < 10; i++)
			{
				etable.Append(members[i]);

			}
			for (int i = 0; i < 20; i++)
			{
				wtable.Append(workers[i]);

			}
			break;
		case 2:
			// table의 모든 객체 출력하기
			//table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.

			etable.Print();
			wtable.Print();
			break;
		case 3:
			// table에서 객체 찾기

			e = etable.Read("kim");
			if (e == nullptr) cout << "kim이 존재하지 않는다" << endl;
			else
				e->Print();

			ws = wtable.Read("kim");
			if (ws == nullptr) cout << "kim이 존재하지 않는다" << endl;
			else
				ws->Print();
			break;
		case 4:
			//table에서 객체 삭제하기
			result = etable.Delete("hong");
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			result = wtable.Delete("hong");
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			break;
		case 5: 

			result = etable.Update("hong", *e);
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			result = wtable.Update("hong", *ws);
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			break;
		default:
			exit(0);

		}
	}
	system("pause");
	return 1;
}