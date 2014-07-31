#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define SIZE 100004
struct Mem
{
	bool flag;
	vector<int> next;
	Mem():flag(false) 
	{
		next.clear();
	}
};

Mem vec[SIZE];
double result = 0;
//深度遍历
void get_result(int node, double p, double r)
{
	if (vec[node].flag)
	{
		result += p * vec[node].next[0];
		return ;
	}
	for (size_t i = 0; i < vec[node].next.size(); ++i)
	{
		get_result(vec[node].next[i], p *(1 + 0.01 * r), r);
	}
}

int main(void)
{

	int N;
	double P, r;
	int k, num;
	scanf("%d %lf %lf", &N, &P, &r);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &k);
		if (k != 0)
		{
			for	(int j = 0; j < k; ++j)
			{
				scanf("%d", &num);
				vec[i].next.push_back(num);
			}
		}
		else
		{
			scanf("%d", &num);
			vec[i].next.push_back(num);
			vec[i].flag = true;
		}
	
	}
	result = 0;
	get_result(0, P, r);
	
	printf("%.1lf\n", result);
	return 0;
}
