#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct People
{
	int id;
	int virtue;
	int talent;	
	bool operator < (const People &people) const
	{
		if (virtue + talent != people.virtue + people.talent)
			return virtue + talent > people.virtue + people.talent;
		else if (virtue != people.virtue)
			return virtue > people.virtue;
		else
			return id < people.id;
	}
};
vector <People> sage, nobleman, foolman, others;
/**
	采用sort函数进行排序，时间复杂度为nlogn，从计算量上来说是会超时的，但还是在PAT测试下过了，对此存在一些小小的疑问
*/
int main(void)
{
	int n,L,H;
	scanf("%d%d%d", &n, &L, &H);
	int count = 0;
	int id, virtue, talent;
	People people;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &id, &virtue, &talent);
		people.id = id; 
		people.virtue = virtue;
		people.talent = talent;
		if (virtue >= H && talent >= H)
			sage.push_back(people);
		else if (virtue >= H && talent >= L)
			nobleman.push_back(people);
		else if (virtue >= L && talent >= L && virtue >= talent)
			foolman.push_back(people);
		else if (virtue >= L && talent >= L)
			others.push_back(people);
	}

	

	sort(sage.begin(), sage.end());
	sort(nobleman.begin(), nobleman.end());
	sort(foolman.begin(), foolman.end());
	sort(others.begin(), others.end());
	printf("%d\n", sage.size() + nobleman.size() + foolman.size() + others.size());
	for (vector<People>::iterator iter = sage.begin(); iter != sage.end(); ++iter)
		printf("%08d %d %d\n", iter->id, iter->virtue, iter->talent);
	for (vector<People>::iterator iter = nobleman.begin(); iter != nobleman.end(); ++iter)
		printf("%08d %d %d\n", iter->id, iter->virtue, iter->talent);
	for (vector<People>::iterator iter = foolman.begin(); iter != foolman.end(); ++iter)
		printf("%08d %d %d\n", iter->id, iter->virtue, iter->talent);
	for (vector<People>::iterator iter = others.begin(); iter != others.end(); ++iter)
		printf("%08d %d %d\n", iter->id, iter->virtue, iter->talent);
	system("pause");
	return 0;
}
/**	
	不实用常规的排序，那么我们使用另一种方法，但是由于此题的输入id号非顺序输入，最后我们还是要对id号进行一次排序，
	在极端情况下，id号的排序也是非常耗时，还不如用常规的排序方式，如果id号是顺序输入，下面方面将是一个好的选择。
	vector<People> saga[101][101];
	vector<People> nobleman[101][101];
	vector<People> foolman[101][101];
	vector<People> others[101][101];
	输出遍历方式：
	int start = 200;
	while (start >= 0)
	{
		int index1;
		if (start >= 100)
			index1 = 100;
		else 
			index2 = start;
		while (index1 >= 0 && start - index1 <= 100)
		{
			sort(saga[index1][start-index1].begin(),saga[index1][start-index1].end());
			for (vector<People>::iter = saga[index1][start-index1].begin(); iter != saga[index1][start-index1].end(); ++iter)
			{
				printf("%d %d %d\n", iter->id, iter->virtue, iter->talent);
			}
		}
	}

*/


/*
vector<People> saga[101][101];
vector<People> nobleman[101][101];
vector<People> foolman[101][101];
vector<People> others[101][101];
int main(void)
{
	int n,L,H;
	scanf("%d%d%d", &n, &L, &H);
	int count = 0;
	int id, virtue, talent;
	People people;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &id, &virtue, &talent);
		people.id = id; 
		people.virtue = virtue;
		people.talent = talent;
		if (virtue >= L && talent >= L)
			++count;
		if (virtue >= H && talent >= H)
			saga[virtue][talent].push_back(people);
		else if (virtue >= H && talent >= L)
			nobleman[virtue][talent].push_back(people);
		else if (virtue >= L && talent >= L && virtue >= talent)
			foolman[virtue][talent].push_back(people);
		else if (virtue >= L && talent >= L)
			others[virtue][talent].push_back(people);
	}
	printf("%d\n", count);
	int start = 200;
	while (start >= 0)
	{
		int index1;
		if (start >= 100)
			index1 = 100;
		else 
			index1 = start;
		while (index1 >= 0 && start - index1 <= 100)
		{
			sort(saga[index1][start-index1].begin(),saga[index1][start-index1].end());
			for (vector<People>::iterator iter = saga[index1][start-index1].begin(); iter != saga[index1][start-index1].end(); ++iter)
			{
				printf("%d %d %d\n", iter->id, iter->virtue, iter->talent);
			}
			--index1;
		}
		--start;
	}
	start = 200;
	while (start >= 0)
	{
		int index1;
		if (start >= 100)
			index1 = 100;
		else 
			index1 = start;
		while (index1 >= 0 && start - index1 <= 100)
		{
			sort(nobleman[index1][start-index1].begin(),nobleman[index1][start-index1].end());
			for (vector<People>::iterator iter = nobleman[index1][start-index1].begin(); iter != nobleman[index1][start-index1].end(); ++iter)
			{
				printf("%d %d %d\n", iter->id, iter->virtue, iter->talent);
			}
			--index1;
		}
		--start;
	}
	start = 200;
	while (start >= 0)
	{
		int index1;
		if (start >= 100)
			index1 = 100;
		else 
			index1 = start;
		while (index1 >= 0 && start - index1 <= 100)
		{
			sort(foolman[index1][start-index1].begin(),foolman[index1][start-index1].end());
			for (vector<People>::iterator iter = foolman[index1][start-index1].begin(); iter != foolman[index1][start-index1].end(); ++iter)
			{
				printf("%d %d %d\n", iter->id, iter->virtue, iter->talent);
			}
			--index1;
		}
		--start;
	}
	start = 200;
	while (start >= 0)
	{
		int index1;
		if (start >= 100)
			index1 = 100;
		else 
			index1 = start;
		while (index1 >= 0 && start - index1 <= 100)
		{
			sort(others[index1][start-index1].begin(),others[index1][start-index1].end());
			for (vector<People>::iterator iter = others[index1][start-index1].begin(); iter != others[index1][start-index1].end(); ++iter)
			{
				printf("%d %d %d\n", iter->id, iter->virtue, iter->talent);
			}
			--index1;
		}
		--start;
	}
	system("pause");
	return 0;
}*/
