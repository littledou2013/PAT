#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/*
	N个测试点， 每个测试点K个学生
*/
struct Student
{
	char number[14];
	int score;
	int local_rank;
	int location;
	int final_rank;
};
bool cmp1(Student stu1, Student stu2)
{
	if (stu1.location != stu2.location)
		return stu1.location < stu2.location;
	if (stu1.score != stu2.score)
		return stu1.score > stu2.score;
	int cmp = strcmp(stu1.number, stu2.number);
	if (cmp > 0)
		return false;
	else 
		return true;
}
bool cmp2(Student stu1, Student stu2)
{
	if (stu1.score != stu2.score)
		return stu1.score > stu2.score;
	int cmp = strcmp(stu1.number, stu2.number);
	if (cmp > 0)
		return false;
	else 
		return true;
}
vector<Student> student;
int main(void)
{
	int N, K;
	scanf("%d", &N);
	Student stu;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &K);
		for (int j = 0; j < K; ++j)
		{
			scanf("%s%d", stu.number, &stu.score);
			stu.location = i;
			student.push_back(stu);
		}
	}
	sort(student.begin(), student.end(), cmp1);
	int location = 0;
	int length = student.size();
	int start = 0;
	for (int i = 0; i < length; ++i)
	{
		if (student[i].location != location)
		{
			location = student[i].location;
			student[i].local_rank = 1;
			start = i;

		}
		else
		{
			if (student[i].score == student[i-1].score)
				student[i].local_rank = student[i-1].local_rank;
			else
				student[i].local_rank = i - start + 1;
		}
	}
	sort(student.begin(), student.end(), cmp2);
	student[0].final_rank = 1;
	for (int i = 1;i < length; ++i)
	{
		if (student[i].score == student[i-1].score)
			student[i].final_rank = student[i-1].final_rank;
		else
			student[i].final_rank = i + 1;
	}
	printf("%d\n", length);
	for (int i = 0; i < length; ++i)
		printf("%s %d %d %d\n", student[i].number, student[i].final_rank, student[i].location, student[i].local_rank);
	
	return 0;
}
