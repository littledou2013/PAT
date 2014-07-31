#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
	//用count标志结点有多少个前缀，第一个前缀为2的即为公共后缀的开始结点
	int count;
	char ch;
	int next;
	Node():count(0)	{}
};
Node link[100000];
int main(void)
{
	int head1, head2, N;
	scanf("%d%d%d", &head1, &head2, &N);
	int add;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &add);
		scanf(" %c %d", &link[add].ch, &link[add].next);
	}
	//head1结点开头的单词，每个结点的前缀应该为1，包括头元素
	while(head1 != -1)
	{
		++link[head1].count;
		head1 = link[head1].next;
	}
	//寻找head2结点开头的单词中，结点count已为1的结点
	while (head2 != -1)
	{
		if (link[head2].count)
			break;
		head2 = link[head2].next;
	}
	if (head2 != -1)
	{
		printf("%05d\n", head2);
	}
	else
		printf("-1\n");
	return 0;
}
