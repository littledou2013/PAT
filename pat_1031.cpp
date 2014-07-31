#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//把字符按输出顺序重新排列后放入str1字符数组中
char str[81];
char str1[81];
int main(void)
{
	scanf("%s", str);
	int length = strlen(str);
	int n1, n2 = (length + 2) / 3;
	n1 = length + 2 - 2 * n2;
	--n2;
	int index1 = 0;
	int index2 = length - 1;
	int count = 0;
	while (index1 < n2)
	{
		str1[count++] = str[index1];
		str1[count++] = str[index2];
		++index1;
		--index2;
	}
	while(index1 < n1 + n2)
	{
		str1[count++] = str[index1];
		++index1;
	}
	n2 *= 2;
	index1 = 0;
	while (index1 < n2)
	{
		printf("%c", str1[index1++]);
		for (int i = 0; i < n1 - 2; ++i)
			printf(" ");
		printf("%c\n", str1[index1++]);
	}
	while(index1 < length)
		printf("%c", str1[index1++]);
	printf("\n");
	return 0;
}
