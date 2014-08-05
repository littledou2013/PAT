#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//M数组用来存放每个数集的个数
//num用来存放每个数集里面的数字
int M[50];
int num[50][10000];

float similarity(int a, int b)
{
	int index1 = 0, index2 = 0;
	int same = 0, different = 0;
	while (index1 < M[a] && index2 < M[b])
	{
		//将同一数集里相同的数字过滤掉，只留一个
		while(index1 < M[a] - 1 && num[a][index1] == num[a][index1+1])
			++index1;
		while(index2 < M[b] - 1 && num[b][index2] == num[b][index2+1])
			++index2;
		if (num[a][index1] == num[b][index2])
		{
			++same;
			++index1;
			++index2;
		} else if(num[a][index1] < num[b][index2])
		{
			++different;
			++index1;
		} else
		{
			++different;
			++index2;
		}
	}
	while (index1 < M[a])
	{
		while(index1 < M[a] - 1 && num[a][index1] == num[a][index1])
			++index1;
		++different;
		++index1;
	}
	while (index2 < M[b])
	{
		while(index2 < M[b] - 1 && num[b][index2] == num[b][index2])
			++index2;
		++different;
		++index2;
	}
	return same * 1.0 / (different + same ) * 100.0;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &M[i]);
		for (int j = 0; j < M[i] ; ++j)
			scanf("%d", &num[i][j]);
	}
	for (int i = 0; i < N; ++i)
		sort(num[i], num[i] + M[i]);
	int K;
	scanf("%d", &K);
	int a, b;
	for (int i = 0; i < K; ++i)
	{
		scanf("%d%d", &a, &b);
		printf("%.01f%%\n", similarity(a - 1, b - 1));
	}

}
