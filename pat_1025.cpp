#include <iostream>
#include <cstdio>
using namespace std;

#define SIZE 1000000

long int num1[SIZE];
long int num2[SIZE];

int main(void)
{
	int n1,n2;
	scanf("%d", &n1);
	for (int i = 0; i < n1; ++i)
		scanf("%ld", &num1[i]);
	scanf("%d", &n2);
	for (int i = 0; i < n2; ++i)
		scanf("%ld", &num2[i]);
		
	//计算中间数字在第几位
	int mid = (n1 + n2 + 1) / 2;
	//count标记一次遍历了多少为，index标记数组遍历的下标
	int count = 0, index1 = 0, index2 = 0;
	long int median;
	while (index1 < n1 && index2 < n2 && count < mid)
	{
		if (num1[index1] <= num2[index2])
		{
			median = num1[index1];
			++index1;
		}
		else 
		{
			median = num2[index2];
			++index2;
		}
		++count;
	}
	while (index1 < n1&& count < mid)
	{
		median = num1[index1];
		++index1;
		++count;
	}
	while (index2 < n2 && count < mid)
	{
		
		median = num2[index2];
		++index2;
		++count;
	}
	printf("%ld\n", median);
	return 0;
}
