#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int char2int(char ch)
{
	if (ch <= '9' && ch >= '0')
	return ch - '0';
	if (ch <= 'z' && ch >= 'a');
	return ch - 'a' + 10;
}
long long int string2llint(char str[], int radix)
{
	int length = strlen(str);
	long long int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result *= radix;
		result += char2int(str[i]);
	}
	return result;
}

int getRadix(long long int result, char str[])
{
	//寻找可以表示str的最小的radix
	int min_radix = 0;
	int length = strlen(str);
	int val;
	for (int i = 0; i < length; ++i)
	{
		str[i] = char2int(str[i]);
		if (str[i] > min_radix)
			min_radix = str[i];
	}
	++min_radix;
	long long int other;
	if (length == 1)
	{
		if (str[0] == result)
			return min_radix;
		else
			return -1;
	}
	if (length == 2)
	{
		if ((result - str[1]) % str[0] == 0)
			return (result - str[1]) / str[0];
		else
			return -1;
	}
	while(true)
	{
		other = 0;	
		for (int i = 0; i < length; ++i)
		{
			other *= min_radix;
			other += str[i];
		}
		if (other == result)
			break;
		if (other > result)
		{
			min_radix = -1;
			break;
		}
		++min_radix;
	}
	return min_radix;

}
int main(void)
{
	char n1[11], n2[11];
	int tag, radix;
	scanf("%s%s%d%d", &n1, &n2, &tag, &radix);
	int r;
	if (tag == 1)
		r = getRadix(string2llint(n1,radix),n2);
	else
		r = getRadix(string2llint(n2,radix),n1);
	if (r == -1)
		printf("Impossible");
	else
		printf("%d", r);
	printf("\n");
	return 0;

}
