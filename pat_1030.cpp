Skip to content
 
This repository 
Explore
Gist
Blog
Help
littledou2013 littledou2013
 
 
1  Unwatch 
  Star 0
 Fork 0littledou2013/Algorithm
 branch: master   Algorithm / pat_1030.cpp
littledou2013 littledou2013 13 seconds ago Create pat_1030.cpp
1 contributor
121 lines (112 sloc)  3.089 kb RawBlameHistory   
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

/*
	对于这个图论题目，计算两点之间的最短长度，并记录相应路径。
	此方法没有按照常规图论中经典算法进行对应求解。
*/

struct Edge
{
	int dist;
	int pri;
	int city;
};
/*
	使用邻接链表来存储图信息
	顶点使用数组vec下标表示
	边使用Edge结构体表示
*/
vector<Edge> vec[500];

//定义四个数组分表来表示离起点的最短距离，相应代价，是否以求出最短路径，某点最短路径所对应的上一个顶点
int minDist[500];
int minPri[500];
bool trans[500];
int next_next[500];
//存放已遍历顶点
vector<int> inclu;

/*
	由path函数回溯路径，并进行输出。
	对于此题来说，容易求最短路径及相应的最短路径，但要保存最短路径则相对来说有些复杂了。
	本思路采用一个数组来记录每个顶点在其相应最短路径的下对应的上一个顶点，只用一个数组便可以记录每个顶点对应于特定顶点的最短路径。
*/
void path(int node, int S)
{
	if (node == S)
	{
		printf("%d ", node);
		return;
	}
	path(next_next[node], S);
	printf("%d ", node);
}

int main(void)
{
	//顶点， 边， 起点， 终点
	int N, M, S, D;
	scanf("%d%d%d%d", &N, &M, &S, &D);

	int city1, city2, dist, pri;
	Edge edge;
	//保存图信息
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d%d%d", &city1, &city2, &dist, &pri);
		edge.dist = dist;
		edge.pri = pri;
		edge.city = city2;
		vec[city1].push_back(edge);
		edge.city = city1;
		vec[city2].push_back(edge);
	}
	/*
		计算最短路径,计算起点到其他定点的最短路径
		初始化路径长度
	*/
	for (int i = 0; i < N; ++i)
		minDist[i] = INT_MAX;
	minDist[S] = 0;
	minPri[S] = 0;
	for (size_t i = 0; i < vec[S].size(); ++i)
	{
		minDist[vec[S][i].city] = vec[S][i].dist;
		minPri[vec[S][i].city] = vec[S][i].pri;
	}

	//S用来存放已计算最短路径顶点的容器
	inclu.push_back(S);
	trans[S] = true;

	int minD, minP;
	while(inclu.size() <= N)
	{
		//初始化记录最短路径的变量minD
		minD = INT_MAX;
		//遍历S中顶点，寻找下一个最短路径顶点
		int node, minNode;
		for (int i = 0; i < inclu.size(); ++i)
		{
			node = inclu[i];
			for (int j = 0; j < vec[node].size(); ++j)
			{
				//寻找没有遍历并且路径最短的顶点
				if (!trans[vec[node][j].city] &&(vec[node][j].dist + minDist[node] < minD || (vec[node][j].dist + minDist[node] == minD && vec[node][j].pri + minPri[node] < minP)))
				{ 		
					minNode = vec[node][j].city;
					minD = vec[node][j].dist + minDist[node];
					minP = vec[node][j].pri + minPri[node];
					//某个点所处最短路径的上一个顶点必须在这里进行更新， 防止node的值在下次遍历时覆盖，
					next_next[minNode] = node;
				}
			}
		}
		minDist[minNode] = minD;
		minPri[minNode] = minP;
		trans[minNode] = true;
		inclu.push_back(minNode);
		if (minNode == D)
			break;
	}
	path(D,S);
	printf("%d %d\n", minDist[D], minPri[D]);
	system("pause");
	return 0;
}
Status API Training Shop Blog About © 2014 GitHub, Inc. Terms Privacy Security Contact 
