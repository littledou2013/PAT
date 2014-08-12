#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
struct Mice
{
	int id;
	int turn;
	int grade;
	int mice;
};

bool cmp1(Mice  mice1, Mice mice2)
{
	return mice1.turn > mice2.turn;
}
bool cmp2(Mice mice1, Mice mice2)
{
	return mice1.id < mice2.id;
}
Mice mice[1000];
//保存顺序
int order[1000];

int main(void)
{
	int Np,  Ng;
	scanf("%d%d", &Np, &Ng);
	for (int i = 0; i < Np; ++i)
	{
		scanf("%d",&mice[i].mice);
		mice[i].id = i;
		mice[i].turn = 0;
	}
	for (int i = 0; i < Np; ++i)
		//下表i表示第i个玩家是谁
		scanf("%d", &order[i]);
	int count = Np;
	int index;
	int next;
	int max;
	int max_mice;
	while(count != 1)//每一轮
	{
		index = 0;
		while(index < count)
		{
			next = index + Ng;
			if (next > count)
				next = count;
			max = 0;
			while(index < next)
			{
				if (mice[order[index]].mice > max)
				{
					max = mice[order[index]].mice;
					max_mice = order[index];
				}
				++index;
			}
			//把胜者放入下一轮的排序中
			order[(index-1)/Ng] = max_mice;
			++mice[max_mice].turn;
		}
		//计算下一轮的人数
		count = (count-1)/Ng + 1;
	}
	//计算排名，由turn来计算排名
	sort(mice, mice+Np, cmp1);
	mice[0].grade = 1;
	for (int i = 1; i < Np; ++i)
	{
		if (mice[i].turn == mice[i-1].turn)
			mice[i].grade = mice[i-1].grade;
		else
			mice[i].grade = i + 1;
	}
	//依照id顺序输出排名
	sort(mice, mice+Np, cmp2);
	printf("%d", mice[0].grade);
	for (int i = 1;i < Np; ++i)
		printf(" %d", mice[i].grade);
	printf("\n");
	return 0;

}
