#include <cstdio>
/*
	pat 1065: 输入数据范围其实是比长长整数大一点的，而在解题中这一点根本就没做考虑。
	本题主要是考虑相加后溢出问题，只存在两种情况会溢出，一种是两个正数相加，一种是两个负数相加
	如果溢出，其结果的符号都会为0或反过来的。
*/
int main(void)
{
	int n, i ;
	long long int a, b, c;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		bool flag = true;
		scanf("%lld%lld%lld", &a, &b, &c);
		long long ans = a + b;
		//一定要判断ans是否大于等于0
		if ( a > 0 && b > 0 && ans < 0) flag = true;
		else if ( a < 0 && b < 0 && ans >= 0) flag = false;
		else if (ans <= c) flag = false;
		if (flag)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	return 0;
}
