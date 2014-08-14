#include <iostream>
#include <cstdio>
using namespace std;
/*
	两个多项式相加
*/
struct Number
{
	int exp;
	float coe;
};
Number num1[12];
Number num2[12];
Number num3[24];
int main(void)
{
	int n1, n2;
	scanf("%d", &n1);
	for (int i = 0; i < n1; ++i)
		scanf("%d%f", &num1[i].exp, &num1[i].coe);
	scanf("%d", &n2);
	for (int i = 0; i < n2; ++i)
		scanf("%d%f", &num2[i].exp, &num2[i].coe);
	int count = 0;
	int i = 0;
	int j = 0;
	float coefficients;
	int exponent;
	while(i < n1 && j < n2)
	{
		if (num1[i].exp == num2[j].exp)
		{
			coefficients = num1[i].coe + num2[j].coe;
			exponent = num1[i].exp;
			++i;
			++j;
		}
		else if (num1[i].exp > num2[j].exp)
		{
			coefficients = num1[i].coe;
			exponent = num1[i].exp;
			++i;
		}
		else
		{
			coefficients = num2[j].coe;
			exponent = num2[j].exp;
			++j;
			
		}
		if (coefficients != 0)
		{
			num3[count].exp = exponent;
			num3[count].coe = coefficients;
			++count;
		}
	}
	while(i < n1)
	{
		coefficients = num1[i].coe;
		exponent = num1[i].exp;
		++i;
		if (coefficients != 0)
		{
			num3[count].exp = exponent;
			num3[count].coe = coefficients;
			++count;
		}
	}
	while(j < n2)
	{
		coefficients = num2[j].coe;
		exponent = num2[j].exp;
		++j;
		if (coefficients != 0)
		{
			num3[count].exp = exponent;
			num3[count].coe = coefficients;
			++count;
		}
	}
	if (count > 0)
	{
		printf("%d", count);
		for (int i = 0;i < count; ++i)
			printf(" %d %.01f",num3[i].exp, num3[i].coe);
	}
	else
		//多项式是0时直接输出0
		printf("0");
	printf("\n");
	return 0;
}
