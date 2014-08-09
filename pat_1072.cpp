#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
/*
	此题属于图论题，求某几个顶点到其他某几个顶点的最短路径，应用dijkstra算法
	其顶点分为两种：
	房子,最大为1000
	汽油站，最大为10
	循环遍历每个汽油站点到其他站点的最短距离
*/
struct Edge
{
	int distant;
	int next;
};

//1-10存放汽油结点，11-1010存放房子结点
vector<Edge> vec[1011];

//每个汽油站离房子的距离
int maxDist[1011][1011];
//is_C记录是否可选，min_C记录最短路径，avg_C记录平均路径
bool is_C[11];
int  min_C[11];
int avg_C[11];
//是否已遍历
bool trans[1011];

int getValue(char *str)
{
	int index = 0;
	int sum = 0;
	bool is_G = false;
	if (str[0] == 'G')
	{
		index = 1;
		is_G = true;
	}
	while(str[index])
	{
		sum *= 10;
		sum += str[index] - '0';
		++index;
	}
	if (is_G)
		return sum;
	else
		return sum + 10;
}


int main(void)
{
	//N:房子总数;M:候选地点数;K:路的条数;Ds:汽油站服务最大距离
	int N, M, K;
	int Ds;
	scanf("%d%d%d%lld", &N, &M, &K, &Ds);
	char str1[3], str2[3];
	int a, b;
	int dist;
	Edge edge;
	for (int i = 0; i < K; ++i)
	{
		scanf("%s%s%lld", str1,str2, &dist);
		a = getValue(str1);
		b = getValue(str2);
		//矩阵邻接存储表
		edge.distant = dist;
		edge.next = b;
		vec[a].push_back(edge);
		edge.next = a;
		vec[b].push_back(edge);
	}
	//接下来求对于每一个侯选站，其与房子的距离,初始化距离
	N += 10;
	int min_node = 0;
	min_C[0] = 0;
	avg_C[0] = INT_MAX;
	for (int i = 1; i <= M; ++i)
	{
		is_C[i] = true;
		//对每一个汽油站采用BFS遍历
		for (int j = 1; j <= M; ++j)
		{
			trans[j] = false;
			maxDist[i][j] = INT_MAX;
		}
		for (int j = 11; j<= N; ++j)
		{
			trans[j] = false;
			maxDist[i][j] = INT_MAX;
		}
		maxDist[i][i] = 0;
		maxDist[i][0] = INT_MAX;
		int node;
		while(1)
		{
			//寻找最短结点
			int min = 0;
			for (int j = 1; j <= M ; ++j)
				if (!trans[j] && maxDist[i][j] < maxDist[i][min])
					min = j;
			for (int j = 11; j <= N; ++j)
				if (!trans[j] && maxDist[i][j] < maxDist[i][min])
					min = j;
			//当min = 0时代表，没有循环到下一个结点
			if (min == 0)
				break;
			//如果找到的最短记录为房子，判断是否在服务范围内
			if (min > 10 && maxDist[i][min] > Ds)
			{
				is_C[i] = false;
				break;
			}
			trans[min] = true;
			for (int j = 0; j < vec[min].size(); ++j)
			{
				node = vec[min][j].next;
				if (maxDist[i][node] > vec[min][j].distant + maxDist[i][min])
				{
					maxDist[i][node] = vec[min][j].distant + maxDist[i][min];
				}
			}
		}
		//选出最符合条件的
		if (is_C[i])
		{
			min_C[i] = INT_MAX;
			avg_C[i] = 0;
			for (int j = 11; j <= N; ++j)
			{
				avg_C[i] += maxDist[i][j];
				if (maxDist[i][j] < min_C[i])
					min_C[i] = maxDist[i][j];
			}
			if (min_C[i] > min_C[min_node] || (min_C[i] == min_C[min_node] && avg_C[i] < avg_C[min_node]))
				min_node = i;
		}
	}
	N -= 10;
	if (min_node)
	{
		printf("G%d\n",min_node);
		printf("%.01lf %.01f\n", 1.0 * min_C[min_node], 1.0 * avg_C[min_node] / N);
	}
	else
		printf("No Solution\n");
	return 0;
}
