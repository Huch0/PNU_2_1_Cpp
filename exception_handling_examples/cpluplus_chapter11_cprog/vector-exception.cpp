#include <iostream>
#include <stdexcept>

template <typename T>
class Bag {
	//no ordering, duplate
public:
	Bag();
	~Bag() :
	virtual	void Add(const T&);
	virtual T * Delete(T&);
	virtual bool IsFull();
	virtual bool IsEmpty();
private:
	T *data;
	int sizeBag;
	int top;
};
template <typename T>
class Set : public Bag {
	//no ordering, no duplicate
public:
	Set();
	~Set();
	void Add(const T&);
	T * Delete(T&);
	bool IsFull();
	bool IsEmpty();
};
template <typename T>
class Vector : public Set {
	//ordering, no duplicaTE
public:
	Vector();
	~Vector();
	void Add(const T&);
	T * Delete(T&);
	bool IsFull();
	bool IsEmpty();
};
class ContainerError {
public:
	virtual void Print();
};
class BagError : public ContainerError {
//
};
class SetError : public BagError {
	//
};
class VectorError : public SetError {
	//
};
int main() {
	try {
		Bag<char*> b;
		Set<char *> s;
		Vector<char*> v;
		while ()
		{
			b.Add();
			s.Add();
			v.Add();
		}
		while ()
		{
			b.Delete();
			s.Delete();
			v.Delete();
		}
	}
	catch (ContainerError) {
		//
	}
}