#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/*
	存储汽油站的数据结构，此题需要将汽油站按与起点距离进行排序
	首先对第一个站点进行判断是否在起点，如不在起点，则最大距离为0，如在进行下一步
	对某一个站点来说需保存left剩余油量，这个剩余油量很重要，
	让我们从一个站点开始，首先我们要摸清它的下一个站点有还是没有
	没有分为如下几种情况：在加满油行驶的范围内没有，或者为最后一站点，或者下一站点已经超出了目的地
	有又分为几种情况：
	1、在加满油并且没有到达终点之前有更便宜的，或者说加满油之后行驶范围内没有更便宜的并且能够直接到达终点，对于此种情况，只需把油加到刚好能行驶此段路就可以
	2、最后一种情况比较复杂，加满油后不能达到终点，并且没有更便宜的，找到行驶范围内相对最便宜的，在站点加满油后，到这个相对便宜的站点，需要记录上一次站点还有多少油没有用完
	所以left很重要
	此题需注意：在计算一个站点需加多少油时，需要依据下一个加油的站点和上一次剩余的油量，计算此战点可以加多少油

*/
struct Station
{
	double price;
	double dist;
	bool operator < (const Station &sta) const
	{
		return dist < sta.dist;
	}
};

vector<Station> sta;
vector<int> dist;
int main(void)
{
	double C, D, Davg, N;
	scanf("%lf%lf%lf%lf", &C, &D, &Davg, &N);
	sta.resize(N);
	dist.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%lf%lf", &sta[i].price, &sta[i].dist);
	sort(sta.begin(), sta.end());
	if (sta[0].dist)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double once = C * Davg, cost = 0;
	//剩余还有多少油量，这个变量很重要，上一站还剩余的油量
	int index = 0, next, left = 0;
	while (index < N)
	{
		next = index + 1;

		/*寻找下一个汽油站点，分为三种情况：
		  1、没有加油站，要么到终点了，要么Impossible
		  if (sta[next].dist - sta[index].dist > once || sta[next].dist >= D)
		  2、有更便宜的加油站
		  while(sta[next].dist - sta[index].dist <= once)
		  {
			if (sta[next].price <= sta[index].price)
				break;
		  }
		  3、没有更便宜的加油站，寻找其中最编译的站点
		*/
		//第一种情况，最后一站或后一站太远或后一站已超出终点
		if (next == N || sta[next].dist - sta[index].dist > once || sta[next].dist >= D)
		{
			if (sta[index].dist + once >= D)
				cost += (D - sta[index].dist - left) * sta[index].price;
			break;
		}
		else
		{
			//第二种情况，接下来距离内有站点，寻找下一个站点
			int min = next;
			while (next < N && sta[next].dist < D && sta[next].dist - sta[index].dist <= once )
			{
				//寻找比之前站点便宜的站点
				if (sta[next].price <= sta[index].price)
				{
					min = next;
					break;
				}
				//当都是比之前站点贵的，寻找相对便宜的站点
				if (sta[next].price <= sta[min].price)
					min = next;
				++next;
			}
			next = min;
			//有更便宜的站点,加适量的油直接开到下一个站点
			if (sta[next].price <= sta[index].price)
			{
				cost += (sta[next].dist - sta[index].dist - left) * sta[index].price;
				left = 0;
			}
			//没有更便宜的站点
			else
			{
				//如果直接能开到终点，那加到终点的油，不能开到终点，加满油
				if (sta[index].dist + once - left >= D)
				{
					cost += (D - sta[index].dist - left) * sta[index].price;
					break;
				}
				else
				{
					cost += (once - left)* sta[index].price;
					left = once - (sta[next].dist - sta[index].dist);
				}
			}
		}
		index = next;
	}
	if (sta[index].dist + once < D)
		printf("The maximum travel distance = %.02lf\n", sta[index].dist + once);
	else
		printf("%.02lf\n", cost / Davg);
	return 0;
}
