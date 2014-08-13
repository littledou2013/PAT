#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string num[10000];

bool cmp(string str1, string str2)
{
	int index1 = 0, index2 = 0;
	int length1 = str1.size(), length2 = str2.size();
	int length;
	if (length2 > length1)
	{
		length = (length2 - 1)/ length1 * length1 + length1;
	}
	else if (length2 < length1)
	{
		length = (length1 - 1)/ length2 * length2 + length2;
	}
	else
		length = length1;
	bool result = true;
	int count = 0;
	while(count < length)
	{
		if (str1[index1] < str2[index2])
			return true;
		else if (str1[index1] > str2[index2])
			return false;
		else
		{
			++index1;
			++index2;
			if (index1 == length1)
				index1 = 0;
			if (index2 == length2)
				index2 = 0;
			++count;
		}
	}
	return true;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	int count = 0;
	string str;
	for (int i = 0;i < N; ++i)
	{
		cin>>str;
		//整个字符串都是0,这个字符串不需要
		bool is_zero = true;
		for (int j = 0;j < str.size(); ++j)
		{
			if (str[j] != '0')
				is_zero = false;
		}
		if (!is_zero)
		{
			num[count++] = str;
		}
	}
	sort(num, num+count, cmp);
	if (count == 0)
		printf("0");
	else
	{
		int index = 0;
		while(index < num[0].size() && num[0][index] == '0')
				++index;
		while(index < num[0].size())
			printf("%c",num[0][index++]);
		for (index = 1; index < count; ++index)
			cout<<num[index];
	}
	printf("\n");
	return 0;
}
