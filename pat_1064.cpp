#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
/**
	此题思路为先存好数据，然后排序后，根据完全二叉树的特点建立完全二叉树，在进行广度搜索，此种方法非最佳
*/
struct Node
{
	int value;
	Node *left;
	Node *right;
	Node () : value(0), left(NULL), right(NULL) {}
	bool operator < (const Node & node) const
	{
		return value < node.value;
	}
};
Node node[1000];
Node *trans(int start, int end)
{
	if (start > end)
		return NULL;
	if (start == end)
		return &node[start];
	//求出树的高度
	int length = end - start + 1;
	int level = 1;
	int nodeAll = 2;
	while(nodeAll - 1 < length)
	{
		nodeAll *= 2;
		++level;
	}
	//找树的根结点
	int mid;
	if (length - (pow(2.0, level - 1) - 1) >= pow(2.0,level - 2))
		mid = pow(2.0, level - 1) - 1 + start;
	else
		mid = end - (pow(2.0,level - 2) - 1);
	node[mid].left = trans(start, mid - 1);
	node[mid].right = trans(mid + 1, end);
	return &node[mid];
}

queue<Node *> que;
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &node[i].value);
	}
	sort(node, node+N);
	Node *head = trans(0, N-1);
	que.push(head);
	Node * index;
	printf("%d", head->value);
	while(!que.empty())
	{
		index = que.front();
		que.pop();
		if (index->left != NULL)
		{
			que.push(index->left);
			printf(" %d", index->left->value);
		}
		if (index->right != NULL)
		{
			que.push(index->right);
			printf(" %d", index->right->value);
		}
	}
	printf("\n");
	return 0;
}
