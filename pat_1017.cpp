#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer
{
	int start;
	int handle;
	int end;
	bool operator < (const Customer & customer) const
	{
		return start < customer.start;
	}
};
vector<Customer> vec;
vector<int> Win;
int main(void)
{
	int N, k, hour, minite, second;
	scanf("%d%d", &N, &k);
	vec.resize(N), Win.resize(k);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d:%d:%d%d", &hour, &minite, &second, &vec[i].handle);
		vec[i].start = (hour - 8) * 60 * 60  + minite * 60 + second;
	}
	sort(vec.begin(), vec.end());
	int wating = 0, index = 0, maxTime = (17 -  8) * 60 * 60 + 1, w;
	while ( index < N && vec[index].start < maxTime)
	{
		//首先寻找数字最小的Win
		w = 0;
		for (int i = 1; i < k; ++i)
		{
			if (Win[i] < Win[w])
				w = i;
		}
		if (Win[w] > vec[index].start)
		{
			wating += Win[w] - vec[index].start;
			Win[w] += vec[index].handle * 60;
		}
		else
		{
			Win[w] = vec[index].start + vec[index].handle * 60;
		}
		++index;
	}
	printf("%.01f\n", wating * 1.0 / (60 * index));
	system("pause");
	return 0;
}
