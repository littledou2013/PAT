#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100005;
//栈
vector<int> stack;
//树状数组
int c[N];
int lowbit(int value)
{
	return value & -value;
}
void add(int value, int count)
{
	while (value <= N)
	{
		c[value] += count;
		value += lowbit(value);
	}
}
int sum(int value)
{
	int sum = 0;
	while (value != 0)
	{
		sum += c[value];
		value -= lowbit(value);
	}
	return sum;
}
int find(int value)
{
	int low = 0, high = N - 1, media, res;
	while (low < high)
	{
		media = (low + high) / 2;
		res = sum(media);
		if (res < value)
			low = media + 1;
		else
			 high = media;
	}
	return high;
}
int main(void)
{
	int n, top = 0, value;
	char oper[12];
	scanf("%d", &n);
	stack.resize(n);
	while (n--)
	{
		scanf("%s", oper);
		if (oper[1] == 'u')
		{
			scanf("%d", &value);
			stack[top++] = value;
			add(value, 1);
		}
		else if (oper[1] == 'o')
		{
			if (top == 0)
				printf("Invalid\n");
			else
			{
				value = stack[--top];
				add(value, -1);
				printf("%d\n", value);
			}
		}
		else
		{
			if (top == 0)
				printf("Invalid\n");
			else
				printf("%d\n", find((top+1)/2));
		}
	}
	return 0;
}
