#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <climits>
using namespace std;
struct Play
{
	int start, serve, p;
	bool operator < (const Play &player) const
	{
		return start < player.start;
	}
};
struct Table
{
	int freetime, number;
	Table():freetime(0), number(0) {}
};

int MAXTIME = 13 * 3600;
vector<Play> players;
vector<Play> vplayers;
set<int> vtable;
vector<Table> table;

void printTime(Play player)
{
		printf("%02d:%02d:%02d ", player.start / 3600 + 8, player.start  / 60 % 60, player.start  % 60);
		printf("%02d:%02d:%02d ", player.serve / 3600 + 8, player.serve / 60 % 60, player.serve % 60);
		printf("%d\n", (player.serve - player.start + 30) / 60);
}
int main(void)
{
	int N, K, M, hour, minite, second, p, tag, vip;
	scanf("%d", &N);
	Play player;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d:%d:%d%d%d", &hour,&minite, &second,&p, &tag);
		player.start = (hour - 8) * 3600 + minite * 60 + second;
		if (player.start < MAXTIME)
		{
			if (p > 120)
				player.p = 120 * 60;
			else 
				player.p = p * 60;
			if (tag == 1)
				vplayers.push_back(player);
			else
				players.push_back(player);
		}
	}
	scanf("%d%d", &K, &M);
	table.resize(K);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &vip);
		vtable.insert(--vip);
	}

	sort (players.begin(), players.end());
	sort (vplayers.begin(), vplayers.end());
	int length = players.size(), vlength = vplayers.size(), index1 = 0, index2 = 0;
	int startime, servetime;
	while(index1 < length || index2 < vlength)
	{	//贵宾
		if (index1 < length && index2 < vlength)
		{
			//如果有普通客户和贵宾，则找出时间来的最早那个
			if (players[index1].start < vplayers[index2].start)
			{
				startime = players[index1].start;
				tag = 0;
			}
			else
			{
				startime = vplayers[index2].start;
				tag = 1;
			}
		}
		if (index1 < length && index2 == vlength)
		{
			//只有普通客户
			startime = players[index1].start;
			tag = 0;
		}
		if (index1 == length && index2 < vlength)
		{
			//只有贵宾
			startime = vplayers[index2].start;
			tag = 1;
		}
		//1、寻找空着数字最小的席位； 2、如果没有空着的席位，寻找最早结束的席位
		int minIndex = -1, minStart = INT_MAX;
		if (tag)
		{	
			for (set<int>::iterator iter = vtable.begin(); iter != vtable.end(); ++iter)
			{
				if (table[*iter].freetime <= startime)
					minIndex = *iter;
			}
		}
		if (minIndex == -1)
		{	
			for (int j = 0; j < K; ++j)
			{
				if (table[j].freetime <= startime)
				{
					minIndex = j;
					break;
				}
				if (table[j].freetime < minStart)
				{
					minStart = table[j].freetime;
					minIndex = j;
				}

			}	
		}
		if (table[minIndex].freetime >= MAXTIME)
			break;
		if (index2 < vlength && table[minIndex].freetime > startime && vtable.find(minIndex) != vtable.end() && vplayers[index2].start <= table[minIndex].freetime)
		{
			tag = 1;
			startime = vplayers[index2].start;
		}
		
		if (table[minIndex].freetime < startime)
			servetime = startime;
		else
			servetime = table[minIndex].freetime;
		if(servetime < MAXTIME)
		{
			++table[minIndex].number;
			if (tag)
			{
				table[minIndex].freetime = servetime + vplayers[index2].p;
				vplayers[index2].serve = servetime;
				printTime(vplayers[index2]);
				++index2;
			}
			else
			{
				table[minIndex].freetime = servetime + players[index1].p;
				players[index1].serve = servetime;
				printTime(players[index1]);
				++index1;
			}
		}
		
	}
	printf("%d", table[0].number);
	for (int i = 1; i < K; ++i)
		printf(" %d", table[i].number);
	printf("\n");
	return 0;
}
