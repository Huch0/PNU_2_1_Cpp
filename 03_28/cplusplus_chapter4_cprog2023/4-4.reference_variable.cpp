//4-4. reference_variable.cpp    4.3 pointer 변수와 reference 변수
#include <iostream>
using namespace std;
#define COLS 5
void update(int* const& p) {//참조 변수로 받는다 
    *p = 10;
    //p = nullptr;
}
void main(){      
    int a[COLS] = {10, 11, 12, 13, 14};
    int *pa[COLS];
    int (*ap)[COLS] = &a; 

    cout<<"<<ap 출력>>"<<endl;
    for(int i=0; i<COLS; i++){
        cout<<&a[i]<<"\t"<<&(*ap)[i]<<"\t" <<(*ap)+i<<"\t"	
             <<a[i]<<"\t" <<(*ap)[i]<<"\t"<<endl;
    }
    cout<<endl;

    int b[10];
    //int &ra[2] = {&b[0],&b[1],&b[2]};//array of reference를 사용할 수 없다
    //int &ra[11] = a;
    //int &ra[COLS] = {0,0,0,0,0};
    
    int (&ar)[COLS] = a; //배열 대신에 reference 사용
	//ar++;
    cout<<"<<ar 출력>>"<<endl;
    for(int i=0; i<COLS; i++)
        cout<<"ar[i] = "<<ar[i]<<"\t"<<"*(ar+i) = "<<*(ar+i)<<endl;
    cout<<endl;
    cout<<"<<ar[1] 대입 결과 출력>>"<<endl;
    ar[1] = *(ar + 1);     
    cout<<"*(ar+1) = "<<*(ar+1)<<"\t" <<"*(ar+2) = "<<*(ar+2)<<"\t" 
		<<"ar[1] = "<<ar[1]<<"\t" <<"ar[2] = "<<ar[2]<<endl;

    cout<<endl<<"<<reference변수 rfrn 출력>>"<<endl;
    int* const& rfrn = a;
    //int &const *rfrn = a; //reference에 대한 pointer를 사용할 수 없다
    rfrn[1] = rfrn[0] + 10;
	cout<<"&a[0] = "<<&a[0]<<"\t"<<"&a[1] = "<<&a[1]<<endl;
    cout<<"*(rfrn+1) = "<<*(rfrn+1)<<"\t" <<"rfrn[1] = "<<rfrn[1]<<endl;
    cout<<"(rfrn+1) = "<<(rfrn+1)<<"\t" <<"&rfrn[1] = "<<&rfrn[1]<<endl;
    int* const p = a;
    update(p);
	system("pause");
}