#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILE1 "test.txt"
#define FILE2 "test1.txt"
#define FILE3 "combine.txt"
int main(int argc, char **argv) {
	if (argc != 3) {
		printf("参数错误!");
		exit(1);
	}
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");
	FILE* fp3 = fopen(FILE3, "w");
	char buf1[20];
	char buf2[20];
	char *p1 = buf1;
	char *p2 = buf2;
	
	if (fp1 == NULL) {
		printf("文件打开失败!");
		exit(1);
	}
	if (fp2 == NULL) {
		printf("文件打开失败!");
		exit(1);
	}
A:  while (fgets(buf1, 20, fp1) !=NULL) {
		while (fgets(buf2, 20, fp2) != NULL) {
			if (!strcmp(buf1, buf2)) {
				rewind(fp2);
				goto A;
			}
		}
		fprintf(fp3, "%s", buf1);
		rewind(fp2);
		printf("%s", buf1);
	}
	rewind(fp2);
	while (!feof(fp2)) {
		fgets(buf2, 21, fp2);
		fprintf(fp3, "%s", buf2);
		printf("%s", buf2);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
