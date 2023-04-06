// 5-4.STATIC.CPP

#include <iostream>
using namespace std;

class Letters{
    char ch;
    static int num;
    public:
        Letters (char c) :ch (c){
            num ++;
            cout << "New letter " << c << ", the total number is " 
                 << num << endl;
        }
        ~Letters (){
            num --;
            cout << "Letter " << ch << " destroyed, ";
            if (num == 1)
                cout << "1 letter remains"<< endl;
            else
                cout << num << " letters remain" << endl;
        }
        char Value (){
            return ch;
        }
        static int Number (){
            return num;
        }
} ;

int Letters :: num = 0;
void main (){
    cout << "Program begins..." << endl;
    cout << "Number of letters at the beginning: " << Letters::Number() 
          << endl;

    Letters A ('a');
    Letters B ('b');
    Letters C ('c');
    Letters D ('d');
    cout << "Number of letters after declarations: "
          <<  A.Number() << endl << endl;

    //1¹ø ÁÖ¼®
    /*
    cout << "Entering a new block..." << endl;
    {
        Letters E ('e');
        Letters *pF;
        pF = new Letters ('f');

        cout << "Total number of letters inside the block: " 
              << A.Number() << endl;
        cout << endl;
        cout << "Leaving the block..." << endl;
        //delete pF; //pF °´Ã¼ ¼Ò¸ê
    }
    */
    cout << endl << "Total number of letters after the block: " 
          <<  Letters::Number() << endl;
}