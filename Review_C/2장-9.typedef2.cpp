// 2장-9 typedef2.cpp
#include <stdio.h>
#include <stdlib.h>
//prototype declaration
typedef struct {
	int x;
	int y;
	float value;
}SAMPLE; 
SAMPLE *merge(SAMPLE *fst, SAMPLE *snd);

void main(void){
    SAMPLE *mid;
	SAMPLE first = {1,1,1.123};
	SAMPLE second = {2,2,2.234};
    mid = merge(&first, &second);
	printf("\nAfter call mid=merge()\n");
	printf("mid 값 출력\n");
	printf("mid x값 출력 : %d\n", mid->x);//wrong value 출력
	printf("mid y값 출력 : %d\n", mid->y);//wrong value 출력
	printf("mid value값 출력 : %f\n\n", mid->value);//wrong value 출력
	system("pause");
}

SAMPLE *merge(SAMPLE *f, SAMPLE *s){   //return by pointer
	SAMPLE temp;
	temp.x = f->x + s->x; temp.y = f->y + s->y;
	temp.value = f->value + s->value;
	printf("mid 값 출력\n");
	printf("mid x값 출력 : %d\n", temp.x);
	printf("mid y값 출력 : %d\n", temp.y);
	printf("mid value값 출력 : %f\n", temp.value);
	return &temp;
}