// 2Àå-7 static.cpp
#include <stdio.h>
#include <stdlib.h>
static int total = 0;   // static definition, internal linkage, static storage duration
void fcn(void);

void main() {
    fcn();
	fcn();
	fcn();
	printf("main():: total = %d\n", total);
	system("pause");
}

void fcn() {
    static int counter = 0;//static º¯¼ö
    counter++;
	printf("fcn::counter = %d\n\n", counter);
	total += counter;
}