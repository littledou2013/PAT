#include <iostream>
#include <cstdio>
using namespace std;
struct Football
{
	 char ch;
	 double price;
}football[3];
int main(void)
{
	double a, b, c;
	for (int i = 0; i < 3 ; ++i)
	{
		scanf("%lf%lf%lf", &a, &b, &c);
		if ( a > b && a > c)
		{
			football[i].ch = 'W';
			football[i].price = a;
		}
		if (b > a && b > c)
		{
			football[i].ch = 'T';
			football[i].price = b;
		}
		if ( c > a && c > b)
		{
			football[i].ch = 'L';
			football[i].price = c;
		}
	}
	printf("%c %c %c %.02lf\n", football[0].ch, football[1].ch, football[2].ch, 2 * (football[0].price * football[1].price * football[2].price * 0.65- 1));
	return 0;
}
