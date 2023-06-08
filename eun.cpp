#include <iostream> 
#include <cassert> 
#include <cstring> 

using namespace std ;

const int STRING_DEFAULT_LENGTH = 100 ; 
class MyString {
    char* str ;
    int size ; 
public:
    MyString() {
        size = 0;
        str = new char[size+1];
        str[size] ='\0' ;
    }
    MyString(const char* const s) { 
        assert (s != 0) ;
        size = strlen(s) ;
        str = new char[size+1] ;
        for ( int i = 0 ; i < size ; i ++ ) str[i] = s[i] ; 
        str[size] ='\0' ;
    }
    ~MyString() { delete [] str ; }
    MyString& operator = (const MyString& another) {
        delete [] str ;
        size = another.size ;
        str = new char[size+1] ;
        for ( int i = 0 ; i < size ; i ++ ) str[i] = another.str[i] ; 
        str[size] ='\0' ;
        return *this ;
    }

    MyString(const MyString& another) {
        size = another.size ;
        str = new char[size+1] ;
        for ( int i = 0 ; i < size ; i ++ ) str[i] = another.str[i] ; 
        str[size] ='\0' ;
    }

    void set(const char* const s) {
        assert (s != 0) ;
        size = strlen(s) ;
        delete [] str ;
        str = new char[size+1] ;
        for ( int i = 0 ; i < size ; i ++ ) str[i] = s[i] ; 
        str[size] ='\0' ;
    }
    bool isEqual(const MyString& another) const {
        if (strcmp(str, another.str) == 0 && size == another.size) 
            return 1;
        else 
            return 0;
    }

    void print() const {
        cout << str << endl;
    }

};


int main() {
	MyString strs[] = {
		MyString("C"),
		MyString(),
		MyString("Java")
	} ;
	strs[1].set("C++") ;

	const int arraySize = sizeof(strs) / sizeof(MyString);

	const MyString target("Java") ;
	for ( int i = 0 ; i < arraySize ; i ++ ) {
		const MyString str(strs[i]) ; // copy constructor
		if ( str.isEqual(target) ) {
			cout << "[" << i << "]: " ;
			str.print() ;
			break ;
		}
	}
	for ( const MyString& str : strs ) {
		str.print() ;
	}
}
