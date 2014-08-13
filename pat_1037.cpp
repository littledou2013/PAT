#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 100000

int coupon[SIZE];
int value[SIZE];

int main(void)
{
	int NC,NP;
	scanf("%d", &NC);
	for (int i = 0; i < NC; ++i)
	{
		scanf("%d",&coupon[i]);
	}
	sort(coupon,coupon+NC);
	scanf("%d", &NP);
	for (int i = 0; i < NP; ++i)
	{
		scanf("%d", &value[i]);
	}
	sort(value, value+NP);
	int index = 0;
	int result = 0;
	while(index < NC && index < NP && coupon[index] < 0 && value[index] < 0)
	{
		result += coupon[index] * value[index];
		++index;
	}
	--NC;
	--NP;
	while(NC >= 0 && NP >= 0 && coupon[NC] > 0 && value[NP] > 0)
	{
		result += coupon[NC] * value[NP];
		--NC;
		--NP;
	}
	printf("%d\n", result);
	return 0;
}
