#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Rich
{
	char name[10];
	int age;
	int worth;
	bool operator < (const Rich &rich) const
	{
		if (worth != rich.worth)
			return worth > rich.worth;
		if (age != rich.age)
			return age < rich.age;
		if (strcmp(name,rich.name) < 0)
			return true;
		else 
			return false;
	}
};
Rich rich[100000];
int age[201] = {0};
vector<int> vec;

int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i)
		scanf("%s%d%d", rich[i].name, &rich[i].age, &rich[i].worth);
	sort(rich,rich+N);
	//下面的步骤非常关键，如果同龄的有超过100的人，则这年龄100以后的需过滤掉，使用vec数组来保存需要的
	for (int i = 0; i < N; ++i)
	{
		if (age[rich[i].age] < 100)
		{
			++age[rich[i].age];
			vec.push_back(i);
		}
	}
	int length = vec.size();
	int out, minAge, maxAge;
	for (int i = 0; i < K; ++i)
	{
		scanf("%d%d%d", &out, &minAge, &maxAge);
		printf("Case #%d:\n", i+1);
		int count = 0;
		for (int j = 0; j < length && count < out; ++j)
		{
			if (rich[vec[j]].age <= maxAge && rich[vec[j]].age >= minAge)
			{
				printf("%s %d %d\n", rich[vec[j]].name, rich[vec[j]].age, rich[vec[j]].worth);
				++count;
			}
		}
		if (!count)
			printf("None\n");

	}
	return 0;
}
