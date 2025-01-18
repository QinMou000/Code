#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int countSeniors(char** details, int detailsSize)
{
	int ans = 0;
	for (int i = 0; i < detailsSize; i++)
	{
		int age = 0;
		age += (details[i][11] - '0') * 10;
		age += (details[i][12] - '0');
		if (age > 60)
			ans++;
	}
	return ans;
}

int main()
{
	char s[][15] = { "7868190130M7522","5303914400F9211","9273338290F4010","5303914400F9211"};
	int len = sizeof(s) / sizeof(*s);
	printf("%d\n", countSeniors(s, len));
	return 0;
}
