//2-11. ragged.cpp: 실습 예제 2.11
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
void raggedTable();
void raggedTable2();

int main(){
	int **T1;
	//1번 주석
	
	T1 = (int**)malloc(32);//2019 버젼은 pointer의 길이가 8바이트
	//T1 = (int**)malloc(16);
	T1[0] = (int*)malloc(4);
	//*T1 = (int*)malloc(4);
	T1[1] = (int*)malloc(8);
	//*(T1+1) = (int*)malloc(8);
	T1[2] = (int*)malloc(12);
	T1[3] = (int*)malloc(16);
<<<<<<< HEAD
	printf("\nsize of T1 = %u, size of T1[0]= %u\n", sizeof T1, sizeof T1[0]);
	printf("\nsize of *T1 = %u\n", sizeof(*T1));
=======
	printf("\nsize of T1 = %d, size of T1[0]= %d\n", sizeof T1, sizeof T1[0]);
	printf("\nsize of *T1 = %d\n", sizeof(*T1));
>>>>>>> a69560c9fda2ab25dbd07058ec63f0f9785b4aef
	printf("T1 = %p, T1[1] = %p, &T1[1] = %p\n", T1, T1+1, &T1[1]);

	T1[0][0]=0;
	T1[1][0]=1; T1[1][1]=2;
	T1[2][0]=3; T1[2][1]=4; T1[2][2]=5;
	T1[3][0]=6; T1[3][1]=7; T1[3][2]=8; T1[3][3]=9;
	
	int cnt = 1;
	printf("T1[][]의 원소 값\n");
	for(int i=0; i<4; i++){
		for(int j=0;j<cnt; j++){
			printf("%d ",T1[i][j]);
		}
		printf("\n");
		cnt++;
	}
	printf("\n");
	//T11[0][0]
	printf("**T1 = %d\n", **T1);
	//T1[1][0]
	printf("**(T1+1) = %d\n", **(T1 + 1));
	//T1[1][1]
	printf("*(*(T1+1)+1) = %d\n", *(*(T1 + 1) + 1));
	for (int i = 0; i < 4; i++)
	{
		free(T1[i]);
	}
	free(T1);

	//2번 주석
<<<<<<< HEAD
	/*
	raggedTable();
	*/

=======
	//*
	int** rt;
	raggedTable(rt);
	free(rt);

	//*/
>>>>>>> a69560c9fda2ab25dbd07058ec63f0f9785b4aef
	//3번 주석
	//배열명을 이용하여 열의 길이가 다른 배열의 원소에 접근하는 방법
	// raggedTable2() 호출 작성 부분
	//*
	raggedTable2();
	//*/
	system("pause");
	return 0;
}


<<<<<<< HEAD
void raggedTable() {
	int** T2;
=======
void raggedTable(int **tx) {
>>>>>>> a69560c9fda2ab25dbd07058ec63f0f9785b4aef
	int row, col;
	int rowIndex;
	static int counter = 0;
	printf("행의 수를 입력하세요:");
	scanf_s("%d", &row);
	//calloc(할당된 원소의 개수, 할당된 원소의 크기)
	tx = (int **)calloc(row, sizeof(int*)); 
	for (rowIndex = 0; rowIndex < row; rowIndex++) {
<<<<<<< HEAD
		printf("	%행에 대한 열의 수를 입력하세요: ");
=======
		printf("%행에 대한 열의 수를 입력하세요:",rowIndex);
>>>>>>> a69560c9fda2ab25dbd07058ec63f0f9785b4aef
		scanf("%d", &col);
		tx[rowIndex] = (int *)calloc(col+1, sizeof(int));
		//각 행의 첫 열에 열의 개수 저장
		for (int j = 0; j < col; j++)
		{
<<<<<<< HEAD
			T2[rowIndex][j] = counter++;
			printf("%d ", T2[rowIndex][j]);
		}
	}

	// 동적할당 받은 2차원 배열의 경우 1차원 배열을 먼저 해제한 후 double pointer를 free해야 함.
=======
			tx[rowIndex][j] = counter++;
			printf("%d ", tx[rowIndex][j]);
		}
		// raggedTable에 치환하는 문장을 실습 코드로 추가

	}

	// 동적할당 받은 2차원 배열의 경우 1차원 배열을 먼저 해제한 후 더블포인터를 해제해야 함.
>>>>>>> a69560c9fda2ab25dbd07058ec63f0f9785b4aef
	//*
	for (rowIndex = 0; rowIndex < row; rowIndex++)
	{
		free(tx[rowIndex]);
	}
<<<<<<< HEAD
	free(T2);
=======
>>>>>>> a69560c9fda2ab25dbd07058ec63f0f9785b4aef
	//*/
	return;
}
void raggedTable2() {
	char** T3;
	int row, col;
	int rowIndex;
	static char counter = 'A';
	printf("행의 수를 입력하세요:");
	scanf_s("%d", &row);
	//calloc(할당된 원소의 개수, 할당된 원소의 크기)
	T3 = (char**)calloc(row, sizeof(char*));
	for (rowIndex = 0; rowIndex < row; rowIndex++) {
		printf("	%행에 대한 열의 수를 입력하세요: ", rowIndex);
		scanf("%d", &col);
		T3[rowIndex] = (char*)calloc(col + 1, sizeof(char));
		//각 행의 첫 열에 열의 개수 저장
		for (int j = 0; j < col; j++)
		{
			T3[rowIndex][j] = counter++;
			printf("%c ", T3[rowIndex][j]);
		}
	}

	// 동적할당 받은 2차원 배열의 경우 1차원 배열을 먼저 해제한 후 double pointer를 free해야 함.
	//*
	for (rowIndex = 0; rowIndex < row; rowIndex++)
	{
		free(T3[rowIndex]);
	}
	free(T3);
	//추가 작성할 코드
	return;
}