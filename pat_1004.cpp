#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/*
	比较难，方法可取巧
	先构建这棵树，再遍历这棵树
*/
vector<int> Node[101];
int level[101];
queue <int> que;
int num[101];
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	int node, child, number;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d", &node, &number);
		for (int j = 0; j < number; ++j)
		{
			scanf("%d", &child);
			Node[node].push_back(child);
		}
	}
	//计算每个结点所属的层次
	level[1] = 0;
	que.push(1);
	int height = 0;
	while(!que.empty())
	{
		node = que.front();
		que.pop();
		for (int i = 0; i < Node[node].size(); ++i)
		{
			level[Node[node][i]] = level[node] + 1;
			if (level[Node[node][i]] > height)
				height = level[Node[node][i]];
			que.push(Node[node][i]);
		}
	}

	int count = 0;
	for (int i = 1 ; i <= N; ++i)
		if (Node[i].size() == 0)
			++num[level[i]];
	printf("%d", num[0]);
	for (int i = 1; i <= height; ++i)
		printf(" %d", num[i]);
	printf("\n");
	return 0;
}
