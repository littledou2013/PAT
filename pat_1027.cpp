#include <iostream>
#include <cstdio>
using namespace std;

void e2m(int n, char* str)
{
	int index = 0;
	if (n == 0)
		str[index++] = '0';
	while (n != 0)
	{
		if (n % 13 >= 10)
		//注意这里需要判断余数是否大于10
			str[index++] = n % 13 - 10 + 'A';
		else
			str[index++] = n % 13 + '0';
		n /= 13;
	}
	if (index == 1)
		str[index++] = '0';
	str[index] = '\0';
	char ch;
	for (int i = 0, j = index - 1; i < j; ++i, --j)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}
int main(void)
{

	int a, b, c;
	char stra[4], strb[4], strc[4];
	scanf("%d%d%d", &a, &b, &c);
	e2m(a, stra);
	e2m(b, strb);
	e2m(c, strc);
	printf("#%s%s%s\n",  stra, strb, strc);
	return 0;
}
