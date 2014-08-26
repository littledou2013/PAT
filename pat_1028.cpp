#include <iostream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student
{
	int id;
	char name[10];
	int grade;
};
bool cmp1(Student stu1, Student stu2)
{
	return stu1.id < stu2.id;
}
bool cmp2(Student stu1, Student stu2)
{
	int cmp = strcmp(stu1.name, stu2.name);
	if (cmp > 0)
		return false;
	if (cmp < 0)
		return true;
	return stu1.id < stu2.id;
}
bool cmp3(Student stu1, Student stu2)
{
	if (stu1.grade != stu2.grade)
		return stu1.grade < stu2.grade;
	return stu1.id < stu2.id;
}
vector<Student> stu;
int main(void)
{
	int N, C;
	scanf("%d%d", &N, &C);
	stu.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].grade);
	switch (C)
	{
	case 1:	sort(stu.begin(), stu.end(), cmp1); break;
	case 2:	sort(stu.begin(), stu.end(), cmp2); break;
	case 3:	sort(stu.begin(), stu.end(), cmp3); break;
	}
	for (int i = 0; i < N; ++i)
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	return 0;
}
