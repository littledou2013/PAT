#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
	典型贪心算法:此题需注意数量应该是小数，否则有一个是无法通过的
*/
struct Mook
{
	double number;
	double price;
	bool operator < (const Mook &mook) const
	{
		return price * mook.number > mook.price * number;
	}
};
vector <Mook> vec;

int main(void)
{
	//N：不同种类的月饼
	//D：市场最大需求
	int N;
	double D;
	scanf("%d%lf", &N, &D);
	vec.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &vec[i].number);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &vec[i].price);
	sort(vec.begin(), vec.end());
	double sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (vec[i].number <= D)
		{
			sum += vec[i].price;
			D -= vec[i].number;
		} 
		else
		{
			sum += vec[i].price / vec[i].number * D;
			break;
		}
	}
	printf("%.02lf\n", sum);
	return 0;
}
