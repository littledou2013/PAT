#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
	int address;
	int key;
	int next;
	bool operator < (const Node &node) const
	{
		return key < node.key;
	}
};

Node node[100000];
vector<Node> vec;
int main(void)
{
	int N, head;
	scanf("%d%d", &N, &head);
	int add;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &add);
		scanf("%d%d", &node[add].key, &node[add].next);
		node[add].address = add;
	}
	vec.clear();
	while(head != -1)
	{

		vec.push_back(node[head]);
		head = node[head].next;
	}
	sort(vec.begin(), vec.end());
	//首先我输出第一个数据
	N = vec.size();
	if (N == 0)
		printf("0 -1\n");
	else
	{
		printf("%d %05d\n", N, vec[0].address);
		printf("%05d %d ", vec[0].address, vec[0].key);
		for (int i = 1; i < N; ++i)
			printf("%05d\n%05d %d ",vec[i].address, vec[i].address, vec[i].key);
		printf("-1\n");
	}
	return 0;
}
