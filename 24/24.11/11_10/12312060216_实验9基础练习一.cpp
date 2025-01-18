#define _CRT_SECURE_NO_WARNINGS 1

# include <stdio.h>
int search(int A[], int x, int n)
{
	int i = 0;
	while (i < n && A[i] != x)
		i++;
	if (i >= n)
		return -1;
	else
		return i;
}
int main()
{
	int a[] = { 2,5,56,10,12,15,8,19,25,32 }, n, d,i;
	printf("A数值\n 下标");
	for (i = 0; i < 10; i++)
		printf("%3d", i);
	printf("\n值");
	for (i = 0; i < 10; i++)
		printf("%3d", a[i]);
	printf("\n输入值：");
	scanf("%d", &d);
	n = search(a, d, 10); 
	if (n >= 0)
		printf("A[%d]=\n", d);
	else
		printf("%d 未找到\n", d);
	return 0;
}