#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

#if 1

size_t my_strlen(const char* s)
{
	assert(s != NULL);
	size_t count = 1;
	if (*s != '\0') 
	{
		return count+my_strlen(s + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char str[] = "abcdefg";
	printf("%zd\n",my_strlen(str));
	return 0;
}

#endif