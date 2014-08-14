#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	char name[5];
	int number;
	vector<int> course;
	bool operator < (const Student &stu) const
	{
		if (strcmp(name, stu.name) <= 0)
			return true;
		else
			return false;
	}
};
Student student[40000];
vector<char *> vec[2501];
int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0;i < N; ++i)
	{
		scanf("%s %d", &student[i].name, &student[i].number);
		student[i].course.resize(student[i].number);
		for (int j = 0; j < student[i].number; ++j)
			scanf("%d", &student[i].course[j]);
	}
	sort(student, student+N);
	for (int i = 0;i < N; ++i)
	{
		for (int j = 0; j < student[i].number; ++j)
			vec[student[i].course[j]].push_back(student[i].name);
	}
	for (int i = 1; i <= K; ++i)
	{
		int count = vec[i].size();
		printf("%d %d\n", i , count);
		for (int j = 0; j < count ; ++j)
		{
			printf("%s\n", vec[i][j]);
		}
	}
	return 0;
}
