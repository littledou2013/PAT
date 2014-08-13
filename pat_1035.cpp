#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct User
{
	string user;
	string pwd;
};
User vec[1000];
int main(void)
{
	int N;
	scanf("%d", &N);
	string user, pwd;
	bool needM;
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		cin>>user>>pwd;
		needM = false;
		int length = pwd.size();
		for (int j = 0; j < length; ++j)
		{
			switch(pwd[j])
			{
			case '1':
				pwd[j] = '@'; needM = true; break;
			case '0':
				pwd[j] = '%'; needM = true; break;
			case 'O':
				pwd[j] = 'o'; needM = true; break;
			case 'l':
				pwd[j] = 'L'; needM = true; break;
			}
		}
		if (needM)
		{
			vec[count].user = user;
			vec[count].pwd = pwd;
			++count;
		}
	}
	if (count == 0)
	{
	  if (N == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n", N);
	}
	else
		printf("%d\n", count);
	for (int i = 0; i < count; ++i)
		cout<<vec[i].user<<" "<<vec[i].pwd<<endl;
	return 0;
}
