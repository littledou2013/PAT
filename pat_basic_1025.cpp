#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
	int data; 
	int next;
	Node():data(0), next(-1){}
};
Node node[100000];
struct Order
{
	int add, data, place;
	bool operator < (const Order &order) const
	{
		return place < order.place;
	}
};
vector<Order> order;
int main(void)
{
	int head, N, K;
	scanf("%d%d%d", &head, &N, &K);
	int add;
	for (int i = 0;i < N; ++i)
	{
		scanf("%d", &add);
		scanf("%d%d", &node[add].data, &node[add].next);
	}
	order.resize(N);
	int index = 0;
	while (head != -1)
	{
		order[index].add = head;
		order[index].place = index;
		order[index].data = node[head].data;
		++index;
		head = node[head].next;
	}
	int length  = index / K * K;
	for (int i = 0; i < length; ++i)
		order[i].place = (order[i].place / K * K) * 2 + K - 1 - order[i].place;
	sort(order.begin(), order.begin() + length);
	printf("%05d %d", order[0].add, order[0].data);
	for (int i = 1; i < index; ++i)
	{
		printf(" %05d\n", order[i].add);
		printf("%05d %d", order[i].add, order[i].data);
	}
	printf(" -1\n");
	return 0;
}
