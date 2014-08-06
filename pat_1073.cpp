#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string str;
int main(void)
{
	cin>>str;
	int length = str.size();
	//首先判断整数部分是否为正
	int is_positive;
	if (str[0] == '+')
		is_positive = true;
	else 
		is_positive = false;
	//记录中间数字的开头和结尾位置
	int begin, end;
	int index = 4;
	//找到E标记
	while(str[index] != 'E')
		++index;
	end = index - 1;
	++index;
	//
	int ex_positive;
	if (str[index] == '+')
		ex_positive = true;
	else 
		ex_positive = false;
	++index;
	//计算量级
	if (!is_positive)
		printf("-");
	int exp = 0;
	while (index < length)
	{
		exp *= 10;
		exp += str[index] - '0';
		++index;
	}
	begin = 2;
	str[2] = str[1];
	if (ex_positive)
	{
		for (int i = 0; i <= exp; ++i)
		{
			if (begin <= end)
				printf("%c", str[begin]);
			else
				printf("0");
			++begin;
		}
		if (begin <= end)
			printf(".");
	}
	else
	{
		printf("0.");
		for (int i = 1; i < exp; ++i)
			printf("0");
		
	}
	while(begin <= end)
	{
		printf("%c", str[begin]);
		++begin;
	}
	return 0;

}
