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
	return 0;
}

方法二

//反转链表
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100000

struct Node 
{
	int data;
	int address;
	int next;
	int number;
	bool operator < (const Node &node) const
	{
		return number < node.number;
	}
};

Node node[SIZE];
vector<Node> vec;
int main(void)
{
	int head, N, K;
	scanf("%d%d%d", &head, &N, &K);
	int add;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &add);
		scanf("%d%d", &node[add].data, &node[add].next);
		node[add].address = add;
	}
	int count = 0;
	while(head != -1)
	{
		node[head].number = count;
		++count;
		vec.push_back(node[head]);
		head = node[head].next;
	}
	int length = count / K * K;
	int divi;
	int remain;
	for (size_t i = 0; i < length; ++i)
	{
		divi = vec[i].number / K * K;
		remain = vec[i].number % K;
		vec[i].number = divi + K - remain - 1;
	}
	sort(vec.begin(),vec.end());
	if (count != 0)
	{
		printf("%05d %d ", vec[0].address, vec[0].data);
		for (int i = 1; i < count; ++i)
			printf("%05d\n%05d %d ", vec[i].address, vec[i].address, vec[i].data);
		printf("-1\n");
	}
	return 0;
}
