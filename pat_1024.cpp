#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char strn[120], strm[120];
char ans[120];
bool isPalindromic()
{
	int length = strlen(strn);
	for (int i = 0; i < length; ++i)
		strm[i] = strn[length - i - 1];
	strm[length] = '\0';
	if (strcmp(strn, strm) == 0)
		return true;
	else 
		return false;
}

void getAns()
{
	int index = 0, remain = 0;
	int length = strlen(strn);
	int result;
	for (int i = length - 1; i >= 0; --i)
	{
		result = strn[i] - '0' + strm[i] - '0' + remain;
		ans[index] = result % 10 + '0';
		++index;
		remain = result / 10;
	}
	if (remain > 0)
		ans[index++] = remain + '0';
	for (int i = index - 1; i >= 0; --i)
		strn[index - i - 1] = ans[i];
	strn[index] = '\0';
}
int main(void)
{
	
		scanf("%s", strn);
		int K;
		scanf("%d", &K);
		int index = 0;
		while (index < K)
		{
			if (isPalindromic())
				break;
			getAns();
			++index;
		}
		printf("%s\n", strn);
		printf("%d\n", index);
	return 0;
}
