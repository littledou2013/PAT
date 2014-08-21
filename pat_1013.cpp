#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/*
	使用并查集判断有多少个连通图，便可计算出需要多少根线，连接连通图
*/
vector<int> city[1000];
bool trans[1000];
int main(void)
{
	//N,城市总量,M,高速公路数,
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	int last, next;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d", &last, &next);
		city[last].push_back(next);
		city[next].push_back(last);
	}
	int broken;
	for (int i = 0;  i < K; ++i)
	{
		scanf("%d", &broken);
		/*
			本来此题最普通的方式是使用并查集来求连通图，但本人比较讨厌并查集，直接就是用对每一个结点进行广度遍历
		*/
		for (int j = 1; j <= N; ++j)
			trans[j] = false;
		trans[broken] = true;
		int count = 0;
		for (int j = 1; j <= N; ++j)
		{
			queue <int> vec;
			if (trans[j] == false)
			{
				//count记录的就是连通图的个数，
				++count;
				trans[j] = true;
				vec.push(j);
				while(!vec.empty())
				{
					int node = vec.front();
					vec.pop();
					for (int k = 0; k < city[node].size(); ++k)
					{
						if (trans[city[node][k]] == false)
						{
							trans[city[node][k]] = true;
							vec.push(city[node][k]);
						}
					}
				}
			}
		}
		printf("%d\n", count - 1);
	}
	return 0;
}
