#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<int,int> mp;
int main(void)
{
	long N;
	scanf("%d", &N);
	printf("%d=",N);
	int prime = 2;
	while(N != 1)
	{
		while(N % prime == 0)
		{
			++mp[prime];
			N /= prime;
		}
		if (prime >= 3 && prime % 2)
			prime += 2;
		else
			++prime;
	}
	if(mp.empty())
	{
		printf("1\n");
	}
	else
	{
		map<int,int>::iterator iter = mp.begin();
		printf("%d",iter->first);
		if (iter->second > 1)
			printf("^%d", iter->second);
		++iter;
		while(iter != mp.end())
		{
			printf("*");
			printf("%d",iter->first);
			if (iter->second > 1)
				printf("^%d", iter->second);
			++iter;
		}
		printf("\n");
	}
	return 0;
}
