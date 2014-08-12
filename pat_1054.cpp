#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<int,int> mp;
int main(void)
{
	int M, N;
	scanf("%d%d", &M, &N);
	int val;
	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &val);
			++mp[val];
		}
	}
	int min = 0;
	int min_node;
	for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
	{
		if (iter->second > min)
		{
			min = iter->second;
			min_node = iter->first;
		}
	}
	printf("%d\n", min_node);
	return 0;
}


方法二
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<int,int> mp;
int main(void)
{
	int M, N;
	scanf("%d%d", &M, &N);
	int val, last;
	int count = 1;
	N *= M;
	scanf("%d", &last);
	for (int i = 1; i < N; ++i)
	{
		scanf("%d", &val);
		if (last == val)
			++count;
		else
		{
			--count;
			if(count <= 0)
				last = val;
		}
	}
	printf("%d\n", last);
	system("pause");
	return 0;
}
