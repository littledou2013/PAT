#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct Student
{
	int id, c, m, e, a;
	int rank[4];
	char maxCh;
	int maxRank;
} student[2000];
bool cmp1(Student stu1, Student stu2)
{
	return stu1.a > stu2.a;
}
bool cmp2(Student stu1, Student stu2)
{
	return stu1.c > stu2.c;
}
bool cmp3(Student stu1, Student stu2)
{
	return stu1.m > stu2.m;
}
bool cmp4(Student stu1, Student stu2)
{
	return stu1.e > stu2.e;
}
int main(void)
{
	int N, M, id;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d%d%d", &student[i].id, &student[i].c, &student[i].m, &student[i].e);
		student[i].a = student[i].c + student[i].m + student[i].e;
	}
	sort (student, student + N, cmp1);
	student[0].rank[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		if (student[i].a == student[i - 1].a)
			student[i].rank[0] = student[i-1].rank[0];
		else
			student[i].rank[0] = i + 1;
	}
	sort (student, student + N, cmp2);
	student[0].rank[1] = 1;
	for (int i = 1; i < N; ++i)
	{
		if (student[i].c == student[i - 1].c)
			student[i].rank[1] = student[i-1].rank[1];
		else
			student[i].rank[1] = i + 1;
	}
	sort (student, student + N, cmp3);
	student[0].rank[2] = 1;
	for (int i = 1; i < N; ++i)
	{
		if (student[i].m == student[i - 1].m)
			student[i].rank[2] = student[i-1].rank[2];
		else
			student[i].rank[2] = i + 1;
	
	}
	sort (student, student + N, cmp4);
	student[0].rank[3] = 1;
	for (int i = 1; i < N; ++i)
	{
		if (student[i].e == student[i - 1].e)
			student[i].rank[3] = student[i-1].rank[3];
		else
			student[i].rank[3] = i + 1;
	}
	for (int i = 0; i < N; ++i)
	{
		int best = N, bestIndex = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (student[i].rank[j] < best)
			{
				best = student[i].rank[j];
				bestIndex = j;
			}
		}
		switch(bestIndex)
		{
		case 0:student[i].maxCh = 'A'; break;
		case 1:student[i].maxCh = 'C'; break;
		case 2:student[i].maxCh = 'M'; break;
		case 3:student[i].maxCh = 'E'; break;
		}
		student[i].maxRank = best;
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &id);
		int j = 0;
		//个人认为这样的遍历方法不是很好，其实可以用二分搜索方法，可以减少时间复杂度
		while(j < N && student[j].id != id)
			++j;
		if (j < N)
			printf("%d %c\n", student[j].maxRank, student[j].maxCh);
		else
			printf("N/A\n");
	}
	system("pause");
	return 0;
	
}
