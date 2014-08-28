#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node () : data(0), left(NULL), right(NULL) {}
};
vector<Node> numbers;
bool isBST(int low, int high)
{
	if (high - low <= 1)
		return true;
	int root = numbers[low].data;
	int index = low + 1;
	while (index <= high)
	{
		if (numbers[index].data >= root)
			break;
		++index;
	}
	int mid = index;
	while(index <= high)
	{
		if (numbers[index].data < root)
			return false;
		++index;
	}
	return isBST(low + 1, mid - 1) && isBST(mid, high);
	
}
bool isMirror(int low, int high)
{
	if (high - low <= 1)
		return true;
	int root = numbers[low].data;
	int index = low + 1;
	while (index <= high)
	{
		if (numbers[index].data < root)
			break;
		++index;
	}
	int mid = index;
	while(index <= high)
	{
		if (numbers[index].data >= root)
			return false;
		++index;
	}
	return isMirror(low + 1, mid - 1) && isMirror(mid, high);
}

//构造BST树
Node *getBST(int low, int high, bool is_BST)
{
	if (high < low)
		return NULL;
	if (high == low)
		return &numbers[high];
	int root = numbers[low].data;
	int index = low + 1;
	if(is_BST)
	{
		while (index <= high)
		{
			if (numbers[index].data >= root)
				break;
			++index;
		}
	}
	else
	{
		while (index <= high)
		{
			if (numbers[index].data < root)
				break;
			++index;
		}
	}
	numbers[low].left = getBST(low + 1, index - 1, is_BST);
	numbers[low].right = getBST(index, high, is_BST);
	return &numbers[low];
}

vector<int> post;
void postorder(Node *root)
{
	if (root->left != NULL)
		postorder(root->left);
	
	if (root->right != NULL)
		postorder(root->right);
	post.push_back(root->data);
}
int main(void)
{
	int N;
	scanf("%d", &N);
	numbers.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &numbers[i].data);
	bool is_BST = isBST(0, N - 1);
	bool is_Mirror = isMirror(0, N - 1);
	if (is_BST || is_Mirror)
	{
		printf("YES\n");
		Node *head;
		head = getBST(0, N-1, is_BST);
		postorder(head);
		printf("%d", post[0]);
		for (int i = 1; i < N; ++i)
			printf(" %d", post[i]);
		printf("\n");
	}
	else
		printf("NO\n");
	return 0;
}
