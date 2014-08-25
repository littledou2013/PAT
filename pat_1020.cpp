#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
	int value;
	Node *left;
	Node *right;
	Node(int _value):value(_value), left(NULL), right(NULL){}
};
int post[30];
int in[30];
Node *getTree(int i1, int j1, int i2, int j2)
{
	Node* tree = new Node(post[j1]);
	int index = i2;
	while (index <= j2)
	{
		if (in[index] == post[j1])
			break;
		++index;
	}
	if (index - i2 > 0)
		tree->left = getTree(i1, i1 + index - i2 - 1, i2, index-1);
	if (j2 - index > 0)
		tree->right = getTree(i1+index-i2, j1-1, index+1, j2);
	return tree;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &post[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &in[i]);
	
	//由后序和中序遍历恢复树
	Node *head = getTree(0, N - 1, 0, N - 1);
	//层次遍历
	queue<Node *> que;
	printf("%d", head->value);
	que.push(head);
	while(!que.empty())
	{
		Node *node = que.front(); 
		que.pop();
		if (node->left !=NULL)
		{
			que.push(node->left);
			printf(" %d",node->left->value);
		}
		if (node->right != NULL)
		{
			que.push(node->right);
			printf(" %d",node->right->value);
		}
	}
	printf("\n");
	return 0;	
}
