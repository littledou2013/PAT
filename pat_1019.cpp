#include <iostream>
#include <cstdio>
using namespace std;

int num[32];
int main(void)
{
	int N, b;
	scanf("%d%d", &N, &b);
	int index = 0;
	if (N == 0)
		num[index] = N;
	while (N != 0)
	{
		num[index++] = N % b;
		N /= b;
	}
	bool is_yes = true;
	for (int i = 0, j = index - 1; i < j; ++i, --j)
	{
		if (num[i] != num[j])
		{
			is_yes = false;
		}
	}
	if (is_yes)
		printf("Yes\n");
	else
		printf("No\n");
	--index;
	printf("%d", num[index--]);
	while (index >= 0)
		printf(" %d", num[index--]);
	printf("\n");

	return 0;
}
