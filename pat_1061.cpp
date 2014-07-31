#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char str1[61];
char str2[61];
char str3[61];
char str4[61];

char we[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(void)
{
	scanf("%s%s%s%s", str1, str2, str3, str4);
	int length1 = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
	int length2 = strlen(str3)< strlen(str4) ? strlen(str3) : strlen(str4);
	int index = 0;
	int week, hour, minite;
	for( ; index < length1; ++index)
	{
		//需要判断相同字符是否在A-G之间
		if(str1[index] <= 'G' && str1[index] >= 'A' && str1[index] == str2[index])
			break;
	}
	week = str1[index] - 'A';
	++index;
	for( ; index < length1; ++index)
	{
		if(str1[index] == str2[index])
		{
			//需要判断相同字符是否在A-N之间或为数字
			if(isdigit(str1[index]) || (str1[index] >= 'A' && str2[index] <= 'N'))
				break;
		}
	}
	if (isdigit(str1[index]))
		hour = str1[index] - '0';
	else
		hour = str1[index] - 'A' + 10;
	index = 0;
	while(index < length2)
	{
		//判断相同字符是否为英文字符
		if (isalpha(str3[index]) && str3[index] == str4[index])
			break;
		++index;
	}
	minite = index;
	printf("%s %02d:%02d\n", we[week], hour, minite);
	return 0;
}
