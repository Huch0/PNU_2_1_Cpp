//4장-6. ReferenceExample.cpp   4.4.3 reference에 의한 함수 parameter 전달
#include <iostream>
using namespace std;
void swap(int value_a, int value_b); //call by value
void swap(int *pointer_a, int *pointer_b); //call by pointer
void swap_ref(int &reference_a, int &reference_b); //call by reference
//void swap(int& reference_a, int& reference_b); // 오류 발생함
void main(){
    int num_1 = 10, num_2 = 20;
    cout << "call by value" << endl;
    swap (num_1, num_2);
    cout << "after swap (num_1, num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;

    cout << endl << "call by pointer" << endl;
	swap (&num_1, &num_2); 
	cout << "after swap (&num_1, &num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;
	num_1 = 10; num_2 = 20;

    cout << endl << "call by reference" << endl;
    swap_ref (num_1, num_2); 
	cout << "after swap_ref (num_1, num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;

	system("pause");
}


void swap(int value_a, int value_b){
    cout << "swap(int,int) ";
    int temp;
    temp = value_a;
    value_a = value_b;
    value_b = temp;
}

void swap(int *pointer_a, int *pointer_b){
    cout << "swap(int*, int*) ";
    int temp;
    temp = *pointer_a;
    *pointer_a = *pointer_b;
    *pointer_b = temp;
}

void swap_ref(int &reference_a, int &reference_b){
    cout << "swap_ref(int&, int&) ";
    int temp;
    temp = reference_a;
    reference_a = reference_b;
    reference_b = temp;
}