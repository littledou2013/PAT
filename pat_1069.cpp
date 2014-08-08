#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
	此题思路，输入整数，将此整数使用0填充为4位，求出该整数重新排序后的最大整数和最小整数，
	此题需注意，遇到6174这个特殊的数字需要先输出一次，然后中断，
	所有使用do-while循环保证一定会执行一次
*/
void inttostr(int n, int &a, int &b)
{
	while (n < 1000)
			n *= 10;
	int div = 1000;
	char str[4];
	int index = 0;
	while(div != 0)
	{
		str[index++] = n / div + '0';
		n %= div;
		div /= 10;
	}
	sort(str, str+4);
	for (int i = 0; i < 4; ++i)
	{
		b *= 10;
		b += str[i] - '0';
	}
	for (int i = 3; i >= 0; --i)
	{
		a *= 10;
		a += str[i] - '0';
	}

}

int main(void)
{
	while(true){
	int n;
	scanf("%d", &n);
	int a, b;
	do{
		a = b = 0;
		inttostr(n, a, b);
		n = a - b;
		printf("%04d - %04d = %04d\n", a, b, n);
	}while(n != 0 && n != 6174);
	return 0;
}
