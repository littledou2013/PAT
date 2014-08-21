#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
//最多1000个顾客，第i个顾客对应第i个下标
struct Customer
{
	int end, time;
} customer[1001];
queue<int> que[20];
int main(void)
{
	int N, M, K, Q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 1; i <= K; ++i)
		scanf("%d", &customer[i].time);
	int end = 0;
	for (int i = 0; i < N; ++i)
		while (!que[i].empty())
			que[i].pop();
	//依次将第i个顾客插入相应的窗口中
	for (int i = 1; i <= K; ++i)
	{
		//寻找需要插的队，就是队的长度最小的那个,最长不超过10
		int minLine = 11;
		int minNode;
		for (int j = 0; j < N; ++j)
		{
			if (que[j].size() < minLine)
			{
				minLine = que[j].size();
				minNode = j;
			}
		}
		if (minLine == M)
		{
			//当队列都是满时，需要判断是那个队列最先弹出一个元素
			int minTime = customer[que[0].front()].end;
			minNode = 0;
			for (int j = 1; j < N; ++j)
			{
				if (customer[que[j].front()].end < minTime)
				{
 					minTime = customer[que[j].front()].end;
					minNode = j;
				}
			}
			end = customer[que[minNode].back()].end;
			que[minNode].pop();
		}
		if (!que[minNode].empty())
			end = customer[que[minNode].back()].end;
		que[minNode].push(i);
		customer[i].end = end + customer[i].time;
	}
	int query;
	for (int i = 0; i < Q; ++i)
	{
		scanf("%d", &query);
		//注意题意是说只要开始时间是在17：00之前就可以
		if (customer[query].end - customer[query].time >= 540)
		{
			printf("Sorry\n");
		}
		else
		{
			int hour, minite;
			hour = customer[query].end / 60 + 8;
			minite = customer[query].end % 60;
			printf("%02d:%02d\n", hour, minite);
		}
		
	}
	return 0;
}
