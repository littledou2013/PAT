#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int value(string str, int &index, int length)
{
	int sum = 0;
	while(index < length && str[index] != '.')
	{
		sum *= 10;
		sum += str[index] - '0';
		++index;
	}
	++index;
	return sum;
}

void getValue(string str, int &a, int &b, int &c)
{
	int index = 0;
	int size = str.size();
	a = value(str,index,size);
	b = value(str,index, size);
	c = value(str,index, size);
}


int main(void)
{
	string str1, str2;
	cin>>str1>>str2;
	int a1,b1,c1,a2,b2,c2;
	getValue(str1,a1,b1,c1);
	getValue(str2,a2,b2,c2);
	a1 += a2;
	b1 += b2;
	c1 += c2;
	int div = c1 / 29;
	c1 %= 29;
	b1 += div;
	div = b1 / 17;
	b1 %= 17;
	a1 += div;
	printf("%d.%d.%d\n", a1, b1, c1);
	system("pause");
	return 0;
}
