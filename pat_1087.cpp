#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <climits>
using namespace std;

map<int, int> mp;
int happy[201];
char cityString[201][4];
int city2int(char city[])
{
	int number = 0;
	for (int i = 0; i < 3; ++i)
	{
		number *= 26;
		number += city[i] - 'A';
	}
	return number;
}

struct Edge
{
	int next;
	int cost;
};
vector<Edge> vec[201];
bool trans[201];
int minCost[201];
vector<int> above[201];
vector<vector<int> > pathAll;
vector<int> path;
void getAllPath(int start)
{
	path.push_back(start);
	int length = above[start].size();
	if (length > 0)
	{
		for (int i = 0; i < length; ++i)
			getAllPath(above[start][i]);
	}
	else
		pathAll.push_back(path);
	path.pop_back();
}
int main(void)
{
	//n 城市数量, road 道路数量， startCity 开始城市
	int n, road;
	scanf("%d%d%s", &n, &road, &cityString[0]);
	mp[city2int(cityString[0])] = 0;
	happy[0] = 0;

	for (int i = 1; i < n; ++i)
	{
		scanf("%s%d", cityString[i], &happy[i]);
		mp[city2int(cityString[i])] = i;
	}
	
	char start[4], end[4];
	int startIndex, endIndex;
	Edge edge;
	for (int i = 0; i < road; ++i)
	{
		scanf("%s%s%d", start, end, &edge.cost);
		startIndex = mp[city2int(start)];
		endIndex = mp[city2int(end)];

		edge.next = endIndex;
		vec[startIndex].push_back(edge);

		edge.next = startIndex;
		vec[endIndex].push_back(edge);
	}
	//求从起点到罗马的所有最短路径

	//初始化最短代价
	for (int i = 0; i < n; ++i)
	{
		minCost[i] = INT_MAX;
		trans[i] = false;
	}

	minCost[0] = 0;

	for (int i = 0; i < n; ++i)
	{
		//寻找代价最小的城市
		int minIndex = -1, min = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if (trans[j] ==false && minCost[j] < min)
			{
				min = minCost[j];
				minIndex = j;
			}
		}
		trans[minIndex] = true;
		
		//更新其他最短距离
		int size = vec[minIndex].size();
		for (int j = 0; j < size; ++j)
		{
			int node = vec[minIndex][j].next;
			if (trans[node] == false)
			{
				if (minCost[node] > minCost[minIndex] + vec[minIndex][j].cost)
				{
					above[node].clear();
					above[node].push_back(minIndex);
					minCost[node] = minCost[minIndex] + vec[minIndex][j].cost;
				}
				else if (minCost[node] == minCost[minIndex] + vec[minIndex][j].cost)
				{
					above[node].push_back(minIndex);
				}
				else
				{
					continue;
				}
			}
		}

	}
	endIndex = mp[city2int("ROM")];
	getAllPath(endIndex);
	printf("%d %d", pathAll.size(), minCost[endIndex]);
	int maxIndex, maxHappy = -1;
	for (int i = pathAll.size() - 1; i >= 0; --i)
	{
		int allHappy = 0;
		for (int j = pathAll[i].size() - 1; j >= 0; --j)
		{
			allHappy += happy[pathAll[i][j]];
		}
		if (allHappy > maxHappy || (allHappy == maxHappy && allHappy * (pathAll[maxIndex].size() - 1) > maxHappy * (pathAll[i].size() - 1)))
		{
			maxHappy = allHappy;
			maxIndex = i;
		}
	}
	int index = pathAll[maxIndex].size() - 1;
	printf(" %d %d\n", maxHappy, maxHappy / index);
	printf("%s", cityString[pathAll[maxIndex][index]]);
	while (index--)
		printf("->%s", cityString[pathAll[maxIndex][index]]);
	printf("\n");
	return 0;
}
