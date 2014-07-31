#include <iostream>
#include <cstdio>
using namespace std;

int num[510];
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	int coin;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &coin);
		num[coin]++;
	}
	int index = 1;
	if (M > 500)
	{
		index = M - 500;
	}
	while(index < M - index)
	{
		if (num[index] && num[M - index])
			break;
		++index;
	}
	if (index < M - index || (index == M - index && num[index] == 2) )
	{
		printf("%d %d", index, M - index);
	}
	else
	{
		printf("No Solution");
	}
	printf("\n");
	return 0;
}
