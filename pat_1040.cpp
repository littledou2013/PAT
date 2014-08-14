#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
/*
	求最长回文串
	使用中心扩散法

*/
char str[1001];
char str1[2005];
/*int main(void)
{
	gets(str);
	int length = strlen(str);
	str1[0] = '#';
	int index = 1;
	for (int i = 0; i < length; ++i)
	{
		str1[index++] = str[i];
		str1[index++] = '#';
	}
	length = index;
	int i, j;
	int max = 1, count;
	for (int index = 0;index < length; ++index)
	{
		i = index - 1;
		j = index + 1;
		count = 0;
		while(i >= 0 && j < length && str1[i] == str1[j])
		{
			++count;
			--i;
			++j;
		}
		if (count > max)
			max = count;
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}*/
//	进一步优化的方法，最大化利用前面计算的结构
int id[2005];
int main(void)
{
	gets(str);
	int length = strlen(str);
	str1[0] = '#';
	int index = 1;
	for (int i = 0; i < length; ++i)
	{
		str1[index++] = str[i];
		str1[index++] = '#';
	}
	length = index;
	id[0] = 0;
	index = 0;
	int max = index + id[0];
	int count = 0;
	for (int i = 1; i < length; ++i)
	{
		if (i < max)
		{
			int j = 2 * index  - i;
			if (id[j]  <= max - i)
				id[i] = id[j];
			else
				id[i] = max - i;
		}
		while(i - id[i] >= 0 && i + id[i] < length && str1[i - id[i]] == str1[i +id[i]])
		{
			++id[i];
		}
		if (id[i] > count)
			count = id[i];
	}
	
	printf("%d\n", count - 1);
	return 0;
}
