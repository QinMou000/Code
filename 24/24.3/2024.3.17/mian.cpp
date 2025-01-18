#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>

//int main()
//{
//    int n = 9;
//    float* pFloat = (float*)&n;
//
//    printf("n的值为：%d\n", n);
//    printf("*pFloat的值为：%f\n", *pFloat);
//
//    *pFloat = 9.0;
//
//    printf("num的值为：%d\n", n);
//    printf("*pFloat的值为：%f\n", *pFloat);
//
//    return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//
//int atoi_my(const char* str)
//{
//	int s = 0;
//	bool flag = false;
//
//	while (*str == ' ')
//	{
//		str++;
//	}
//
//	if (*str == '-' || *str == '+')
//	{
//		if (*str == '-')
//			flag = true;
//		str++;
//	}
//
//	while (*str >= '0' && *str <= '9')
//	{
//		s = s * 10 + *str - '0';
//		str++;
//		if (s < 0)
//		{
//			s = 2147483647;
//			break;
//		}
//	}
//	return s * (flag ? -1 : 1);
//}



//int main()
//{
//	const char* s1 = "333640";
//	const char* s2 = "-12345";
//	const char* s3 = "123.3113";
//	const char* s4 = "-8362865623872387698";
//	const char* s5 = "+246653278";
//
//
//	int sum1 = atoi(s1);
//	int sum_1 = atoi_my(s1);
//
//	int sum2 = atoi(s2);
//	int sum_2 = atoi_my(s2);
//
//	int sum3 = atoi(s3);
//	int sum_3 = atoi_my(s3);
//
//	int sum4 = atoi(s4);
//	int sum_4 = atoi_my(s4);
//
//	int sum5 = atoi(s5);
//	int sum_5 = atoi_my(s5);
//
//	cout << "atoi:  :" << sum1 << endl;
//	cout << "atoi_my:" << sum_1 << endl;
//
//	cout << "atoi:  :" << sum2 << endl;
//	cout << "atoi_my:" << sum_2 << endl;
//
//	cout << "atoi:  :" << sum3 << endl;
//	cout << "atoi_my:" << sum_3 << endl;
//
//	cout << "atoi:  :" << sum4 << endl;
//	cout << "atoi_my:" << sum_4 << endl;
//
//	cout << "atoi:  :" << sum5 << endl;
//	cout << "atoi_my:" << sum_5 << endl;
//
//	system("pause");
//	return 0;
//}

//int my_atoi(const char* str)
//{
//	assert(str);
//
//	const char* tmp = str;
//	while (*tmp == ' ')  // 跳过空格字符
//		tmp++;
//	int num = 0; // 转换数字字符值的接收变量
//	
//	while (*tmp <= 57 && *tmp >= 48)// 如果是数字字符，就进来，到不连续处就停止
//	{
//		num = num * 10 + (*tmp - '0');
//
//		if (*(tmp + 1) < 48 || *(tmp + 1) > 57)
//		{
//			return num;
//		}
//		tmp++;
//	}
//	// 如果开始判断的字符不是数字字符，前面的循环不进去，这里直接返回0
//	return 0;
//}
//int main()
//{
//	char a[] = "";
//	char b[] = "     ";
//	char c[] = "66666";
//	char d[] = "    @. 66ab";
//	char e[] = "    6666@qq.com";
//	char f[] = "520hehe";
//	char g[] = "i love you 555";
//
//	printf("%d\n", my_atoi(a)); // 0
//	printf("%d\n", my_atoi(b)); // 0
//	printf("%d\n", my_atoi(c)); // 66666
//	printf("%d\n", my_atoi(d)); // 0
//	printf("%d\n", my_atoi(e)); // 6666
//	printf("%d\n", my_atoi(f)); // 520
//	printf("%d\n", my_atoi(g)); // 0
//
//	return 0;
//}

int fun()
{
	int a = 1;
	return *(char*)&a;
}

int main()
{
	printf("%d\n", fun());
	return 0;
}