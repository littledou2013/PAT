#include <iostream>
#include <cstdio>
using namespace std;

int dist[100002];
int cdist[100002];
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &dist[i]);
	int M;
	//正转
	cdist[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		cdist[i] = cdist[i-1] + dist[i-1];
	}
	int sum = cdist[N] + dist[N];
	scanf("%d", &M);
	int a, b;
	int result1, result2;
	for (int i = 1; i <= M; ++i)
	{
		scanf("%d%d", &a, &b);
		//要使b大于a
		if ( a > b)
		{
			int temp = b;
			b = a;
			a = temp;
		}
		result1 = cdist[b] - cdist[a];
		result2 = sum + cdist[a] - cdist[b];
		if (result1 < result2)
			printf("%d\n", result1);
		else
			printf("%d\n", result2);
	}
	return 0;
}
