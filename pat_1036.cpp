#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct People
{
	string name;
	string id;
	int grade;
};
int main(void)
{
	int N;
	scanf("%d", &N);
	string name, id;
	char sex;
	int grade;
	People female, male;
	female.grade = -1;
	male.grade = 101;
	for (int i = 0; i < N; ++i)
	{
		//名字，性别，id，成绩
		cin>>name>>sex>>id>>grade;
		if (sex == 'F')
		{
			if (female.grade < grade)
			{
				female.grade = grade;
				female.id = id;
				female.name = name;
			}
		}
		else
		{
			if (male.grade > grade)
			{
				male.grade = grade;
				male.id = id;
				male.name = name;
			}
		}
	}
	if (female.grade == -1)
		printf("Absent\n");
	else
		cout<<female.name<<" "<<female.id<<endl;
	if (male.grade == 101)
		printf("Absent\n");
	else
		cout<<male.name<<" "<<male.id<<endl;
	if (female.grade == -1 || male.grade == 101)
		cout<<"NA"<<endl;
	else
		printf("%d\n", female.grade - male.grade);
	return 0;
}
