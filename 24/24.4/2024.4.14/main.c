#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//bool isThree(int n)
//{
//	int count = 0;
//	if (n == 2)
//		return 0;
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//			count++;
//	}
//	if (count == 1)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	isThree(12);
//	return 0;
//}

//bool IsPalindrome(char* word, int size)
//{
//    int left = 0;
//    int right = size - 1;
//    while (left < right)
//    {
//        if (word[left] != word[right])
//        {
//            return false;
//        }
//        left++;
//        right--;
//    }
//    return true;
//}
//
//char* firstPalindrome(char** words, int wordsSize)
//{
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int len = strlen(words[i]);
//        if (IsPalindrome(words[i], len) == true)
//        {
//            return words[i];
//        }
//    }
//    return "";
//}

int cmp(const void* x, const void* y)
{
	return *(int*)y - *(int*)x;
}

int minimumCost(int* cost, int costSize)
{
	if (costSize < 2)
		return cost[0];
	qsort(cost, costSize, sizeof(int), cmp);
	int sum = 0;
	for (int i = 0; i < costSize; i++)
	{
		if ((i + 1) % 3 != 0)
			sum += cost[i];
	}
	return sum;
}
int main()
{
	int cost[] = { 6,5,7,9,2,2 };
	int len = sizeof(cost) / sizeof(cost[0]);
	printf("%d\n", minimumCost(cost,len));
	return 0;
}

