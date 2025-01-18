#define _CRT_SECURE_NO_WARNINGS 1
//#include"sort.h"
//#include"stack.h"

#define N 1000000


//void MergeSortNonRtest()
//{
//	int a[] = {2,5,8,7,4,1,3,6,9,10};
//	Print(a, sizeof(a) / sizeof(int));
//	MergeSortNonR(a,sizeof(a)/sizeof(int));
//	Print(a, sizeof(a) / sizeof(int));
//}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	srand((size_t)time);

	//int* a1 = (int*)malloc(sizeof(int) * N);
	//int* a2 = (int*)malloc(sizeof(int) * N);
	//int* a3 = (int*)malloc(sizeof(int) * N);
	//int* a4 = (int*)malloc(sizeof(int) * N);
	//int* a5 = (int*)malloc(sizeof(int) * N);
	//int* a6 = (int*)malloc(sizeof(int) * N);
	//int* a7 = (int*)malloc(sizeof(int) * N);
	//int* a8 = (int*)malloc(sizeof(int) * N);
	//int* a9 = (int*)malloc(sizeof(int) * N);
	//int* a10= (int*)malloc(sizeof(int) * N);

	//for (int i = 0; i < N; i++)
	//{
	//	a1[i] = rand() + i;
	//	a2[i] = a1[i];
	//	a3[i] = a1[i];
	//	a4[i] = a1[i];
	//	a5[i] = a1[i];
	//	a6[i] = a1[i];
	//	a7[i] = a1[i];
	//	a8[i] = a1[i];
	//	a9[i] = a1[i];
	//	a10[i] = a1[i];

	//}
	vector<int> v1;
	vector<int> v2;

	for (size_t i = 0; i < N; i++)
	{
		v1.push_back(rand() + i);
		v2.push_back(rand() + i);
	}

	//int began1 = clock();
	//SelectSort(a1, N);
	//int over1 = clock();

	//int began2 = clock();
	//InsertSort(a2, N);
	//int over2 = clock();

	//int began3 = clock();
	//BubbleSort(a3, N);
	//int over3 = clock();

	int began4 = clock();
	sort_heap(v1.begin(),v1.end());
	int over4 = clock();

	//int began5 = clock();
	//ShellSort(a5, N);
	//int over5 = clock();

	int began6 = clock();
	sort(v2.begin(), v2.end());
	int over6 = clock();

	//int began7 = clock();
	//QuickSortNonR(a7, 0, N - 1);
	//int over7 = clock();

	//int began8 = clock();
	//MergeSort(a8, N);
	//int over8 = clock();

	//int began9 = clock();
	//MergeSortNonR(a9, N);
	//int over9 = clock();

	//int began10 = clock();
	//CountSort(a9, N);
	//int over10 = clock();

	//printf("SelectSort:%dms\n",over1 - began1);
	//printf("InsertSort:%dms\n", over2 - began2);
	//printf("BubbleSort:%dms\n", over3 - began3);
	printf("HeapSort:%dms\n", over4 - began4);
	//printf("SellSort:%dms\n", over5 - began5);
	printf("QuickSort:%dms\n", over6 - began6);
	//printf("QuickSortNonR:%dms\n", over7 - began7);
	//printf("MergeSort:%dms\n", over8 - began8);
	//printf("MergeSortNonR:%dms\n", over9 - began9);
	//printf("CountSort:%dms\n", over10 - began10);

	//MergeSortNonRtest();
	return 0;
}
