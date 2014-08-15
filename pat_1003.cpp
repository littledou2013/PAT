#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
/*
	比较难
	这个题目求的不是最短路径，而是最短路径的数量,对dijkstra算法进行更改就可以
	
*/
struct Edge
{
	int dist;
	int next;
};
//使用邻接矩阵来存储这个图
vector<Edge> ver[500];
//每个顶点所带有的队列
int teams[500];
//起点到其他点的最短距离
int distant[500];
//起点到其他点经过的所有队伍数
int teamAll[500];
bool trans[500];
int path[500];
int main(void)
{
	//N,顶点数量,M,边的数量，C1,起点，C2,终点
	int N, M, C1, C2;
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; ++i)
		scanf("%d", &teams[i]);
	int start, end;
	Edge edge;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &start, &end, &edge.dist);
		edge.next = end;
		ver[start].push_back(edge);
		edge.next = start;
		ver[end].push_back(edge);
	}
	//求C1点到C2点的最短路径
	//初始化距离和相应的队伍
	for (int i = 0;i < N; i++)
	{
		distant[i] = -1;
		teamAll[i] = teams[C1];
	}
	distant[C1] = 0;
	path[C1] = 1;
	int min_Node;
	int min_dist;
	int count = 0;
	int update;
	//找N此最小的点就可以了
	while(count < N)
	{
		//首先找最小的路径的顶点
		min_dist = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if (trans[i] == false && distant[i] != -1 && distant[i] < min_dist)
			{
				min_dist = distant[i];
				min_Node = i;
			}
		}
		trans[min_Node] = true;
		if (min_Node == C2 || min_dist == INT_MAX)
			break;
		//根据找到的点更新路径
		int length = ver[min_Node].size();
		for (int i = 0;i < length; ++i)
		{
			update = ver[min_Node][i].next;
			//更新的结点
			if (trans[update] == false)
			{
				if (distant[update] == -1 || distant[update] > distant[min_Node] + ver[min_Node][i].dist )
				{
					path[update] = path[min_Node];
					distant[update] = distant[min_Node] + ver[min_Node][i].dist;
					teamAll[update] = teamAll[min_Node] + teams[update];
				}
				else if (distant[update] == distant[min_Node] + ver[min_Node][i].dist)
				{
					path[update] += path[min_Node];
					if (teamAll[update] < teamAll[min_Node] + teams[update])
						teamAll[update] = teamAll[min_Node] + teams[update];
				}
			}
			
		}
		++count;
	}
	printf("%d %d\n", path[C2], teamAll[C2]);
	return 0;
}
