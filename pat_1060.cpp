#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N;
char str1[110], str2[110];
int getExp(char str[])
{
	//这里只要找小数点和第一个不为0的数字就可以了
	int index = 0;
	int last = 0;
	int length = strlen(str);
	while (index < length)
	{
		if (str[index] == '.')
			break;
		++index;
	}
	while (last < length)
	{
		if (str[last] <= '9' && str[last] >= '1')
			break;
		++last;
	}
	if (last == length)
		return 0;
	int result = index - last;
	if (result > 0)
		return result;
	else
		return result + 1;
}
void getPre(char str[])
{
	int index = 0;
	//首先把前面的0过滤掉
	int length = strlen(str);
	while(index < length)
		if (str[index] == '0' || str[index] == '.')
			++index;
		else
			break;
	int count = 0;
	while(index < length && count < N)
	{
		if (str[index] != '.')
		{
			str[count] = str[index];
			++count;
		}
		++index;
	}
	while(count < N)
	{
		str[count] = '0';
		++count;
	}
}
void printFloat(char str[], int n)
{
	printf("0.");
	for (int i = 0; i < N; ++i)
		printf("%c", str[i]);
	printf("*10^%d",n);
}
int main(void)
{
	//N:精度0-99
	scanf("%d%s%s", &N, &str1, &str2);
	//对于一个浮点数需要求两个东西
	int n1 = getExp(str1);
	int n2 = getExp(str2);
	getPre(str1);
	getPre(str2);
	bool is_same = true;
	if (n1 != n2)
		is_same = false;
	else
		for (int i = 0; i < N; ++i)
			if (str1[i] != str2[i])
			{
				is_same = false;
				break;
			}
	if (is_same)
	{
		printf("YES ");
		printFloat(str1,n1);
	}
	else
	{
		printf("NO ");
		printFloat(str1,n1);
		printf(" ");
		printFloat(str2,n2);
	}
	printf("\n");
	
	return 0;
}
