#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<string.h>
#include"stack.h"

void Print(int* a, int n);
void Swap(int* x, int* y);
void BubbleSort(int* a, int n);
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void QuickSort(int* a, int left, int right);
int Midofthree(int* a,int x, int y, int z);
void QuickSortNonR(int* a, int left, int right);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void CountSort(int* a, int n);