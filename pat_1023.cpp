#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char num1[21];
char num2[21];
char str[21];
bool isSame(char str[])
{
	int index = 0;
	int length = strlen(str);
	int remain = 0;
	int ans;
	for (int i = length - 1; i >= 0; --i)
	{
		ans = (str[i] - '0') * 2;
		num1[index] = ans % 10 + '0' + remain;
		remain = ans / 10;
		num2[index] = num1[index];
		++index;
	}
	if (remain)
	{
		num1[index] = remain + '0';
		num2[index] = num1[index];
		++index;
	}
	num1[index] = '\0';
	num2[index] = num1[index];
	if (index != length)
		return false;
	
	sort(num1, num1 + index);
	sort(str,str + length);
	for (int i = 0;i < length ; ++i)
	{
		if (num1[i] != str[i])
			return false;
	}
	return true;
}


int main(void)
{
	scanf("%s", str);
	if (isSame(str))
		printf("Yes\n");
	else
		printf("No\n");
	for (int i = strlen(num2) - 1; i >= 0; --i)
		printf("%c", num2[i]);
	printf("\n");
	return 0;
}
