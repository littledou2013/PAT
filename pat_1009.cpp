#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
	求多项式的积
*/
struct Poly
{
	int exp;
	double coe;
	bool operator < (const Poly & poly) const
	{
		return exp > poly.exp;
	}
};
Poly poly1[10];
Poly poly2[10];
Poly poly3[100];
int main(void)
{
	int K1, K2;
	scanf("%d", &K1);
	for (int i = 0; i < K1; ++i)
	{
		scanf("%d%lf", &poly1[i].exp, &poly1[i].coe);
	}
	scanf("%d", &K2);
	for (int i = 0; i < K2; ++i)
	{
		scanf("%d%lf", &poly2[i].exp, &poly2[i].coe);
	}
	int index = 0;
	for (int i = 0; i < K1; ++i)
	{
		for (int j = 0; j < K2; ++j)
		{
			poly3[index].coe = poly1[i].coe * poly2[j].coe;
			poly3[index].exp = poly1[i].exp + poly2[j].exp;
			++index;
		}
	}
	sort(poly3, poly3+index);
	int count = 0, last = 0;
	//把相同的项合并,注意那些不要的项，必须要把其coe置为0
	for (int i = 1; i < index; ++i)
	{
		if (poly3[i].exp == poly3[last].exp)
		{
			poly3[last].coe = poly3[i].coe + poly3[last].coe;
			poly3[i].coe = 0;
		}
		else
		{
			//对不为0的count加1
			if (poly3[last].coe != 0)
				++count;
			last = i;
		}
	}
	if (poly3[last].coe != 0)
		++count;
	printf("%d", count);
	for (int i = 0; i < index; ++i)
	{
		if (poly3[i].coe != 0)
			printf(" %d %.01lf", poly3[i].exp, poly3[i].coe);
	}
	printf("\n");
	return 0;

}
