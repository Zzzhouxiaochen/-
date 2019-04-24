#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main()
{
	int i,k,j;
	int a[11];
	printf("请输入十个数字：\n");
	for (i = 0; i < 11; i++)
	{
		scanf("%d", &a[i]);
	}
	for (j = 1; j <= 9; j++) //排数次数
	{
		for (i = 1; i < 10 - j; i++) //每次交换次数
		{
			if (a[i] > a[i + 1])
			{
				k = a[i];
				a[i] = a[i + 1];
				a[i + 1] = k;
			}
		}
	}
	printf("排序之后的结果：\n");
	for (i = 1; i < 11; i++)
	{
		printf("%5d", a[i]);
	}
	system("pause");
	return 0;
}