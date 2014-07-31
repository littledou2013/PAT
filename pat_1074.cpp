//反转链表
#include <iostream>
#include <cstdio>
using namespace std;

#define SIZE 100000
struct Node
{
	int data;
	int next;
};


Node link[SIZE];

int main(void)
{
	while(true)
		{
			int firstNode, N, K;
	scanf("%d%d%d", &firstNode, &N, &K);
	//下标代表地址
	int add;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &add);
		scanf("%d%d", &link[add].data, &link[add].next);
	}
	int node = firstNode;
	N = 0;
	while(node != -1)
	{
		node = link[node].next;
		++N;
	}
	int count = N / K;
	int temp = 1;
	//先反转前K个元素
	int khead = firstNode, knode = khead, knext = link[khead].next, knextnext;
	if (count >= 1)
	{
		//khead反转前为K个元素的头元素，反转后为K个元素的尾元素
		
		while (temp < K)
		{
			knextnext = link[knext].next;
			link[knext].next = knode;
			knode = knext;
			knext = knextnext;
			++temp;
		}
		firstNode = knode;
	}
	int klasthead = khead;
	for (int i = 1; i < count; ++i)
	{
		temp = 1;
		khead = knext;
		knode = khead;
		knext = link[khead].next;
		while(temp < K)
		{
			knextnext = link[knext].next;
			link[knext].next = knode;
			knode = knext;
			knext = knextnext;
			++temp;
		}
		link[klasthead].next = knode;
		klasthead = khead;
	}
	link[klasthead].next = knext;	
	while(--N)
	{
		printf("%05d %d %05d\n", firstNode, link[firstNode].data, link[firstNode].next);
		firstNode = link[firstNode].next;
	}
	printf("%05d %d %d\n", firstNode, link[firstNode].data, link[firstNode].next);
	}
	system("pause");
	return 0;
}
