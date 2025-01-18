#define _CRT_SECURE_NO_WARNINGS 1

//
#include <stdio.h>
#include <windows.h>
//int main()
//{
//    float x, y, z;
//    for (y = 1.5f; y > -1.5f; y -= 0.1f)
//    {
//        for (x = -1.5f; x < 1.5f; x += 0.05f)
//        {
//            z = (float)(x * x + y * y - 1);
//            putchar(z * z * z - x * x * y * y * y <= 0.0f ? '@' : ' ');
//        }
//        system("color 04");
//        putchar('\n');
//    }
//    printf("                          我是大帅B!               \n");
//    return 0;
//}
//
//int hammingDistance(int x, int y)
//{
//	int count = 0;
//
//	for (int i = 0; i < 32; i++)
//	{
//		if ((x & 1) != (y & 1))
//			count++;
//		x >>= 1;
//		y >>= 1;
//	}
//	return count;
//}
//
//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	
//	printf("%d\n", hammingDistance(x, y));
//	return 0;
//}

//int countSegments(char* s)
//{
//	char* x = " ";
//	int ans = 0;
//	if (strtok(s, x) != NULL)
//		ans++;
//	for (; strtok(NULL, x) != NULL; ans++)
//		;
//	return ans;
//}
//
//int main()
//{
//	char str[20] = { '0' };
//	gets(str);
//	printf("%d\n", countSegments(str));
//	return 0;
//}

//char* addStrings(char* num1, char* num2)
//{
//	char* ch = *num1 + *num2;
//	return ch;
//}
//
//int main()
//{
//	char* num1 = "123";
//	char* num2 = "456";
//	printf("%s", addStrings(num1, num2));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int input = 0;
//	printf("加入比特\n");
//	printf("要好好学习吗(1/0)?");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("一个好offer\n");
//	}
//	else
//	{
//		printf("卖红薯\n");
//	}
//	return 0;
//}

