#include <iostream>
#include <cstdio>
using namespace std;
/**
  比较简单
**/
int main(void)
{
	int N;
	scanf("%d", &N);
	int last = 0;
	int all = 0, floor;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &floor);
		if (floor > last)
			all += (floor - last) * 6;
		else
			all += (last - floor) * 4;
		last = floor;
		all += 5;
	}
	printf("%d", all);
	return 0;
}
