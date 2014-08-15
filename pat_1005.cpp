#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char digit[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main(void)
{
	char str[101];
	scanf("%s", str);
	int length = strlen(str);
	int sum = 0;
	for (int i = 0; i < length; ++i)
		sum += str[i] - '0';
	int index = 0;
	if (sum == 0)
		str[index++] = '0';
	int div;
	while(sum != 0)
	{
		div = sum % 10;
		sum /= 10;
		str[index++] = div + '0';
	}
	--index;
	printf("%s", digit[str[index] - '0']);
	for (int i = index - 1; i >= 0; --i)
		printf(" %s", digit[str[i] - '0']);
	printf("\n");
	return 0;
}
