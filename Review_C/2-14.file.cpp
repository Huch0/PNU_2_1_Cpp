//2-14. file.cpp: 실습예제 2.14
#include <stdio.h>
#include <stdlib.h>

void main(){	
	char word[1024]="";	
	char filename[20];
	FILE * readFile;
	FILE * writeFile;	

	printf("\n내용을 추가할 file 명을 입력하세요(ex : test.txt)\n");
	scanf("%s", &filename);
	printf("내용을 입력하세요->\n");
	writeFile = fopen(filename, "a");
	scanf("%s", &word);
	printf("word = %s\n", word);
	fprintf(writeFile, word);
	fclose(writeFile);
	printf("--------file출력--------\n");
	readFile = fopen(filename, "r");
	while(fread(word, 1, 1024, readFile) != 0){		
		printf("the result of fread() = %s", word);
	}
	fclose(readFile);	

	printf("\n");
	system("pause");
}