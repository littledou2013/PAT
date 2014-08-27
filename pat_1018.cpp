#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int station[501];
struct Edge
{
	int time;
	int next;
};
/*
	使用Node邻接矩阵来存储图信息
*/
vector<Edge> Node[501];
int distant[501];
vector<int> parent[501];
bool trans[501];
vector<vector<int> > path;
vector<int> p;
void getTree(int Sp)
{
	p.push_back(Sp);
	if (Sp == 0)
	{
		p.pop_back();
		path.push_back(p);
		return;
	}
	for (int i = 0; i < parent[Sp].size(); ++i)
		getTree(parent[Sp][i]);	
	p.pop_back();
}
int main(void)
{
	//Cmax,最大容量，为偶数， N，顶点个数，Sp,终点，M，边条数
	//Sp要么满，要么空
	int Cmax, N, Sp, M;
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &station[i]);
	int s1, s2;
	Edge edge;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &s1, &s2, &edge.time);
		edge.next = s2;
		Node[s1].push_back(edge);
		edge.next = s1;
		Node[s2].push_back(edge);
	}
	//初始化所有信息
	for (int i = 0; i <= N; ++i)
	{
		distant[i] = INT_MAX;
		//到底怎么记录team这个值，逻辑不是很清楚
		trans[i] = false;
		parent[i].clear();
	}
	distant[0] = 0;
	while(true)
	{
		int minNode = -1, min = INT_MAX;
		//寻找最小的点                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
		for (int i = 0; i <= N; ++i)
		{
			if (trans[i] == false && distant[i] < min)
			{
				min = distant[i];
				minNode = i;
			}
		}
		if (minNode == Sp || minNode == -1)
			break;
		trans[minNode] = true;
		//根据最小的点，对其邻接点进行更新
		for (int i = 0; i < Node[minNode].size(); ++i)
		{
			Edge adjax = Node[minNode][i];
			if (trans[adjax.next] == false)
			{
				if (distant[minNode] + adjax.time < distant[adjax.next])
				{
					parent[adjax.next].clear();
					parent[adjax.next].push_back(minNode);
					distant[adjax.next] = distant[minNode] + adjax.time;
				}
				else if (distant[minNode] + adjax.time == distant[adjax.next])
					parent[adjax.next].push_back(minNode);
			}
		}
	}
	path.clear();
	p.clear();
	//根据parent创建树
	getTree(Sp);
	int index = 0;
	int send , collect, minSend = INT_MAX, minCollect = INT_MAX;
	for (int i = 0; i < path.size(); ++i)
	{
		send = 0;
		collect = 0;
		for (int j = path[i].size() - 1; j >= 0; --j)
		{
			if (station[path[i][j]] > Cmax / 2)
				collect += station[path[i][j]] - Cmax / 2;
			else if (station[path[i][j]] < Cmax / 2)
			{
				collect -= Cmax / 2 - station[path[i][j]];
				if (collect < 0) 
				{
					send -= collect;
					collect = 0;
				}
			}
		}
		//这里需要保障路线上的所有站点都是perfect。
		if (send < minSend)
		{
			minSend = send;
			minCollect = collect;
			index = i;
		}
		else if (send == minSend && collect < minCollect)
		{
			minCollect = collect;
			index = i;
		}
		
	}
	
	printf("%d 0",minSend);
	for (int i = path[index].size() - 1; i >= 0; --i)
		printf("->%d", path[index][i]);
	printf(" %d\n", minCollect);
	return 0;
}
