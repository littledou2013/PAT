#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	a += b;
	char str[10];
	bool is_neg = false;
	int index = 0;
	if (a < 0)
	{
		a = -a;
		str[0] = '-';
		is_neg = true;
	}
	//先判断是否为0
	if (a == 0)
		str[index++] = '0';
	//地位放在数组前面，然后倒叙输出
	//一般,会放在3，7，11，这些地方
	while(a!=0)
	{
		if((index + 1) % 4 == 0)
		{
			str[index++] = ',';
		}
		str[index++] = a%10+'0';
		a /= 10;
	}
	if (is_neg)
		str[index++] = '-';
	for (int i = index - 1; i >= 0; --i)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}
