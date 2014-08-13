#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct People
{
	//名字，通话总时长，通话对象
	string name;
	int callTime;
	vector<int> callTo;
	People(): callTime(0), callTo(NULL){}
};
struct Gang
{
	string head;
	int people;
	bool operator < (const Gang &gang) const
	{
		return head < gang.head;
	}
	
};
vector<Gang> gang;
People people[2000];
//使用map将名字与下标对应起来
map<string, int> mp;
bool trans[2000] = {false};
vector<int> que;

int main(void)
{
	//K为阈值
	int N, K;
	scanf("%d%d", &N, &K);
	string name1, name2;
	int peopleNumber = 0;
	int callT, a, b;
	for (int i = 0; i < N; ++i)
	{
		cin>>name1>>name2>>callT;
		//使用map来寻找name的下标，如果不存在创建下标
		if (mp.find(name1) == mp.end())
		{
			mp[name1] = peopleNumber;
			++peopleNumber;
		}
		if (mp.find(name2) == mp.end())
		{
			mp[name2] = peopleNumber;
			++peopleNumber;
		}
		a = mp[name1];
		b = mp[name2];
		people[a].callTime += callT;
		people[a].callTo.push_back(b);
		people[a].name = name1;
		people[b].callTime += callT;
		people[b].callTo.push_back(a);
		people[b].name = name2;
	}
	//广度遍历

	for (int i = 0; i < peopleNumber; ++i)
	{
		if (trans[i] == false)
		{
			//遍历一个连通图
			que.clear();
			que.push_back(i);
			int node;
			//记录一个连通图的结点数
			int count = 0;
			//head 来寻找头
			int head = i;
			trans[i] = true;
			//总通话时间来比较阈值
			int people_timeAll = 0;
			while(!que.empty())
			{
				node = que.back();
				que.pop_back();
				people_timeAll += people[node].callTime;
				if (people[node].callTime > people[head].callTime)
					head = node;
				++count;
				for (int j = 0;j < people[node].callTo.size(); ++j)
				{
					if (trans[people[node].callTo[j]] == false)
					{
						que.push_back(people[node].callTo[j]);
						trans[people[node].callTo[j]] = true;
					}
				}
			}
			if (people_timeAll > K * 2 && count > 2)
			{
				Gang g;
				g.head = people[head].name;
				g.people = count;
				gang.push_back(g);
			}
		}
		else
			continue;
	}
	sort(gang.begin(), gang.end());
	int length = gang.size();
	printf("%d\n", length);
	for (int i = 0;i < length; ++i)
		cout<<gang[i].head<<" "<<gang[i].people<<endl;
	return 0;
}
