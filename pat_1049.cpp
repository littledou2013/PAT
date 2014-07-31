#include <iostream>
#include <cstdio>
using namespace std;

int num[10];
//num[10]保存的是0以下，10以下，100以下……1000000000（10的九次方）以下有多少个1（不包含本身）
void initial()
{
	//初始化num[0] = 0;
	//后面元素可以由前一个元素得出
	num[0] = 0;
	int index = 1;
	int factor = 1;
	while (index < 10)
	{
		//关键理解代码
		num[index] = 10 * num[index - 1] +factor;
		factor *= 10;
		++index;
	}
}
int main(void)
{
	initial();
	int n;
	scanf("%d", &n);
	int tt = 9;
	int fa = 1000000000;
	//找出n的数量级
	while(n / fa == 0)
	{
		fa /= 10;
		--tt;
	}
	int remain;
	int result = 0;

	//tt代表n还有多少位数
	while(tt != -1)
	{
		remain = n % fa;
		n /= fa;
		result += n * num[tt];
		if (n > 1)
			result += fa;
		else if(n == 1)
			result += remain + 1;
		fa /= 10;
		n = remain;
		--tt;
	}
	printf("%d\n", result);
	return 0;
}
