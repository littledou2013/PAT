#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;

vector<int> course[2501];
vector<int> student[26 * 26 * 26 * 10];
int main(void)
{
	//N，学生; K,课程;
	int N, K;
	scanf("%d%d", &N, &K);
	int cour, number;
	char name[4];
	int numName;
	int count = 0;
	for (int i = 1; i <= K; ++i)
	{
		scanf("%d%d", &cour, &number);
		for (int j = 0; j < number; ++j)
		{
			scanf("%s", name);
			numName = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 +name[3] - '0';
			course[cour].push_back(numName);
		}
	}
	for (int i = 1;i <= K; ++i)
	{
		number = course[i].size();
		for (int j = 0; j < number; ++j)
		{
			student[course[i][j]].push_back(i);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%s",name);
		numName = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 +name[3] - '0';
		number = student[numName].size();
		printf("%s %d", name, number);
		for (int j = 0; j < number; ++j)
			printf(" %d", student[numName][j]);
		printf("\n");
	}
	return 0;
}
