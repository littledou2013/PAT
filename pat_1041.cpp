#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Lottery
{
	int number;
	int id;
};
map<int, Lottery> mp;
int main(void)
{
	int N;
	scanf("%d", &N);
	int lottery;
	for (int i = 0;i < N; ++i)
	{
		scanf("%d", &lottery);
		if (mp.find(lottery) == mp.end())
		{
			mp[lottery].number = 1;
			mp[lottery].id = i;
		}
		else
			mp[lottery].number += 1;
	}
	int max = 100001;
	int unique;
	for (map<int,Lottery>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
	{
		if (iter->second.number == 1 && iter->second.id < max)
		{
			max = iter->second.id;
			unique = iter->first;
		}
	}
	if (max != 100001)
		printf("%d\n", unique);
	else
		printf("None\n");
	return 0;
}
