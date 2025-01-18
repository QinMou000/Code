#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//struct _iobuf {
//	char* _ptr;
//	int _cnt;
//	char* _base;
//	int _flag;
//	int _file;
//	int _charbuf;
//	int _bufsiz;
//	char* _tmpfname;
//};
//typedef struct _iobuf FILE;
//
//typedef struct _iobuf
//{
//	void* _Placeholder;
//} FILE;

//int main()
//{
//	//FILE* pf;//⽂件指针变量
//	/* fseek example */
//	FILE* pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	/*
//	SEEK_SET    文件起始位置
//	SEEK_CUR	文件指针的当前位置
//	SEEK_END	文件末尾
//	*/
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}

///* ftell example : getting size of a file */
//#include <stdio.h>
//int main()
//{
//	long size;
//	FILE* pFile = fopen("myfile.txt", "rb");
//	if (pFile == NULL)
//		perror("Error opening file");
//	else
//	{
//		fseek(pFile, 0, SEEK_END); // non-portable
//		size = ftell(pFile);
//		fclose(pFile);
//		printf("Size of myfile.txt: %ld bytes.\n", size);
//	}
//	return 0;
//}

///* rewind example */
//#include <stdio.h>
//int main()
//{
//	int n;
//	FILE* pFile;
//	char buffer[27];
//	pFile = fopen("myfile.txt", "w+");
//	for (n = 'A'; n <= 'Z'; n++)
//		fputc(n, pFile);//将A到Z放进文件里面
//	rewind(pFile);//返回文件开头，准备打印
//	fread(buffer, 1, 26, pFile);//将文件里面读到的数据放到buffer里面
//	fclose(pFile);
//	pFile = NULL;
//	buffer[26] = '\0';
//	printf(buffer);//打印
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//	int c; // 注意：int，⾮char，要求处理EOF
//	FILE* fp = fopen("test.txt", "r");
//	if (!fp) {
//		perror("File opening failed");
//		return EXIT_FAILURE;
//	}
//	//fgetc 当读取失败的时候或者遇到⽂件结束的时候，都会返回EOF
//	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取⽂件循环
//	{
//		putchar(c);
//	}
//	//判断是什么原因结束的
//	if (ferror(fp))
//		puts("I/O error when reading");
//	else if (feof(fp))
//		puts("End of file reached successfully");
//	fclose(fp);
//}

//#include <stdio.h>
//enum { SIZE = 5 };
//int main()
//{
//	double a[SIZE] = { 1.,2.,3.,4.,5. };
//	double b[SIZE] = { 0 };
//	FILE* fp = fopen("test.bin", "wb"); // 必须⽤⼆进制模式
//	fwrite(a, sizeof * a, SIZE, fp); // 写 double 的数组
//	fclose(fp);
//	fp = fopen("test.bin", "rb");
//	size_t ret_code = fread(b, sizeof * b, SIZE, fp); // 读 double 的数组
//	if (ret_code == SIZE) {
//		puts("Array read successfully, contents: ");
//		for (int n = 0; n < SIZE; ++n)
//			printf("%f ", b[n]);
//		putchar('\n');
//	}
//	else { // error handling
//		if (feof(fp))
//			printf("Error reading test.bin: unexpected end of file\n");
//		else if (ferror(fp)) {
//			perror("Error reading test.bin");
//		}
//	}
//	fclose(fp);
//	fp = NULL;
//}

#include <stdio.h>
#include <windows.h>
//VS2022 WIN11环境测试
int main()
{
	FILE* pf = fopen("test.txt", "w");
	fputs("abcdef", pf);//先将代码放在输出缓冲区
	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
	Sleep(10000);
	printf("刷新缓冲区\n");
	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到⽂件（磁盘）
	//注：fflush 在⾼版本的VS上不能使⽤了
	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
	Sleep(10000);
	fclose(pf);
	//注：fclose在关闭⽂件的时候，也会刷新缓冲区
	pf = NULL;
	return 0;
}