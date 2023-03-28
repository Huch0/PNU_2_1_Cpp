//4장-17 ostream.cpp   4.7 C++ file 입출력
#include <iostream>
#include <fstream>
using namespace std;
void main() {
    char ch;
    fstream file;
    char filename[10];
    cout <<"File name = "<<flush;
    cin >> filename;
    file.open(filename, ios::in);
    file.unsetf(ios::skipws);
    while (1) {
        cin >> ch;
        file << ch;
        if (file.fail()) break;
        cout << ch;
        cout.put(ch);
    }
    file.close();
	system("pause");
}