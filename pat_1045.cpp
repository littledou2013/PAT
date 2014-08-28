#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <climits>
using namespace std;
/*
	此题运用树最好，最后计算其分支
	存储的数据只需要是最喜欢的颜色，并且相邻颜色相同可以之存储一个
*/

int favorite[201];
//末尾是下标时最大长度
vector<int> number;
int strip[10000];

int main(void)
{
	//颜色数量
	int N, M, L;
	scanf("%d", &N);
	scanf("%d", &M);
	int color, index = 0;
	for (int i = 1; i <= N; ++i)
	{
		favorite[i] = -1;
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &color);
		//表示color色是第i个最喜欢的颜色，i = 1，为最喜欢
		favorite[color] = i;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; ++i)
	{
		scanf("%d", &color);
		if (favorite[color] != -1)
			strip[index++] = favorite[color];
	}
	number.resize(M);
	int minIndex;
	for (int i = 0; i < index; ++i)
	{
		minIndex = 0;
		for (int j = 1; j < M && j <= strip[i]; ++j)
		{
			 if (number[j] > number[minIndex])
				 minIndex = j;
		}
		number[strip[i]] = number[minIndex] + 1;
	}
	minIndex = 0;
	for (int i = 0; i < M; ++i)
	{
		if (number[i] > minIndex)
			minIndex = number[i];
	}
	printf("%d\n", minIndex);
	return 0;
}
