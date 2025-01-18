#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void fun(int* arr, int len)
{
	int backup[100000] = { 0 };
	for (int i = 0; i < len; i++)
	{
		backup[i] = arr[i];
	}
	int x = 0;
	for (int i = 0; i < len; i++)
	{
		if (*(backup+i) % 2 == 1)
		{
			arr[x] = *(backup + i);
			x++;
		}
	}
	int y = x;
	for (int i = 0; i < len; i++)
	{
		if (*(backup + i) % 2 == 0)
		{
			arr[y] = *(backup + i);
			y++;
		}
	}
}

int main()
{
	int arr[] = { 4565,564486,456,5416,5416,4516,415,8974,45,5641,4897 };
	         
	size_t len = sizeof(arr) / sizeof(arr[0]);      

	for (int i = 0; i < len; i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");

	fun(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}

	printf("\n");

	return 0;
}

#if 0

char* left_round(char* str, int len,int k)
{
	if (k != 1)
	{	
		char x = *str;
		int i = 0;
		for (i = 0; i < len; i++)
		{
			*(str + i) = *(str + i + 1);
		}
		*(str + i-1) = x;
		return left_round(str, len, k - 1);
	}
	else
	{
		char x = *str;
		int i = 0;
		for (i = 0; i < len; i++)
		{
			*(str + i) = *(str + i + 1);
		}
		*(str + i - 1) = x;
		return str;
	}
}

int main()
{
	char ch[] = "ABCD";

	int sz = strlen(ch);

	puts(ch);

	int k = 0;

	scanf("%d",&k);

	puts(left_round(ch, sz, k));

	return 0;
}

void fun(char* str,int lens)
{
	for (int i = 0; (str+i)<(str+lens-2-i) ; i++)
	{
		char s = *(str + i);
		*(str + i) = *(str +lens-2- i);
		*(str + lens-2 - i) = s;
	}
}
int main()

{
	char ch[] = "abcdef";

	int sz = sizeof(ch);

	puts(ch);

	fun(ch, sz);

	puts(ch);

	return 0;
}
#endif