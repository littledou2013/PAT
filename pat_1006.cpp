#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
  比较简单
*/
struct Sign
{
	char name[16];
	char signIn[10];
	char signOut[10];
};

int main(void)
{
	int M;
	char name[16], signIn[10], signOut[10];
	//开门学生，关门学生，开门时间，关门时间
	char unlockname[16], lockname[16], unlocktime[10], locktime[10];
	scanf("%d", &M);
	scanf("%s%s%s", unlockname, unlocktime, locktime);
	strcpy(lockname, unlockname);
	for (int i = 1; i < M; ++i)
	{
		scanf("%s %s %s", name, signIn, signOut);
		if (strcmp(signIn,unlocktime) < 0)
		{
			strcpy(unlockname, name);
			strcpy(unlocktime, signIn);
		}
		if (strcmp(signOut, locktime) > 0)
		{
			strcpy(lockname, name);
			strcpy(locktime, signOut);
		}
	}
	printf("%s %s\n", unlockname, lockname);
	return 0;
}
