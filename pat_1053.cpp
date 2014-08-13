#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int weight;
	vector<int> children;
};
Node tree[100];
vector<vector<int> >path;
vector<int> vec;

void DFS(int node, int s)
{
	vec.push_back(tree[node].weight);
	if (tree[node].children.empty())
	{
		if (tree[node].weight == s)
			path.push_back(vec);
		vec.pop_back();
		return;
	}
	int size = tree[node].children.size();
	for (int i = 0; i < size; ++i)
	{
		DFS(tree[node].children[i], s - tree[node].weight);
	}
	vec.pop_back();
	return;
}
int main(void)
{
	int N, M, S;
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < N; ++i)
		scanf("%d", &tree[i].weight);
	int number, node, child;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d", &node, &number);
		for (int j = 0; j < number; ++j)
		{
			scanf("%d", &child);
			tree[node].children.push_back(child);
		}
	}
	DFS(0,S);
	//sort竟然会对vector类型进行自动排序
	sort(path.begin(), path.end());
	int length = path.size();
	int size;
	for (int i = length - 1;i >= 0; --i)
	{
		size = path[i].size();
		printf("%d", path[i][0]);
		for (int j = 1; j < size; ++j)
			printf(" %d", path[i][j]);
		printf("\n");
	}
	return 0;
}
