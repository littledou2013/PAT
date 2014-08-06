#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> vec;
vector<bool> trans;
set<int> s;
/*
	首先用一个数组来存放下标所代表的数值存放的位置，用下表存放的好处，可以快速知道0放置的位置，
	如果0放置的位置为0，需判断是否还有未放到对应位置的元素，使用set集来存放未放到对应位置的元素，
	如果set不为空，则0与其中任意一个i元素位置进行交换
		vec[0] = vec[i];vec[i] = 0;
	然后一直交换,并将交换好的元素从set从删除，0元素与vec[0]元素进行交换，则将0放置到了vec[0]所在的位置。
		vec[0] = vec[vec[0]];
*/
int main(void)
{
	int N;
	int val;
	scanf("%d", &N);
	vec.resize(N);
	trans.resize(N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &val);
		//表示val放在什么位置
		vec[val] = i;
		if (val != i && val != 0)
		//s收集未对应好位置的元素，不包括0
			s.insert(val);
	}
	int count = 0;
	while(!s.empty())
	{
		if (vec[0] == 0)
		{
			//交换任意一个未拍好序的数字
			int tmp = *(s.begin());
			vec[0] = vec[tmp];
			vec[tmp] = 0;
			++count;
		}
		while(vec[0] != 0)
		{
			s.erase(vec[0]);
			vec[0] = vec[vec[0]];
			++count;
			
		}
	}
	printf("%d\n", count);
	return 0;	
}
